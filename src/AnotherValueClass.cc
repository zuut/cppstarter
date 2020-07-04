//
// Created by bear on 6/18/20.
//

// indicate that this is the 1 file implementing the APIWITHIMPLCLASS
#define ANOTHERVALUECLASS_EXTERN
#include "cxxstarter/AnotherValueClass.h"
#include "util.h"

#include <string>

namespace zuut
{
    // this just holds the class fields in a struct to isolate
    // clients from changes to the class structure.
    struct AnotherValueClass::Impl final
    {
        Impl() :
                strProp1_(),
                strProp2_(),
                collectionProp3_(),
                primitive4_(0)
        {
        }

        std::string strProp1_;
        std::string strProp2_;
        std::vector<std::string> collectionProp3_;
        int primitive4_;

        bool operator == (const Impl& other) const {
            return strProp1_ == other.strProp1_
            && strProp2_ == other.strProp2_
            && primitive4_ == other.primitive4_
            && collectionProp3_.size() == other.collectionProp3_.size()
            && std::equal(collectionProp3_.begin(), collectionProp3_.end(),
                     other.collectionProp3_.begin());
        }
    };

    AnotherValueClass::AnotherValueClass() :
            impl_(std::make_shared<Impl>())
    {
        std::cout << "creating " << *this << std::endl;
    }

    AnotherValueClass::AnotherValueClass(std::string prop1, std::string prop2) :
            impl_(std::make_shared<Impl>())
    {
        impl_->strProp1_ = prop1;
        impl_->collectionProp3_.push_back(prop1);
        impl_->strProp2_ = prop2;
        impl_->collectionProp3_.push_back(prop2);
        impl_->primitive4_ = impl_->collectionProp3_.size();
        std::cout << "creating(x,y) " << *this << std::endl;
    }

    // put the destructor in a source file to let the compiler know it can put
    // generated implementations here.
    AnotherValueClass::~AnotherValueClass() = default;

    bool AnotherValueClass::operator == (const AnotherValueClass& other) const
    {
        if ( other.impl_ == 0) {
            return false;
        }
        return *impl_ == *other.impl_;
    }

    std::ostream& operator << (std::ostream& os, const AnotherValueClass& obj)
    {
#define ofield(nm)  #nm << ":" << obj.impl_->nm << " "
        os << "{" << clazzname(obj) << ": "
           << "address:" << obj.impl_.get() << " "
           << ofield(strProp1_) << ofield(strProp2_)
           << ofield(collectionProp3_) << ofield(primitive4_)
           << "}" << std::endl;
#undef ofield
        return os;
    }

    std::string AnotherValueClass::prop1() const
    {
        return impl_->strProp1_;
    }

    std::string AnotherValueClass::prop2() const
    {
        return impl_->strProp2_;
    }
}
/* namespace zuut */
