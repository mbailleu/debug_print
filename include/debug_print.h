#pragma once

#if !defined(NDEBUG)
#define IF_RELEASE(x) x
#define IF_DEBUG(x) 

#include <iostream>

namespace {
template<class ... Args>
void _debug_print(char const * func, size_t line, Args && ... args) {
  std::cout << "DEBUG: " << func << ':' << line;
  if constexpr (sizeof ...(args) > 0) {
    std::cout << " -> ";
    (std::cout << ... << args);
  }
  std::cout << '\n';
}
}

#define debug_print(...) _debug_print(__PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__)

#include <typeinfo>
#include <string>
#include "map.h"

std::string demangle(char const * name);

template<class T>
std::string type(T && t) {
  return demangle(typeid(t).name());
}

#define debug_vars_name(VAR) \
  std::cout << #VAR << '(' << type(VAR) << ':' << VAR << ") ";

#define debug_vars(...) \
  std::cout << "DEBUG: " << __PRETTY_FUNCTION__ << ':' << __LINE__ <<  " -> " ; \
  MAP(debug_vars_name, ##__VA_ARGS__) \
  std::cout << '\n';

#else //NDEBUG
#define IF_RELASE(x)
#define IF_DEBUG(x) x

#define debug_print(...)
#define debug_vars(...)

#endif //NDEBUG
