//
// Created by bear on 7/3/20.
//
#include <fmt/core.h>
#include "util.h"

namespace zuut {

    TEST(fmtLibTest, sooo_basic) {
        fmt::print(stdout, "This is a hello {}", "world");
    }
    
    TEST(fmtLibTest, lessbasic) {
        fmt::print(stdout, "{where} is a hello {what} {num:d}  {num2:3.2f}. ok {where}?",
                fmt::arg("where", "This"), fmt::arg("what", "world"), fmt::arg("num", 1000323),
                   fmt::arg("num2", 2718194.0));
    }
}
