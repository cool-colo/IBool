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
    ConstantExpression(ExpressionType et, std::string&& k, T&& v):value(std::move(v)), Expression(et, std::move(k)){};
    ConstantExpression(ExpressionType et, const std::string& k, const T& v):value(v), Expression(et, k){};
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
    ParameterExpression(ExpressionType et, std::string&& k, typename DataGetterFun<T>::type&& f):fun(std::move(f)), Expression(et, std::move(k)){ 
    };
    ParameterExpression(ExpressionType et, const std::string& k, const typename DataGetterFun<T>::type& f):fun(f), Expression(et, k){
    };
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
    using UnaryExpression::UnaryExpression;
    bool GetResult(const Context& context){
      return !(expr->GetResult(context));
    }
};


class BinaryExpression : public Expression{
  public:
    BinaryExpression(ExpressionType et, const std::string& key, ExpSharedPtr l, ExpSharedPtr r): left(l), right(r), Expression(et,key){};
    BinaryExpression(ExpressionType et, std::string&& key, ExpSharedPtr l, ExpSharedPtr r): left(l), right(r), Expression(et,std::move(key)){};
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
    using BinaryExpression::BinaryExpression;
    bool GetResult(const Context& context){
      return left->GetResult(context) && right->GetResult(context);
    }
};

class OrElseExpression : public BinaryExpression{
  public:
    using BinaryExpression::BinaryExpression;
    bool GetResult(const Context& context){
      return left->GetResult(context) || right->GetResult(context);
    }
};

template<typename T>
class EqualExpression : public BinaryExpression{
  public:
    using DataType = T;
    using BinaryExpression::BinaryExpression;
    bool GetResult(const Context& context){
      auto p = dynamic_cast<ParameterExpression<T>*>(left.get());
      const T& left_value = left->GetType() == ExpressionType::Constant ? dynamic_cast<ConstantExpression<T>*>(left.get())->GetValue(context) : dynamic_cast<ParameterExpression<T>*>(left.get())->GetValue(context);
      const T& right_value = right->GetType() == ExpressionType::Constant ? dynamic_cast<ConstantExpression<T>*>(right.get())->GetValue(context) : dynamic_cast<ParameterExpression<T>*>(right.get())->GetValue(context);
      return left_value == right_value;
    }
};

template<typename T>
class NotEqualExpression : public BinaryExpression{
  public:
    using DataType = T;
    using BinaryExpression::BinaryExpression;
    bool GetResult(const Context& context){
      const T& left_value = left->GetType() == ExpressionType::Constant ? dynamic_cast<ConstantExpression<T>*>(left.get())->GetValue(context) : dynamic_cast<ParameterExpression<T>*>(left.get())->GetValue(context);
      const T& right_value = right->GetType() == ExpressionType::Constant ? dynamic_cast<ConstantExpression<T>*>(right.get())->GetValue(context) : dynamic_cast<ParameterExpression<T>*>(right.get())->GetValue(context);
      return !(left_value == right_value);
    }
};

template<typename T>
class GreaterThanExpression : public BinaryExpression{
  public:
    using DataType = T;
    using BinaryExpression::BinaryExpression;
    bool GetResult(const Context& context){
      const T& left_value = left->GetType() == ExpressionType::Constant ? dynamic_cast<ConstantExpression<T>*>(left.get())->GetValue(context) : dynamic_cast<ParameterExpression<T>*>(left.get())->GetValue(context);
      const T& right_value = right->GetType() == ExpressionType::Constant ? dynamic_cast<ConstantExpression<T>*>(right.get())->GetValue(context) : dynamic_cast<ParameterExpression<T>*>(right.get())->GetValue(context);
      return left_value > right_value;
    }
};

template<typename T>
class GreaterThanOrEqualExpression : public BinaryExpression{
  public:
    using DataType = T;
    using BinaryExpression::BinaryExpression;
    bool GetResult(const Context& context){
      const T& left_value = left->GetType() == ExpressionType::Constant ? dynamic_cast<ConstantExpression<T>*>(left.get())->GetValue(context) : dynamic_cast<ParameterExpression<T>*>(left.get())->GetValue(context);
      const T& right_value = right->GetType() == ExpressionType::Constant ? dynamic_cast<ConstantExpression<T>*>(right.get())->GetValue(context) : dynamic_cast<ParameterExpression<T>*>(right.get())->GetValue(context);
      return !(left_value < right_value);
    }
};

template<typename T>
class LessThanExpression : public BinaryExpression{
  public:
    using DataType = T;
    using BinaryExpression::BinaryExpression;
    bool GetResult(const Context& context){
      const T& left_value = left->GetType() == ExpressionType::Constant ? dynamic_cast<ConstantExpression<T>*>(left.get())->GetValue(context) : dynamic_cast<ParameterExpression<T>*>(left.get())->GetValue(context);
      const T& right_value = right->GetType() == ExpressionType::Constant ? dynamic_cast<ConstantExpression<T>*>(right.get())->GetValue(context) : dynamic_cast<ParameterExpression<T>*>(right.get())->GetValue(context);
      return left_value < right_value;
    }
};

template<typename T>
class LessThanOrEqualExpression : public BinaryExpression{
  public:
    using DataType = T;
    using BinaryExpression::BinaryExpression;
    bool GetResult(const Context& context){
      const T& left_value = left->GetType() == ExpressionType::Constant ? dynamic_cast<ConstantExpression<T>*>(left.get())->GetValue(context) : dynamic_cast<ParameterExpression<T>*>(left.get())->GetValue(context);
      const T& right_value = right->GetType() == ExpressionType::Constant ? dynamic_cast<ConstantExpression<T>*>(right.get())->GetValue(context) : dynamic_cast<ParameterExpression<T>*>(right.get())->GetValue(context);
      return !(left_value > right_value);
    }
};

template<typename T>
class InExpression : public BinaryExpression{
  public:
    using DataType = T;
    using BinaryExpression::BinaryExpression;
    bool GetResult(const Context& context){
      const T& left_value = dynamic_cast<ParameterExpression<T>*>(left.get())->GetValue(context);
      const std::vector<T>& right_value = dynamic_cast<ConstantExpression<std::vector<T>>*>(right.get())->GetValue(context);
      std::cout<<"in expression get result"<<std::endl;
      for (const auto& value : right_value){
        //std::cout<<"value in array:"<<value<<std::endl;
      }
      return std::any_of(std::begin(right_value), std::end(right_value), [&left_value](const auto& value) { return left_value == value; });
    }
};

template<typename T>
class NotInExpression : public BinaryExpression{
  public:
    using DataType = T;
    using BinaryExpression::BinaryExpression;
    bool GetResult(const Context& context){
      const T& left_value = dynamic_cast<ParameterExpression<T>*>(left.get())->GetValue(context);
      const std::vector<T>& right_value = dynamic_cast<ConstantExpression<std::vector<T>>*>(right.get())->GetValue(context);
      return std::none_of(std::begin(right_value), std::end(right_value), [&left_value](const auto& value) { return left_value == value; });
    }
};

}

