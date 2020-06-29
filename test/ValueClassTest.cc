//
// Created by bear on 6/18/20.
//

#include "../include/cppsandbox/ValueClass.h"
#include "util.h"

#include <iostream>
namespace zuut {

    TEST(ValueClassTest, emptyContruct) {
        ValueClass underTest;
        std::cout << "underTest" << underTest << std::endl;
    }

    TEST(ValueClassTest, contruct) {
        ValueClass underTest("name1", "field2");
        std::cout << "underTest" << underTest << std::endl;

        ValueClass underTest2(underTest);
        std::cout << "underTest2" << underTest2 << std::endl;
        std::cout << "underTest" << underTest << std::endl;

        ASSERT_TRUE(underTest == underTest);
        ASSERT_TRUE(underTest2 == underTest2);
        ASSERT_EQ(underTest, underTest2);
        ASSERT_TRUE(underTest == underTest2);
        ASSERT_FALSE(underTest != underTest2);
    }

    TEST(ValueClassTest, comparison) {
        ValueClass underTest("name1", "field2");
        ValueClass underTest2("name2", "field2");
        std::cout << "underTest==underTest2 = " << (underTest == underTest2 ? "true" : "false") << std::endl;
        ASSERT_FALSE(underTest == underTest2);
        ASSERT_TRUE(underTest != underTest2);
    }

    TEST(ValueClassTest, unique_ptr) {
        auto ptr = std::make_unique<ValueClass>("t1", "t2");
        std::cout << *ptr << std::endl;
        ASSERT_TRUE(ptr != nullptr);
    }

    TEST(ValueClassTest, shared_ptr) {
        auto ptr = std::make_shared<ValueClass>("t1", "t2");
        std::cout << *ptr << std::endl;
        ASSERT_TRUE(ptr != nullptr);
    }

    TEST(ValueClassTest, weak_ptr) {
        auto mainPtr = std::make_shared<ValueClass>("t1", "t2");
        auto weak = std::weak_ptr(mainPtr);
        auto ptr = weak.lock();
        std::cout << *ptr << std::endl;
        ASSERT_TRUE(ptr != nullptr);
    }

    TEST(ValueClassTest, vecOfValues) {
        // verify that there is an implementation of the vector of obj class
        // i.e. no link errors
        auto vec = std::vector<ValueClass>({
                 ValueClass("t1", "v1"),
                 ValueClass("t2", "v2"),
                 ValueClass("t3", "v3")
         });
        for (auto e : vec) {
            std::cout << e << std::endl;
        }
        ASSERT_EQ(3, vec.size());
    }

    TEST(ValueClassTest, vecOfShared) {
        // verify that there is an implementation of the vector of obj class
        // i.e. no link errors
        auto vec = std::vector<std::shared_ptr<ValueClass>>({});
        ASSERT_EQ(0, vec.size());
    }

    TEST(ValueClassTest, vecOfWeak) {
        // verify that there is an implementation of the vector of obj class
        // i.e. no link errors
        auto vec = std::vector<std::weak_ptr<ValueClass>>({});
        ASSERT_EQ(0, vec.size());
    }
}