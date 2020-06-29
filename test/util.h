//
// Created by bear on 6/18/20.
//

#ifndef CPPSANDBOX_UTIL_H
#define CPPSANDBOX_UTIL_H
#include "gtest/gtest.h"
#include <boost/type_index.hpp>

#define SHOW( stmt )  std::cout << #stmt << endl; stmt

namespace zuut {
    class Util {

    };

    template<typename T>
    auto clazz(T &&obj) { return boost::typeindex::type_id_with_cvr<decltype(obj)>(); }

    template<typename T>
    auto clazz() { return boost::typeindex::type_id_with_cvr<T>(); }

    template<typename T>
    std::string clazzname(T &&obj) { return clazz(obj).pretty_name(); }

    template<typename T>
    std::string clazzname() { return clazz<T>().pretty_name(); }

}
#endif //CPPSANDBOX_UTIL_H
