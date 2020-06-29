//
// Created by bear on 6/18/20.
//

#ifndef CPPSANDBOX_VALUECLASS_H
#define CPPSANDBOX_VALUECLASS_H

#include <string>
#include <vector>
#include <iosfwd>
#include <boost/operators.hpp>

namespace zuut {
#ifndef VALUECLASS_EXTERN
#define VALUECLASS_EXTERN extern
#endif
    // We make our value classes immutable
    class ValueClass : boost::operators<ValueClass> {
    public:
        ValueClass(
                std::string strProp1,
                std::string strProp2,
                std::vector<std::string> collectionProp3,
                int primitive4);

        ValueClass() = default;
        ValueClass(const std::string& initialProp1, const std::string& initialProp2 = "");
        ValueClass(const ValueClass& other) = default;
        ValueClass(ValueClass&& rref) noexcept = default;
        virtual ~ValueClass();

        ValueClass& operator = (const ValueClass& other) = default;
        ValueClass& operator = (ValueClass&& rref) noexcept = default;

        // necessary for list<ValueClass> and set<ValueClass> (as opposed to list<ValueClass*>)
        // which need comparators
        bool operator == (const ValueClass& other) const;
        bool operator < (const ValueClass& other) const;

        friend std::ostream& operator << (std::ostream& out, const ValueClass& vc);
        friend std::istream& operator >> (std::istream& is, ValueClass& vc);

        std::string prop1() const { return strProp1_; }
        std::string prop2() const { return strProp2_; }
    private:

        std::string strProp1_;
        std::string strProp2_;
        std::vector<std::string> collectionProp3_;
        int primitive4_;
    };
}


#include <memory>

VALUECLASS_EXTERN template class std::shared_ptr<zuut::ValueClass>;
VALUECLASS_EXTERN template class std::unique_ptr<zuut::ValueClass>;
VALUECLASS_EXTERN template class std::weak_ptr<zuut::ValueClass>;

// list vector set
VALUECLASS_EXTERN template class std::vector<zuut::ValueClass>;
VALUECLASS_EXTERN template class std::vector<std::shared_ptr<zuut::ValueClass> >;
VALUECLASS_EXTERN template class std::vector<std::weak_ptr<zuut::ValueClass> >;

#include <list>
VALUECLASS_EXTERN template class std::list<zuut::ValueClass>;
VALUECLASS_EXTERN template class std::list<std::shared_ptr<zuut::ValueClass> >;

#include <set>
VALUECLASS_EXTERN template class std::set<zuut::ValueClass>;
VALUECLASS_EXTERN template class std::set<std::shared_ptr<zuut::ValueClass> >;

#endif //CPPSANDBOX_VALUECLASS_H
