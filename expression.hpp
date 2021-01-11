#pragma once
#include <iostream>
#include <functional>
#include <memory>


namespace Bool{

enum ExpressionType{
  Constant,
  Parameter,


  AndAlso,
  OrElse,
  Not,

  Equal,  
  NotEqual,
  GreaterThan,
  GreaterThanOrEqual,
  LessThan,
  LessThanOrEqual,
  In,
  NotIn,
  Contains,
};

struct Context{
  virtual ~Context(){
  }
};



template<typename T>
struct DataGetterFun{
  using type = std::function<const T&(const Context& context)>; 
};

class Expression{
  public:
    ExpressionType expression_type;
    std::string key;
  public:
    using ExpSharedPtr = std::shared_ptr<Expression>;
    Expression(){};
    Expression(ExpressionType et):expression_type(et){};
    Expression(ExpressionType et, std::string&& k):expression_type(et), key(std::move(k)){};
    Expression(ExpressionType et, const std::string& k):expression_type(et), key(k){};
  public:
    ExpressionType GetType() { return expression_type; }
    const std::string GetKey() { return key; }
    virtual bool GetResult(const Context& context){ return true; }
    virtual std::string Print() = 0;
};


template<typename T>
class ConstantExpression : public Expression{
  public:
    ConstantExpression(std::string&& k, T&& v):value(std::move(v)), Expression(ExpressionType::Constant, std::move(k)){};
    ConstantExpression(const std::string& k, const T& v):value(v), Expression(ExpressionType::Constant, k){};
    const T& GetValue(const Context& context){ 
      return value; 
    }
    std::string Print() override {
      return GetKey();
    }
  protected:
    T value;
};



template<typename T>
class ParameterExpression : public Expression{
  public:
    ParameterExpression(std::string&& k, const typename DataGetterFun<T>::type& f):fun(f), Expression(ExpressionType::Parameter, std::move(k)){ };
    ParameterExpression(const std::string& k, const typename DataGetterFun<T>::type& f):fun(f), Expression(ExpressionType::Parameter, k){ };
    const T& GetValue(const Context& context){ 
      return fun(context);
    }
    std::string Print() override {
      return GetKey();
    }
  protected:
    typename DataGetterFun<T>::type fun;
};

class UnaryExpression : public Expression{
  public:
    UnaryExpression(ExpressionType et, const std::string& key, ExpSharedPtr e): expr(e), Expression(et,key){};
    UnaryExpression(ExpressionType et, std::string&& key, ExpSharedPtr e): expr(e), Expression(et,std::move(key)){};
    bool GetResult(const Context& context){
    }
    std::string Print() override {
      return GetKey() + expr->Print();
    }
  protected:
    ExpSharedPtr expr;
};

class NotExpression : public UnaryExpression{
  public:
    NotExpression(const std::string& key, ExpSharedPtr e): UnaryExpression(ExpressionType::Not, key, e){};
    NotExpression(std::string&& key, ExpSharedPtr e): UnaryExpression(ExpressionType::Not, std::move(key), e){};
    bool GetResult(const Context& context){
      return !(expr->GetResult(context));
    }
};


class BinaryExpression : public Expression{
  public:
    BinaryExpression(ExpressionType et, std::string&& key, ExpSharedPtr l, ExpSharedPtr r): left(l), right(r), Expression(et,std::move(key)){};
    BinaryExpression(ExpressionType et, const std::string& key, ExpSharedPtr l, ExpSharedPtr r){ BinaryExpression(et, std::string(key), l, r); }
    bool GetResult(const Context& context){
    }
    std::string Print() override {
      return "(" + left->Print() + " " + GetKey() + " " + right->Print() + ")";
    }
  protected:
    ExpSharedPtr left;
    ExpSharedPtr right;
};

class AndAlsoExpression : public BinaryExpression{
  public:
    AndAlsoExpression(std::string&& key, ExpSharedPtr l, ExpSharedPtr r): BinaryExpression(ExpressionType::AndAlso, std::move(key), l, r){};
    AndAlsoExpression(const std::string& key, ExpSharedPtr l, ExpSharedPtr r): BinaryExpression(ExpressionType::AndAlso, key, l, r){};
    bool GetResult(const Context& context){
      return left->GetResult(context) && right->GetResult(context);
    }
};

class OrElseExpression : public BinaryExpression{
  public:
    OrElseExpression(std::string&& key, ExpSharedPtr l, ExpSharedPtr r): BinaryExpression(ExpressionType::OrElse, std::move(key), l, r){};
    OrElseExpression(const std::string& key, ExpSharedPtr l, ExpSharedPtr r): BinaryExpression(ExpressionType::OrElse, key, l, r){};
    bool GetResult(const Context& context){
      return left->GetResult(context) || right->GetResult(context);
    }
};

template<typename T, typename Enable = void>
class EqualExpression : public BinaryExpression{
  public:
    using DataType = T;
    EqualExpression(std::string&& key, ExpSharedPtr l, ExpSharedPtr r): BinaryExpression(ExpressionType::Equal, std::move(key), l, r){};
    EqualExpression(const std::string& key, ExpSharedPtr l, ExpSharedPtr r): BinaryExpression(ExpressionType::Equal, key, l, r){};
    bool GetResult(const Context& context){
      const T& left_value = dynamic_cast<ParameterExpression<T>*>(left.get())->GetValue(context);
      const T& right_value = dynamic_cast<ConstantExpression<T>*>(right.get())->GetValue(context);
      return left_value == right_value;
    }
};

template<typename T, typename ... ARGS, template<typename ...> class Container>
class EqualExpression<Container<T, ARGS...>, typename std::enable_if<!std::is_same<Container<T>, std::string>::value>::type>  : public BinaryExpression{
  public:
    using DataType = Container<T, ARGS...>;
    EqualExpression(std::string&& key, ExpSharedPtr l, ExpSharedPtr r): BinaryExpression(ExpressionType::Equal, std::move(key), l, r){};
    EqualExpression(const std::string& key, ExpSharedPtr l, ExpSharedPtr r): BinaryExpression(ExpressionType::Equal, key, l, r){};
    bool GetResult(const Context& context){
      return false;
    }
};

template<typename T, typename Enable = void>
class NotEqualExpression : public BinaryExpression{
  public:
    using DataType = T;
    NotEqualExpression(std::string&& key, ExpSharedPtr l, ExpSharedPtr r): BinaryExpression(ExpressionType::NotEqual, std::move(key), l, r){};
    NotEqualExpression(const std::string& key, ExpSharedPtr l, ExpSharedPtr r): BinaryExpression(ExpressionType::NotEqual, key, l, r){};
    bool GetResult(const Context& context){
      const T& left_value = dynamic_cast<ParameterExpression<T>*>(left.get())->GetValue(context);
      const T& right_value = dynamic_cast<ConstantExpression<T>*>(right.get())->GetValue(context);
      return !(left_value == right_value);
    }
};

template<typename T, typename ... ARGS, template<typename ...> class Container>
class NotEqualExpression<Container<T, ARGS...>, typename std::enable_if<!std::is_same<Container<T>, std::string>::value>::type>  : public BinaryExpression{
  public:
    using DataType = Container<T, ARGS...>;
    NotEqualExpression(std::string&& key, ExpSharedPtr l, ExpSharedPtr r): BinaryExpression(ExpressionType::NotEqual, std::move(key), l, r){};
    NotEqualExpression(const std::string& key, ExpSharedPtr l, ExpSharedPtr r): BinaryExpression(ExpressionType::NotEqual, key, l, r){};
    bool GetResult(const Context& context){
      return false;
    }
};

template<typename T, typename Enable = void>
class GreaterThanExpression : public BinaryExpression{
  public:
    using DataType = T;
    GreaterThanExpression(std::string&& key, ExpSharedPtr l, ExpSharedPtr r): BinaryExpression(ExpressionType::GreaterThan, std::move(key), l, r){};
    GreaterThanExpression(const std::string& key, ExpSharedPtr l, ExpSharedPtr r): BinaryExpression(ExpressionType::GreaterThan, key, l, r){};
    bool GetResult(const Context& context){
      const T& left_value = dynamic_cast<ParameterExpression<T>*>(left.get())->GetValue(context);
      const T& right_value = dynamic_cast<ConstantExpression<T>*>(right.get())->GetValue(context);
      return left_value > right_value;
    }
};

template<typename T, typename ... ARGS, template<typename ...> class Container>
class GreaterThanExpression<Container<T, ARGS...>, typename std::enable_if<!std::is_same<Container<T>, std::string>::value>::type>  : public BinaryExpression{
  public:
    using DataType = Container<T, ARGS...>;
    GreaterThanExpression(std::string&& key, ExpSharedPtr l, ExpSharedPtr r): BinaryExpression(ExpressionType::GreaterThan, std::move(key), l, r){};
    GreaterThanExpression(const std::string& key, ExpSharedPtr l, ExpSharedPtr r): BinaryExpression(ExpressionType::GreaterThan, key, l, r){};
    bool GetResult(const Context& context){
      return false;
    }
};

template<typename T, typename Enable = void>
class GreaterThanOrEqualExpression : public BinaryExpression{
  public:
    using DataType = T;
    GreaterThanOrEqualExpression(std::string&& key, ExpSharedPtr l, ExpSharedPtr r): BinaryExpression(ExpressionType::GreaterThanOrEqual, std::move(key), l, r){};
    GreaterThanOrEqualExpression(const std::string& key, ExpSharedPtr l, ExpSharedPtr r): BinaryExpression(ExpressionType::GreaterThanOrEqual, key, l, r){};
    bool GetResult(const Context& context){
      const T& left_value = dynamic_cast<ParameterExpression<T>*>(left.get())->GetValue(context);
      const T& right_value = dynamic_cast<ConstantExpression<T>*>(right.get())->GetValue(context);
      return !(left_value < right_value);
    }
};

template<typename T, typename ... ARGS, template<typename ...> class Container>
class GreaterThanOrEqualExpression<Container<T, ARGS...>, typename std::enable_if<!std::is_same<Container<T>, std::string>::value>::type>  : public BinaryExpression{
  public:
    using DataType = Container<T, ARGS...>;
    GreaterThanOrEqualExpression(std::string&& key, ExpSharedPtr l, ExpSharedPtr r): BinaryExpression(ExpressionType::GreaterThanOrEqual, std::move(key), l, r){};
    GreaterThanOrEqualExpression(const std::string& key, ExpSharedPtr l, ExpSharedPtr r): BinaryExpression(ExpressionType::GreaterThanOrEqual, key, l, r){};
    bool GetResult(const Context& context){
      return false;
    }
};

template<typename T, typename Enable = void>
class LessThanExpression : public BinaryExpression{
  public:
    using DataType = T;
    LessThanExpression(std::string&& key, ExpSharedPtr l, ExpSharedPtr r): BinaryExpression(ExpressionType::LessThan, std::move(key), l, r){};
    LessThanExpression(const std::string& key, ExpSharedPtr l, ExpSharedPtr r): BinaryExpression(ExpressionType::LessThan, key, l, r){};
    bool GetResult(const Context& context){
      const T& left_value = dynamic_cast<ParameterExpression<T>*>(left.get())->GetValue(context);
      const T& right_value = dynamic_cast<ConstantExpression<T>*>(right.get())->GetValue(context);
      return left_value < right_value;
    }
};

template<typename T, typename ... ARGS, template<typename ...> class Container>
class LessThanExpression<Container<T, ARGS...>, typename std::enable_if<!std::is_same<Container<T>, std::string>::value>::type>  : public BinaryExpression{
  public:
    using DataType = Container<T, ARGS...>;
    LessThanExpression(std::string&& key, ExpSharedPtr l, ExpSharedPtr r): BinaryExpression(ExpressionType::LessThan, std::move(key), l, r){};
    LessThanExpression(const std::string& key, ExpSharedPtr l, ExpSharedPtr r): BinaryExpression(ExpressionType::LessThan, key, l, r){};
    bool GetResult(const Context& context){
      return false;
    }
};

template<typename T, typename Enable = void>
class LessThanOrEqualExpression : public BinaryExpression{
  public:
    using DataType = T;
    LessThanOrEqualExpression(std::string&& key, ExpSharedPtr l, ExpSharedPtr r): BinaryExpression(ExpressionType::LessThanOrEqual, std::move(key), l, r){};
    LessThanOrEqualExpression(const std::string& key, ExpSharedPtr l, ExpSharedPtr r): BinaryExpression(ExpressionType::LessThanOrEqual, key, l, r){};
    bool GetResult(const Context& context){
      const T& left_value = dynamic_cast<ParameterExpression<T>*>(left.get())->GetValue(context);
      const T& right_value = dynamic_cast<ConstantExpression<T>*>(right.get())->GetValue(context);
      return !(left_value > right_value);
    }
};

template<typename T, typename ... ARGS, template<typename ...> class Container>
class LessThanOrEqualExpression<Container<T, ARGS...>, typename std::enable_if<!std::is_same<Container<T>, std::string>::value>::type>  : public BinaryExpression{
  public:
    using DataType = Container<T, ARGS...>;
    LessThanOrEqualExpression(std::string&& key, ExpSharedPtr l, ExpSharedPtr r): BinaryExpression(ExpressionType::LessThanOrEqual, std::move(key), l, r){};
    LessThanOrEqualExpression(const std::string& key, ExpSharedPtr l, ExpSharedPtr r): BinaryExpression(ExpressionType::LessThanOrEqual, key, l, r){};
    bool GetResult(const Context& context){
      return false;
    }
};

template<typename T, typename Enable = void>
class InExpression : public BinaryExpression{
  public:
    using DataType = T;
    InExpression(std::string&& key, ExpSharedPtr l, ExpSharedPtr r): BinaryExpression(ExpressionType::In, std::move(key), l, r){};
    InExpression(const std::string& key, ExpSharedPtr l, ExpSharedPtr r): BinaryExpression(ExpressionType::In, key, l, r){};
    bool GetResult(const Context& context){
      const T& left_value = dynamic_cast<ParameterExpression<T>*>(left.get())->GetValue(context);
      const std::vector<T>& right_value = dynamic_cast<ConstantExpression<std::vector<T>>*>(right.get())->GetValue(context);
      return std::any_of(std::begin(right_value), std::end(right_value), [&left_value](const auto& value) { return left_value == value; });
    }
};

template<typename T, typename ... ARGS, template<typename ...> class Container>
class InExpression<Container<T, ARGS...>, typename std::enable_if<!std::is_same<Container<T>, std::string>::value>::type>  : public BinaryExpression{
  public:
    using DataType = Container<T, ARGS...>;
    InExpression(std::string&& key, ExpSharedPtr l, ExpSharedPtr r): BinaryExpression(ExpressionType::In, std::move(key), l, r){};
    InExpression(const std::string& key, ExpSharedPtr l, ExpSharedPtr r): BinaryExpression(ExpressionType::In, key, l, r){};
    bool GetResult(const Context& context){
      return false;
    }
};

template<typename T, typename Enable = void>
class NotInExpression : public BinaryExpression{
  public:
    using DataType = T;
    NotInExpression(std::string&& key, ExpSharedPtr l, ExpSharedPtr r): BinaryExpression(ExpressionType::NotIn, std::move(key), l, r){};
    NotInExpression(const std::string& key, ExpSharedPtr l, ExpSharedPtr r): BinaryExpression(ExpressionType::NotIn, key, l, r){};
    bool GetResult(const Context& context){
      const T& left_value = dynamic_cast<ParameterExpression<T>*>(left.get())->GetValue(context);
      const std::vector<T>& right_value = dynamic_cast<ConstantExpression<std::vector<T>>*>(right.get())->GetValue(context);
      return std::none_of(std::begin(right_value), std::end(right_value), [&left_value](const auto& value) { return left_value == value; });
    }
};

template<typename T, typename ... ARGS, template<typename ...> class Container>
class NotInExpression<Container<T, ARGS...>, typename std::enable_if<!std::is_same<Container<T>, std::string>::value>::type>  : public BinaryExpression{
  public:
    using DataType = Container<T, ARGS...>;
    NotInExpression(std::string&& key, ExpSharedPtr l, ExpSharedPtr r): BinaryExpression(ExpressionType::NotIn, std::move(key), l, r){};
    NotInExpression(const std::string& key, ExpSharedPtr l, ExpSharedPtr r): BinaryExpression(ExpressionType::NotIn, key, l, r){};
    bool GetResult(const Context& context){
      return false;
    }
};

template<typename T, typename Enable = void>
class ContainsExpression : public BinaryExpression{
  public:
    using DataType = T;
    ContainsExpression(std::string&& key, ExpSharedPtr l, ExpSharedPtr r): BinaryExpression(ExpressionType::Contains, std::move(key), l, r){};
    ContainsExpression(const std::string& key, ExpSharedPtr l, ExpSharedPtr r): BinaryExpression(ExpressionType::Contains, key, l, r){};
    bool GetResult(const Context& context){
      return false;
    }
};

template<typename T, typename ... ARGS, template<typename ...> class Container>
class ContainsExpression<Container<T, ARGS...>> : public BinaryExpression{
  public:
    using DataType = T;
    ContainsExpression(std::string&& key, ExpSharedPtr l, ExpSharedPtr r): BinaryExpression(ExpressionType::Contains, std::move(key), l, r){};
    ContainsExpression(const std::string& key, ExpSharedPtr l, ExpSharedPtr r): BinaryExpression(ExpressionType::Contains, key, l, r){};
    bool GetResult(const Context& context){
      const Container<T, ARGS...>& left_value = dynamic_cast<ParameterExpression<Container<T, ARGS...>>*>(left.get())->GetValue(context);
      const T& right_value = dynamic_cast<ConstantExpression<T>*>(right.get())->GetValue(context);
      return std::any_of(std::begin(left_value), std::end(left_value), [&right_value](const auto& value) { return right_value == value; });
    }
};

template<>
class ContainsExpression<std::string> : public BinaryExpression{
  public:
    using DataType = std::string;
    ContainsExpression(std::string&& key, ExpSharedPtr l, ExpSharedPtr r): BinaryExpression(ExpressionType::Contains, std::move(key), l, r){};
    ContainsExpression(const std::string& key, ExpSharedPtr l, ExpSharedPtr r): BinaryExpression(ExpressionType::Contains, key, l, r){};
    bool GetResult(const Context& context){
      const std::string& left_value = dynamic_cast<ParameterExpression<std::string>*>(left.get())->GetValue(context);
      const std::string& right_value = dynamic_cast<ConstantExpression<std::string>*>(right.get())->GetValue(context);
      return left_value.find(right_value) != std::string::npos;
    }
};

}

