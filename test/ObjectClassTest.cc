//
// Created by bear on 6/19/20.
//

#include "../include/cxxstarter/ObjectClass.h"

#include "util.h"

#include <iostream>


namespace zuut {

    TEST(ObjectClassTest, emptyContruct) {
        ObjectClass underTest;
        std::cout << "underTest" << underTest << std::endl;
    }

    TEST(ObjectClassTest, construct3) {
        ObjectClass underTest("name1", "field1", 3'000'000);
        std::cout << "underTest" << underTest << std::endl;
    }

    TEST(ObjectClassTest, contruct) {
        ObjectClass underTest("name1", "field2");
        std::cout << "underTest" << underTest << std::endl;

        ObjectClass underTest2(underTest);
        std::cout << "underTest2" << underTest2 << std::endl;
        std::cout << "underTest" << underTest << std::endl;

        std::cout << "underTest==underTest2 = " << (underTest == underTest2 ? "true" : "false") << std::endl;

        // This is an object so the only true is if they two are the same instance
        ASSERT_TRUE(underTest == underTest);
        ASSERT_TRUE(underTest2 == underTest2);
        ASSERT_FALSE(underTest == underTest2);
        ASSERT_TRUE(underTest != underTest2);

        std::cout << "using auto " << std::endl;
        auto underTest3 = underTest2;
        std::cout << "underTest3" << underTest3 << std::endl;
        std::cout << "underTest" << underTest << std::endl;

        std::cout << "underTest==underTest3 = " << (underTest == underTest3 ? "true" : "false") << std::endl;

        // This is an object so the only true is if they two are the same instance
        ASSERT_TRUE(underTest == underTest);
        ASSERT_TRUE(underTest3 == underTest3);
        ASSERT_FALSE(underTest == underTest3);
        ASSERT_TRUE(underTest != underTest3);
    }

    TEST(ObjectClassTest, moveConstruct) {
        struct Local {
            static ObjectClass make(std::string nm1, std::string nm2) { return ObjectClass(nm1, nm2); }
        };
        std::cout << "expecting move constructor " << std::endl;
        ObjectClass underTest(std::move(Local::make("t1", "t2")));
        std::cout << "underTest:" << underTest << std::endl;
        std::cout << "underTest==underTest2 = " << (underTest == Local::make("t1", "t2") ? "true" : "false")
                  << std::endl;
        ASSERT_TRUE(underTest == underTest);
        ASSERT_FALSE(underTest == Local::make("t1", "t2"));
        ASSERT_TRUE(underTest != Local::make("t1", "t2"));

        std::cout << "expecting move constructor " << std::endl;
        ObjectClass underTest2(Local::make("t1", "t2"));
        std::cout << "underTest2:" << underTest2 << std::endl;
    }

    TEST(ObjectClassTest, moveAssignment) {
        struct Local {
            static ObjectClass make(std::string nm1, std::string nm2) { return ObjectClass(nm1, nm2); }
        };
        auto underTest = Local::make("t1", "t2");

        std::cout << "expecting move assignment " << std::endl;
        underTest = std::move(Local::make("t2", "t3"));
        std::cout << "underTest:" << underTest << std::endl;
        ASSERT_TRUE(underTest == underTest);
    }


    TEST(ObjectClassTest, comparison) {
        ObjectClass underTest("name1", "field2");
        ObjectClass underTest2("name2", "field2");
        std::cout << "underTest==underTest2 = " << (underTest == underTest2 ? "true" : "false") << std::endl;
        ASSERT_FALSE(underTest == underTest2);
        ASSERT_TRUE(underTest != underTest2);
    }

    TEST(ObjectClassTest, unique_ptr) {
        auto ptr = std::make_unique<ObjectClass>("t1", "t2");
        std::cout << *ptr << std::endl;
        ASSERT_TRUE(ptr != nullptr);
    }

    TEST(ObjectClassTest, shared_ptr) {
        auto ptr = std::make_shared<ObjectClass>("t1", "t2");
        std::cout << *ptr << std::endl;
        ASSERT_TRUE(ptr != nullptr);
    }

