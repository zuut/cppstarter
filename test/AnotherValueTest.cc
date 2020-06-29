//
// Created by bear on 6/19/20.
//

#include "cppsandbox/AnotherValueClass.h"

#include "util.h"

#include <iostream>
namespace zuut {

    TEST(AnotherValueClassTest, emptyContruct) {
        AnotherValueClass underTest;
        std::cout << "underTest: " << underTest << std::endl;
    }

    TEST(AnotherValueClassTest, contruct) {
        AnotherValueClass underTest("name1", "field2");
        std::cout << "underTest" << underTest << std::endl;

        AnotherValueClass underTest2(underTest);
        std::cout << "underTest2" << underTest2 << std::endl;
        std::cout << "underTest" << underTest << std::endl;

        std::cout << "underTest==underTest2 = " << (underTest == underTest2 ? "true" : "false") << std::endl;
        ASSERT_TRUE(underTest == underTest);
        ASSERT_TRUE(underTest2 == underTest2);
        ASSERT_EQ(underTest, underTest2);
        ASSERT_TRUE(underTest == underTest2);
        ASSERT_FALSE(underTest != underTest2);

        std::cout << "Use auto " << std::endl;
        auto underTest3 = underTest2;
        std::cout << "underTest==underTest3 = " << (underTest == underTest3 ? "true" : "false") << std::endl;
        ASSERT_TRUE(underTest == underTest);
        ASSERT_TRUE(underTest2 == underTest2);
        ASSERT_EQ(underTest, underTest2);
        ASSERT_TRUE(underTest == underTest2);
        ASSERT_FALSE(underTest != underTest2);
    }

    TEST(AnotherValueClassTest, moveConstruct) {
        struct Local {
            static AnotherValueClass make() { return AnotherValueClass("t1", "t2");}
        };
        AnotherValueClass underTest(Local::make());
        std::cout << "underTest==underTest2 = " << (underTest == Local::make() ? "true" : "false") << std::endl;

        std::cout << " Now assignment " << std::endl;
        underTest = AnotherValueClass("t1", "t2");
        std::cout << "underTest: " << underTest << std::endl;
        ASSERT_TRUE(underTest == underTest);
        ASSERT_TRUE(underTest == Local::make());
        ASSERT_FALSE(underTest != Local::make());
    }

    TEST(AnotherValueClassTest, comparison) {
        AnotherValueClass underTest("name1", "field2");
        AnotherValueClass underTest2("name2", "field2");
        std::cout << "underTest==underTest2 = " << (underTest == underTest2 ? "true" : "false") << std::endl;
        ASSERT_FALSE(underTest == underTest2);
        ASSERT_TRUE(underTest != underTest2);
    }

    TEST(AnotherValueClassTest, unique_ptr) {
        auto ptr = std::make_unique<AnotherValueClass>("t1", "t2");
        std::cout << *ptr << std::endl;
        ASSERT_TRUE(ptr != nullptr);
    }

    TEST(AnotherValueClassTest, shared_ptr) {
        auto ptr = std::make_shared<AnotherValueClass>("t1", "t2");
        std::cout << *ptr << std::endl;
        ASSERT_TRUE(ptr != nullptr);
    }

    TEST(AnotherValueClassTest, weak_ptr) {
        auto mainPtr = std::make_shared<AnotherValueClass>("t1", "t2");
        auto weak = std::weak_ptr(mainPtr);
        auto ptr = weak.lock();
        std::cout << *ptr << std::endl;
        ASSERT_TRUE(ptr != nullptr);
    }

    TEST(AnotherValueClassTest, vecOfValues) {
        // verify that there is an implementation of the vector of obj class
        // i.e. no link errors
        auto vec = std::vector<AnotherValueClass>({
                                                          AnotherValueClass("t1", "v1"),
                                                          AnotherValueClass("t2", "v2"),
                                                          AnotherValueClass("t3", "v3")
                                                  });
        for (auto e : vec ) {
            std::cout << e << std::endl;
        }
        ASSERT_EQ(3, vec.size());
    }

    TEST(AnotherValueClassTest, vecOfShared) {
        // verify that there is an implementation of the vector of obj class
        // i.e. no link errors
        auto vec = std::vector<std::shared_ptr<AnotherValueClass>>({});
        ASSERT_EQ(0, vec.size());
    }

    TEST(AnotherValueClassTest, vecOfWeak) {
        // verify that there is an implementation of the vector of obj class
        // i.e. no link errors
        auto vec = std::vector<std::weak_ptr<AnotherValueClass>>({});
        ASSERT_EQ(0, vec.size());
    }
}
