#pragma once
#include "expression.hpp"
#include "string_util.hpp"
#include "custom_define.h"
#include <iostream>
#include <functional>
#include <memory>


namespace Bool{

template<typename T>
struct Conv{
  static T To(std::string&& from){
    return T{std::move(from)};
  }
};
template<>
struct Conv<std::string>{
  static std::string To(std::string&& from){
    return std::move(from);
  }
};
template<>
struct Conv<int>{
  static int To(std::string&& from){
    return atoi(from.data());
  }
};


template<typename T>
T To(std::string&& from){
  return Conv<T>::To(std::move(from));
}

template <typename T, T... S, typename F>
constexpr void for_sequence(std::integer_sequence<T, S...>, F&& f) {
    (void)std::vector<bool>{(static_cast<void>(f(std::integral_constant<T, S>{})), true)...};
}


struct ExpressionMaker{
  template<typename DT>
  static Expression* MakeConstExpression(const std::string& key, const DT& data){
    return new ConstantExpression<DT>(key, data);
  }

  template<typename DT>
  static Expression* MakeConstExpression(std::string&& key, DT&& data){
    return new ConstantExpression<DT>(std::move(key), std::forward<DT>(data));
  }

  template<typename DT, typename Enable = void>
  struct MakeConstExpressionImpl{
    static Expression* MakeConstExpression(std::string&& key, std::string&& value){
      return ExpressionMaker::MakeConstExpression<DT>(std::move(key), To<DT>(std::move(value)));
    }
  };

  template<template<typename> class Container, typename DT>
  struct MakeConstExpressionImpl<Container<DT>, typename std::enable_if<!std::is_same<Container<DT>, std::string>::value>::type>{
    static Expression* MakeConstExpression(std::string&& key, std::string&& value){
      std::string trimed_value = StringUtil::Trim(value, " []");
      std::vector<std::string> values;
      StringUtil::split(trimed_value, ",", values);
      std::transform(values.begin(), values.end(), values.begin(), [](const std::string& value) { return StringUtil::Trim(value, " \""); });
  
      Container<DT> target_values;
      std::transform(values.begin(), values.end(), std::back_inserter(target_values), [](const std::string& value) { return To<DT>(std::string(value)); });
      return ExpressionMaker::MakeConstExpression<Container<DT>>(std::move(key), std::move(target_values));
    }
  };
  

  template<typename DT>
  static Expression* MakeConstExpression(std::string&& key, std::string&& value, bool is_array){
    std::string trimed_value = StringUtil::Trim(value, "\"");
    if (is_array) {
      return MakeConstExpressionImpl<std::vector<DT>>::MakeConstExpression(std::move(key), std::move(trimed_value));
    } else {
      return MakeConstExpressionImpl<DT>::MakeConstExpression(std::move(key), std::move(trimed_value));
    }
    return nullptr;  //never be here
  }

  template<typename DT>
  static Expression* MakeParameterExpression(std::string&& key, const typename DataGetterFun<DT>::type& f){
    return new ParameterExpression<DT>(std::move(key), f);
  }
  template<typename DT>
  static Expression* MakeParameterExpression(const std::string& key, const typename DataGetterFun<DT>::type& f){
    return new ParameterExpression<DT>(key, f);
  }

  template<template<typename T> class EX, typename DT>
  static Expression* MakeRelationBinaryExpression(std::string&& key,  Expression* left, Expression* right){
    return new EX<DT>(std::move(key), std::shared_ptr<Expression>{left}, std::shared_ptr<Expression>{right});
  }

  template<template<typename T> class EX, typename DT>
  static Expression* MakeRelationBinaryExpression(const typename DataGetterFun<DT>::type& f, std::string&& key,  std::string&& left, std::string&& right, bool is_array){
    auto* parameter_expr = MakeParameterExpression<DT>(std::move(left), f);
    auto* const_expr = MakeConstExpression<DT>(std::string(right), std::string(right), is_array);
    return MakeRelationBinaryExpression<EX, DT>(std::move(key), parameter_expr, const_expr);
  }