    TEST(ObjectClassTest, weak_ptr) {
        auto mainPtr = std::make_shared<ObjectClass>("t1", "t2");
        auto weak = std::weak_ptr(mainPtr);
        auto ptr = weak.lock();
        std::cout << *ptr << std::endl;
        ASSERT_TRUE(ptr != nullptr);
    }

    TEST(ObjectClassTest, vecOfValues) {
        // verify that there is an implementation of the vector of obj class
        // i.e. no link errors

        std::cout << "creating vector of objects " << std::endl;
        auto vec = std::vector<ObjectClass>({
                  ObjectClass("t1", "v1"),
                  ObjectClass("t2", "v2"),
                  ObjectClass("t3", "v3")
        });
        std::cout << "done creating vector of objects " << clazzname(vec) << std::endl;

        std::cout << "creating vector2 of objects " << std::endl;
        std::vector<ObjectClass> vec2{
                ObjectClass("t1", "v1"),
                ObjectClass("t2", "v2"),
                ObjectClass("t3", "v3")
        };
        std::cout << "done creating vector2 of objects " << clazzname(vec2) << std::endl;

        std::cout << "iterate by copy " << std::endl;
        for (auto e : vec) {
            std::cout << e << std::endl;
        }

        std::cout << "Add an element and then iterate by ref " << std::endl;
        vec.emplace_back("t4", "v4");
        for (auto &e : vec) {
            std::cout << e << std::endl;
        }
        std::cout << "done w/ iteration" << std::endl;
        ASSERT_EQ(4, vec.size());
    }

    TEST(ObjectClassTest, vecOfUnique) {
        // verify that there is an implementation of the vector of obj class
        // i.e. no link errors
        std::cout << "creating vector of objects " << std::endl;
        std::vector<std::unique_ptr<ObjectClass>> vec;
        vec.insert(end(vec), std::make_unique<ObjectClass>("t1", "v1"));
        vec.insert(end(vec), std::make_unique<ObjectClass>("t2", "v2"));
        vec.insert(end(vec), std::make_unique<ObjectClass>("t3", "v3"));
        std::cout << "done creating vector of objects " << clazzname(vec) << std::endl;

        std::cout << "iterate by ref " << std::endl;
        for (auto &ptr : vec) {
            std::cout << *ptr << std::endl;
        }
        std::cout << "done w/ iteration" << std::endl;
        ASSERT_EQ(3, vec.size());
    }

    TEST(ObjectClassTest, vecOfShared) {
        // verify that there is an implementation of the vector of obj class
        // i.e. no link errors
        std::cout << "creating vector of objects " << std::endl;
        auto vec = std::vector<std::shared_ptr<ObjectClass>>({
               std::make_shared<ObjectClass>("t1", "v1"),
               std::make_shared<ObjectClass>("t2", "v2"),
               std::make_shared<ObjectClass>("t3", "v3")
        });
        std::cout << "done creating vector of objects " << clazzname(vec) << std::endl;

        std::cout << "creating vector2 of objects " << std::endl;
        std::vector<std::shared_ptr<ObjectClass>> vec2{
                std::make_shared<ObjectClass>("t1", "v1"),
                std::make_shared<ObjectClass>("t2", "v2"),
                std::make_shared<ObjectClass>("t3", "v3")
        };
        std::cout << "done creating vector2 of objects " << clazzname(vec2) << std::endl;
        std::cout << "iterate by copy " << std::endl;
        for (auto ptr : vec) {
            std::cout << *ptr << std::endl;
        }

        std::cout << "iterate by ref " << std::endl;
        for (auto &ptr : vec) {
            std::cout << *ptr << std::endl;
        }
        std::cout << "done w/ iteration" << std::endl;
        ASSERT_EQ(3, vec.size());
    }

    TEST(ObjectClassTest, vecOfWeak) {
        // verify that there is an implementation of the vector of obj class
        // i.e. no link errors
        auto vec = std::vector<std::weak_ptr<ObjectClass>>({});
        ASSERT_EQ(0, vec.size());
    }
}
