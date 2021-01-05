#pragma once
#include "expression.hpp"
#include "custom_define.h"
#include <iostream>
#include <functional>
#include <memory>


namespace Bool{



struct ExpressionMaker{

  template<template<typename T> class EX, typename DT>
  static Expression* MakeRelationBinaryExpression(ExpressionType et, std::string&& key,  Expression* left, Expression* right){
    return new EX<DT>(et, std::move(key), std::shared_ptr<Expression>{left}, std::shared_ptr<Expression>{right});
  }

  template<typename EX>
  static Expression* MakeLogicBinaryExpression(ExpressionType et, std::string&& key, Expression* left, Expression* right){
    return new EX(et, std::move(key), std::shared_ptr<Expression>{left}, std::shared_ptr<Expression>{right});
  }
  template<typename DT>
  static Expression* MakeConstExpression(const std::string& key, const DT& data){
    return new ConstantExpression<DT>(ExpressionType::Constant, key, data);
  }

  template<typename DT>
  static Expression* MakeConstExpression(std::string&& key, DT&& data){
    return new ConstantExpression<DT>(ExpressionType::Constant, std::move(key), std::forward<DT>(data));
  }
  template<typename DT>
  static Expression* MakeParameterExpression(std::string&& key, typename DataGetterFun<DT>::type&& f){
    return new ParameterExpression<DT>(ExpressionType::Parameter, std::move(key), std::move(f));
  }

  static Expression* MakeParameterExpression(std::string&& key){
    if (key == "src_id"){
      return MakeParameterExpression<std::string>(std::move(key), src_id_getter);
    } else if (key == "media_index"){
      return MakeParameterExpression<int>(std::move(key), media_index_getter);
    } else if (key == "app_version"){
      return MakeParameterExpression<AppVersion>(std::move(key), app_version_getter);
    } else if (key == "random"){
      return MakeParameterExpression<int>(std::move(key), random_getter);
    }
    std::cout<<"invalid parameter expression key found:"<<key<<std::endl;
    return nullptr;
  }



  static Expression* MakeAndAlsoExpression(std::string&& key, Expression* left, Expression* right){
    return MakeLogicBinaryExpression<AndAlsoExpression>(ExpressionType::AndAlso, std::move(key), left, right);
  }
  static Expression* MakeOrElseExpression(std::string&& key, Expression* left, Expression* right){
    return MakeLogicBinaryExpression<OrElseExpression>(ExpressionType::OrElse, std::move(key), left, right);
  }
  static Expression* MakeNotExpression(std::string&& key, Expression* expression){
    return MakeLogicBinaryExpression<OrElseExpression>(ExpressionType::OrElse, std::move(key), expression, expression);
  }


  //关系操作表达式也需要根据变量类型定义
  #define CustomMakeRelationBinaryExpression(EXPRESSION, EXPRESSION_TYPE, KEY, left, right) \
      const std::string& parameter_key = left->GetKey(); \
      const std::string& right_key = right->GetKey(); \
      if (parameter_key == "src_id"){ \
        return MakeRelationBinaryExpression<EXPRESSION, std::string>(EXPRESSION_TYPE, std::move(KEY), left, right); \
      } else if (parameter_key == "media_index"){ \
        return MakeRelationBinaryExpression<EXPRESSION, int>(EXPRESSION_TYPE, std::move(key), left, MakeConstExpression<int>(right_key, atoi(right_key.data()))); \
      } else if (parameter_key == "random"){ \
        return MakeRelationBinaryExpression<EXPRESSION, int>(EXPRESSION_TYPE, std::move(key), left, MakeConstExpression<int>(right_key, atoi(right_key.data()))); \
      } else if (parameter_key == "app_version"){ \
        AppVersion app_version{right_key}; \
        return MakeRelationBinaryExpression<EXPRESSION, AppVersion>(EXPRESSION_TYPE, std::move(KEY), left, MakeConstExpression<AppVersion>(right_key, app_version)); \
      } \
      std::cout<<"invalid parameter expression key found:"<<key<<std::endl; \
      return nullptr; \

  static Expression* MakeEqualExpression(std::string&& key, Expression* left, Expression* right){
    CustomMakeRelationBinaryExpression(EqualExpression, ExpressionType::Equal, key, left, right);
  }
  static Expression* MakeNotEqualExpression(std::string&& key, Expression* left, Expression* right){
    CustomMakeRelationBinaryExpression(NotEqualExpression, ExpressionType::NotEqual, key, left, right);
  }
  static Expression* MakeGreaterThanExpression(std::string&& key, Expression* left, Expression* right){
    CustomMakeRelationBinaryExpression(GreaterThanExpression, ExpressionType::GreaterThan, key, left, right);
  }
  static Expression* MakeGreaterThanOrEqualExpression(std::string&& key, Expression* left, Expression* right){
    CustomMakeRelationBinaryExpression(GreaterThanOrEqualExpression, ExpressionType::GreaterThanOrEqual, key, left, right);
  }
  static Expression* MakeLessThanExpression(std::string&& key, Expression* left, Expression* right){
    CustomMakeRelationBinaryExpression(LessThanExpression, ExpressionType::LessThan, key, left, right);
  }
  static Expression* MakeLessThanOrEqualExpression(std::string&& key, Expression* left, Expression* right){
    CustomMakeRelationBinaryExpression(LessThanOrEqualExpression, ExpressionType::LessThanOrEqual, key, left, right);
  }
};

}

