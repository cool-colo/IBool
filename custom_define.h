#pragma once
#include "expression.hpp"
#include "string_util.hpp"
#include <iostream>



struct AppVersion{
  AppVersion(const std::string& ver){
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
  AppVersion app_version;
  virtual ~CustomContext(){
  }
};


//需要使用方按需提供
static const auto app_version_getter = [](const Bool::Context& context)->const AppVersion&{ 
    const auto& custom_context = dynamic_cast<const CustomContext&>(context);
    return custom_context.app_version;
  };
static const auto media_index_getter = [](const Bool::Context& context)->const int&{ 
    const auto& custom_context = dynamic_cast<const CustomContext&>(context);
    return custom_context.media_index;
  };
static const auto src_id_getter = [](const Bool::Context& context)->const std::string&{ 
    const auto& custom_context = dynamic_cast<const CustomContext&>(context);
    return custom_context.src_id;
  };

static const auto random_getter = [](const Bool::Context& context)-> const int&{ 
    const auto& custom_context = dynamic_cast<const CustomContext&>(context);
    return custom_context.random;
  };




