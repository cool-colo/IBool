#pragma once
#include "expression.hpp"
#include "string_util.hpp"
#include <iostream>
#include <unordered_set>
#include <set>
#include <list>
#include <vector>
#include <tuple>

//自定义类型需要实现:
//1 .std::string&&为参数的构造函数
//2 .operator >
//3 .operator <
//4. operator ==
struct AppVersion{
  AppVersion(std::string&& ver){
    std::vector<std::string> tokens;
    StringUtil::split(ver, ".", tokens);
    major = atoi(tokens[0].data());
    minor = atoi(tokens[1].data());
    //TODO
  }
  AppVersion(){
    //TODO
  }
  int major = 0;
  int minor = 0;
  bool operator > (const AppVersion& rth) const{
    if (major > rth.major){
      return true;
    }
    if (major < rth.major){
      return false;
    }
    if (minor > rth.minor){
      return true;
    }
    if (minor < rth.minor){
      return false;
    }
    return false;
  }
  bool operator < (const AppVersion& rth) const{
    if (major < rth.major){
      return true;
    }
    if (major > rth.major){
      return false;
    }
    if (minor < rth.major){
      return true;
    }
    if (minor > rth.major){
      return false;
    }
    return false;
  }

  bool operator == (const AppVersion& rth) const{
    return major == rth.major && minor == rth.minor;
  }
  
};




//需要使用方按需提供
struct CustomContext : public Bool::Context{
  std::string src_id;
  int media_index;
  int random;
  std::vector<std::string> tags;
  std::unordered_set<int> loc_codes;
  std::set<int, std::greater<int>> levels;
  std::string taichi;
  AppVersion app_version;
  virtual ~CustomContext(){
  }
};


namespace Bool {

//需要支持的动态参数获取值的方法，在这里填加
static const typename DataGetterFun<AppVersion>::type app_version_getter = [](const Bool::Context& context)->const AppVersion&{ 
    const auto& custom_context = dynamic_cast<const CustomContext&>(context);
    return custom_context.app_version;
  };
static const typename DataGetterFun<int>::type media_index_getter = [](const Bool::Context& context)->const int&{ 
    const auto& custom_context = dynamic_cast<const CustomContext&>(context);
    return custom_context.media_index;
  };

static const typename DataGetterFun<std::string>::type src_id_getter = [](const Bool::Context& context)->const std::string&{ 
    const auto& custom_context = dynamic_cast<const CustomContext&>(context);
    return custom_context.src_id;
  };

static const typename DataGetterFun<std::string>::type taichi_getter = [](const Bool::Context& context)->const std::string&{ 
    const auto& custom_context = dynamic_cast<const CustomContext&>(context);
    return custom_context.taichi;
  };

static const typename DataGetterFun<int>::type random_getter = [](const Bool::Context& context)-> const int&{ 
    const auto& custom_context = dynamic_cast<const CustomContext&>(context);
    return custom_context.random;
  };

static const typename DataGetterFun<std::vector<std::string>>::type tags_getter = [](const Bool::Context& context)-> const std::vector<std::string>&{ 
    const auto& custom_context = dynamic_cast<const CustomContext&>(context);
    return custom_context.tags;
  };

static const typename DataGetterFun<std::unordered_set<int>>::type loc_codes_getter = [](const Bool::Context& context)-> const std::unordered_set<int>&{ 
    const auto& custom_context = dynamic_cast<const CustomContext&>(context);
    return custom_context.loc_codes;
  };

static const typename DataGetterFun<std::set<int, std::greater<int>>>::type levels_getter = [](const Bool::Context& context)-> const std::set<int, std::greater<int>>&{ 
    const auto& custom_context = dynamic_cast<const CustomContext&>(context);
    return custom_context.levels;
  };



template<typename T>
struct PropertyImpl{
    constexpr PropertyImpl(const char* name, const typename DataGetterFun<T>::type* fun):fun_(fun), name_(name){
    }
    using Type = T;
    const typename DataGetterFun<T>::type* fun_;
    const char* name_;
};


template<typename T>
constexpr auto property(const char* name, const typename DataGetterFun<T>::type* fun){
    return PropertyImpl<T>(name, fun);
}

template< class T >
struct remove_cvref {
    using type = typename std::remove_cv<std::remove_reference_t<T>>::type;
};

#define PROPERTY(NAME,FUN) property<remove_cvref<std::result_of<decltype(FUN)(const Bool::Context&)>::type>::type>(#NAME, &FUN)

//需要支持的动态参数在这里填加
struct ParameterDefine{
  constexpr static auto PARAMETERS = 
    std::make_tuple(
      PROPERTY(src_id, src_id_getter),
      PROPERTY(app_version, app_version_getter),
      PROPERTY(media_index, media_index_getter ),
      PROPERTY(tags, tags_getter ),
      PROPERTY(loc_codes, loc_codes_getter ),
      PROPERTY(levels, levels_getter ),
      PROPERTY(taichi, taichi_getter ),
      PROPERTY(random, random_getter )
    );
};

}


