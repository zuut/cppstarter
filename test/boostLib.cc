//
// Created by bear on 6/27/20.
//
#include "util.h"

#include <iostream>

#include <boost/units/quantity.hpp>
#include <boost/units/io.hpp>
#include <boost/units/systems/si.hpp>
#include <boost/units/systems/si/prefixes.hpp>
#include <boost/units/systems/cgs.hpp>

namespace zuut {
    template<class T1, class T2>
    static decltype(auto)
    work(const T1 &F, const T2 &dx) { return F * dx; }

    TEST(BoostTest, units) {
        using namespace boost::units;
        using namespace boost::units::si;
        auto F(newton);

        // Create our own constants for the mks system
        const auto centimeter = 1.0 * centi * meter; // not used
        const auto centimeters = 1.0 * centi * meters; // not used
        const auto nanometers = 1.0 * nano * meter;

        std::cout << "Using the si (mks meter/kilogram/second) system " << std::endl;
        auto dist1(1.5 * meters);
        auto dist2 = 2.0 * nanometers;
        auto dist3 = 150 * nano * meters;
        auto dist4 = 0.002 * nanometers;
        auto dist5 = dist2 + dist3 + dist4;
        // ERROR can't do a : auto dist6 = dist1 + dist5; w/o a type conversion

#define show(x)  /*clazzname(x) << " " << */ #x << " = " << x
        std::cout << show(dist1) << std::endl;
        std::cout << show(dist2) << std::endl;
        std::cout << show(dist3) << std::endl;
        std::cout << show(dist4) << std::endl;
        std::cout << show(dist5) << std::endl;

        // cgs (centimeter-gram-second system)
        std::cout << "Using the cgs (centimeter/gram/second) system " << std::endl;
        quantity<cgs::length> cm_dist1 = static_cast<quantity<cgs::length>>(dist1);
        auto cm_dist2 = 2.0 * cgs::centimeter;
        auto cm_dist3 = 150 * cgs::centimeter;
        auto cm_dist4(3 * cgs::centimeter);
        std::cout << show(cm_dist1) << std::endl;
        std::cout << show(cm_dist2) << std::endl;
        std::cout << show(cm_dist3) << std::endl;
        std::cout << show(cm_dist4) << std::endl;

        std::cout << "Other units system " << std::endl;
        auto E(work(F, dist1));
        std::cout << show(E) << std::endl;
#undef show
    }
}
