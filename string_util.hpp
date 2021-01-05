#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <string>



class StringUtil {
 public:
  static bool StartsWith(const std::string& str, const std::string& prefix)
  {
      return str.size() >= prefix.size() && str.compare(0, prefix.size(), prefix) == 0;
  }
  static bool EndsWith(std::string const & value, std::string const & ending)
  {
      if (ending.size() > value.size()) return false;
      return std::equal(ending.rbegin(), ending.rend(), value.rbegin());
  } 

  static bool IsNumber(const std::string& s)
  {
      return !s.empty() && std::find_if(s.begin(), 
              s.end(), [](char c) { return !std::isdigit(c); }) == s.end();
  }

  static bool IsAlpha(const std::string& s)
  {
      return !s.empty() && std::find_if(s.begin(), 
              s.end(), [](char c) { return !std::isalpha(c); }) == s.end();
  }
  static void Trim(
    const std::string& source, 
    std::string& dest, 
    const char * ignore)
  {
    size_t end = source.find_last_not_of(ignore);
    if (end == std::string::npos)
    {
      dest.clear();
      return;
    }
    dest.assign(
      source.begin() + source.find_first_not_of(ignore),
      source.begin() + end + 1);
  
    return;
  }

  static std::string Trim(const std::string& source, const char * ignore)
  {
    std::string tmp;
    Trim(source, tmp, ignore);
    return tmp;
  }

  static void TrimLeft(    
    const std::string& source, 
    std::string& dest, 
    const char * ignore)
  {
    dest.assign(source.begin() + source.find_first_not_of(ignore), 
          source.end());
  }

  static std::string TrimLeft(const std::string& source, const char * ignore)
  {
    std::string tmp;
    TrimLeft(source, tmp, ignore);
    return tmp;
  }

  static void TrimRight(    
    const std::string& source, 
    std::string& dest, 
    const char * ignore)
  {
    size_t end = source.find_last_not_of(ignore);
    if (end == std::string::npos)
    {
      dest.clear();
      return;
    }
    dest.assign(source.begin(), source.begin() + end + 1);
  }

  static std::string TrimRight(const std::string& source, const char * ignore)
  {
    std::string tmp;
    TrimRight(source, tmp, ignore);
    return tmp;
  }

  static void Quote(
    const char * source, 
    const char * left, 
    const char * right, 
    std::string& dest)
  {
    dest.clear();
    dest.append(left)
      .append(source)
      .append(right);
  }

  static std::string Quote(
    const std::string& source,
    const std::string& left = "\"",
    const std::string& right = "\"")
  {
    std::string tmp;
    Quote(source.c_str(), left.c_str(), right.c_str(), tmp);
    return tmp;
  }


  static void split(const std::string& s, const std::string& delim, std::vector<std::string>& ret) {
    ret.clear();
    if (delim.length() == 0) {
      ret.push_back(s);
      return ;
    }
    std::string::size_type last = 0;
    std::string::size_type index = s.find(delim, last);
    while (index != std::string::npos) {
      ret.push_back(s.substr(last, index - last));
      last = index + delim.length();
      index = s.find(delim, last);
    }
    ret.push_back(s.substr(last));
  }

};


