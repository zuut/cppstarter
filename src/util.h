//
// Created by bear on 6/19/20.
//

#ifndef CPPSANDBOX_UTIL_H
#define CPPSANDBOX_UTIL_H
#include <iostream>
#include <vector>
#include <typeinfo>
#include <boost/core/demangle.hpp>

namespace zuut {
    extern std::ostream &operator<<(std::ostream &os, const std::vector<std::string> v);
}

inline std::string clazzname(const std::type_info& typeInfo) { return boost::core::demangle(typeInfo.name()); }
template<typename T> std::string clazzname(T&& obj) { return clazzname(typeid(obj)); }

#endif //CPPSANDBOX_UTIL_H
