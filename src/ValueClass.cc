//
// Created by bear on 6/18/20.
//

#define VALUECLASS_EXTERN
#include "cxxstarter/ValueClass.h"
#include "util.h"

#include <string>
#include <iostream>

namespace zuut
{

    ValueClass::ValueClass(
            std::string strProp1,
            std::string strProp2,
            std::vector<std::string> collectionProp3,
            int primitive4) :
            strProp1_(std::move(strProp1)),
            strProp2_(std::move(strProp2)),
            collectionProp3_(std::move(collectionProp3)),
            primitive4_(std::move(primitive4))
    {
        // TODO Auto-generated constructor stub
    }

    ValueClass::ValueClass(
            const std::string& initialProp1,
            const std::string& initialProp2) :
            strProp1_(initialProp1),
            strProp2_(initialProp2)
    {
        collectionProp3_.push_back(initialProp1);
        collectionProp3_.push_back(initialProp2);
        primitive4_ = collectionProp3_.size();
    }

    ValueClass::~ValueClass() = default;

/** the operator== must satisfy the following:
 *  [1] Define operator==(x,y) to be !(operator<(x,y)||operator<(y,x)).
 *  [2] Transitivity of equivalence: If operator==(x,y) and operator==(y,z), then operator==(x,z).
 */
    bool ValueClass::operator == (const ValueClass& other) const {
        return strProp1_ == other.strProp1_
               && strProp2_ == other.strProp2_
               && primitive4_ == other.primitive4_
               && collectionProp3_.size() == other.collectionProp3_.size()
               && std::equal(collectionProp3_.begin(), collectionProp3_.end(),
                             other.collectionProp3_.begin());
    }

    /** the operator < must satisfy the following:
 *  [1] Irreflexivity: operator<(x,x) is false.
 *  [2] Antisymmetry: operator<(x,y) implies !operator<(y,x).
 *  [3] Transitivity: If operator<(x,y) and operator<(y,z), then operator<(x,z).
 *  [4] Transitivity of equivalence: Define operator==(x,y) to be !(operator<(x,y)||operator<(y,x)).
 */
    bool ValueClass::operator < (const ValueClass& other) const
    {
        return this->strProp1_ < other.strProp1_;
    }

    std::ostream& operator << (std::ostream& out, const ValueClass& obj)
    {
#define ofield(nm)  #nm << ":" << obj.nm << " "
        out << "{" << clazzname(obj) << ": "
           << "address:" << &obj << " "
           << ofield(strProp1_) << ofield(strProp2_)
           << ofield(collectionProp3_) << ofield(primitive4_)
           << "}" << std::endl;
#undef ofield
        return out;
    }

}
