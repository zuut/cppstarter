//
// Created by bear on 6/19/20.
//
#include "util.h"
namespace zuut {
    std::ostream &operator<<(std::ostream &os, const std::vector<std::string> v) {
        os << "[";
        bool isfirst = true;
        for (auto &&item : v) {
            os << (!isfirst ? "," : "") << item;
            isfirst = false;
        }
        os << "]";
        return os;
    }
}
