#include "debug_print.h"

#include <string>

#if defined(__GNUG__)

#include <cstdlib>
#include <memory>
#include <cxxabi.h>

std::string demangle(char const * name) {
  int status = -4;

  std::unique_ptr<char, void(*)(void*)> res {
    abi::__cxa_demangle(name, NULL, NULL, &status),
    std::free
  };

  if (status == 0)
    return res.get();
  return name;
}

#else //__GNUG__

std::string demanle(char const * name) {
  return name;
}

#endif //__GNUG__
