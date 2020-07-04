//
// Created by bear on 6/18/20.
//

#ifndef CPPSANDBOX_ANOTHERVALUECLASS_H
#define CPPSANDBOX_ANOTHERVALUECLASS_H

#include <memory>
#include <vector>
#include <iostream>
#include <boost/operators.hpp>

namespace zuut {
#ifndef ANOTHERVALUECLASS_EXTERN
#define ANOTHERVALUECLASS_EXTERN extern
#endif
    // We make our value classes immutable
    // SINCE ITS IMMUTABLE, WE CAN USE SHARED POINTER INSTEAD OF UNIQUE PTR
    class AnotherValueClass : boost::operators<AnotherValueClass>{
    public:
        AnotherValueClass();
        AnotherValueClass(const AnotherValueClass& other) = default;
        AnotherValueClass(AnotherValueClass&& rref) noexcept = default;

        AnotherValueClass(std::string prop1, std::string prop2);
        virtual ~AnotherValueClass();

        AnotherValueClass& operator = (const AnotherValueClass& other) = default;
        AnotherValueClass& operator = (AnotherValueClass&& rref) noexcept = default;

        bool operator == (const AnotherValueClass& other) const;

        friend std::ostream& operator << (std::ostream& os, const AnotherValueClass& obj);

        std::string prop1() const;
        std::string prop2() const;
    private:
        struct Impl;
        std::shared_ptr<Impl> impl_;
    };
}

ANOTHERVALUECLASS_EXTERN template class std::shared_ptr<zuut::AnotherValueClass>;
ANOTHERVALUECLASS_EXTERN template class std::unique_ptr<zuut::AnotherValueClass>;
ANOTHERVALUECLASS_EXTERN template class std::weak_ptr<zuut::AnotherValueClass>;

ANOTHERVALUECLASS_EXTERN template class std::vector<zuut::AnotherValueClass>;
ANOTHERVALUECLASS_EXTERN template class std::vector<std::shared_ptr<zuut::AnotherValueClass> >;
ANOTHERVALUECLASS_EXTERN template class std::vector<std::weak_ptr<zuut::AnotherValueClass> >;



#endif //CPPSANDBOX_ANOTHERVALUECLASS_H