  template<typename EX>
  static Expression* MakeLogicBinaryExpression(std::string&& key, Expression* left, Expression* right){
    return new EX(std::move(key), std::shared_ptr<Expression>{left}, std::shared_ptr<Expression>{right});
  }

  template<typename EX>
  static Expression* MakeUnaryExpression(std::string&& key, Expression* expr){
    return new EX(std::move(key), std::shared_ptr<Expression>{expr});
  }

  

  static Expression* MakeAndAlsoExpression(std::string&& key, Expression* left, Expression* right){
    return MakeLogicBinaryExpression<AndAlsoExpression>(std::move(key), left, right);
  }
  static Expression* MakeOrElseExpression(std::string&& key, Expression* left, Expression* right){
    return MakeLogicBinaryExpression<OrElseExpression>(std::move(key), left, right);
  }
  static Expression* MakeNotExpression(std::string&& key, Expression* expr){
    return MakeUnaryExpression<NotExpression>(std::move(key), expr);
  }

  template<template<typename> class EX>
  static Expression* MakeRelationBinaryExpression(std::string&& key,  std::string&& left, std::string&& right, bool is_array){

    Expression* res = nullptr;
    constexpr auto nbProperties = std::tuple_size<decltype(ParameterDefine::PARAMETERS)>::value;
    for_sequence(std::make_index_sequence<nbProperties>{}, [&](auto i) {
      constexpr auto property = std::get<i>(ParameterDefine::PARAMETERS);
      using Type = typename decltype(property)::Type;
      if (left == property.name_ && res == nullptr){
        res = ExpressionMaker::MakeRelationBinaryExpression<EX, Type>(*(property.fun_), std::move(key), std::move(left), std::move(right), is_array);
      }
    });
    if (res == nullptr){
      std::cout<<"invalid parameter expression key found:"<<key<<std::endl;
    }
    return res; 
  }

  static Expression* MakeEqualExpression(std::string&& key, std::string&& left, std::string&& right){
    return MakeRelationBinaryExpression<EqualExpression>(std::move(key), std::move(left), std::move(right), false);
  }
  static Expression* MakeNotEqualExpression(std::string&& key, std::string&& left, std::string&& right){
    return MakeRelationBinaryExpression<NotEqualExpression>(std::move(key), std::move(left), std::move(right), false);
  }
  static Expression* MakeGreaterThanExpression(std::string&& key, std::string&& left, std::string&& right){
    return MakeRelationBinaryExpression<GreaterThanExpression>(std::move(key), std::move(left), std::move(right), false);
  }
  static Expression* MakeGreaterThanOrEqualExpression(std::string&& key, std::string&& left, std::string&& right){
    return MakeRelationBinaryExpression<GreaterThanOrEqualExpression>(std::move(key), std::move(left), std::move(right), false);
  }
  static Expression* MakeLessThanExpression(std::string&& key, std::string&& left, std::string&& right){
    return MakeRelationBinaryExpression<LessThanExpression>(std::move(key), std::move(left), std::move(right), false);
  }
  static Expression* MakeLessThanOrEqualExpression(std::string&& key, std::string&& left, std::string&& right){
    return MakeRelationBinaryExpression<LessThanOrEqualExpression>(std::move(key), std::move(left), std::move(right), false);
  }
  static Expression* MakeInExpression(std::string&& key, std::string&& left, std::string&& right){
    return MakeRelationBinaryExpression<InExpression>(std::move(key), std::move(left), std::move(right), true);
  }
  static Expression* MakeNotInExpression(std::string&& key, std::string&& left, std::string&& right){
    return MakeRelationBinaryExpression<NotInExpression>(std::move(key), std::move(left), std::move(right), true);
  }
};

}

