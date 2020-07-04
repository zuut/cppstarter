//
// Created by bear on 6/18/20.
//

// indicate that this is the 1 file implementing the APIWITHIMPLCLASS
#define OBJECTCLASS_EXTERN
#include "cxxstarter/ObjectClass.h"
#include "util.h"

#include <string>
#include <iostream>

namespace zuut
{
    // this just holds the class fields in a struct to isolate
    // clients from changes to the class structure.
    struct ObjectClass::Impl final
    {
        Impl() :
                strProp1_(),
                strProp2_(),
                collectionProp3_(),
                primitive4_(0)
        {
        }

        Impl(const std::unique_ptr<ObjectClass::Impl>& other) :
                strProp1_(other->strProp1_),
                strProp2_(other->strProp2_),
                collectionProp3_(other->collectionProp3_),
                primitive4_(other->primitive4_)
        {
        }

        std::string strProp1_;
        std::string strProp2_;
        std::vector<std::string> collectionProp3_;
        int primitive4_;
    };

    ObjectClass::ObjectClass()  :
            impl_(std::make_unique<Impl>())
    {
        std::cout<< "creating " << *this << std::endl;
    }

    ObjectClass::ObjectClass(const ObjectClass& other) :
        // is there any means that someone can cause our impl to be moved and left empty?
        impl_(other.impl_ ? std::make_unique<Impl>(*other.impl_) : std::make_unique<Impl>())
    {
        std::cout << "copying " << *this << " from " << other << std::endl;
    }

    ObjectClass::ObjectClass(ObjectClass&& rref) noexcept = default;

    ObjectClass::ObjectClass(std::string prop1, std::string prop2) :
            ObjectClass(prop1, prop2, 2)
    {
    }

    ObjectClass::ObjectClass(std::string prop1, std::string prop2, int prop4) :
            impl_(std::make_unique<Impl>())
    {
        impl_->strProp1_ = std::move(prop1);
        impl_->strProp2_ = std::move(prop2);

        impl_->collectionProp3_.push_back(impl_->strProp1_);
        impl_->collectionProp3_.push_back(impl_->strProp2_);
        impl_->primitive4_ = prop4;

        std::cout<< "creating(x,y) " << *this << std::endl;
    }

    ObjectClass::~ObjectClass() = default;

    ObjectClass& ObjectClass::operator = (const ObjectClass& other)
    {
        if (impl_ && other.impl_) {
            *this->impl_ = *other.impl_;
        } else if (other.impl_) {
            impl_ = std::make_unique<Impl>(*other.impl_);
        } else {
            impl_ = std::make_unique<Impl>(nullptr);
        }
        return *this;
    }

    ObjectClass& ObjectClass::operator = (ObjectClass&& rref) noexcept = default;

    std::ostream& operator << (std::ostream& os, const ObjectClass& obj)
    {
        os << "{" << clazzname(obj) << ": ";
        if (obj.impl_ != nullptr) {
#define ofield(nm)  #nm << ":" << obj.impl_->nm << " "
            os <<
            "address:" << obj.impl_.get() << " "
              << ofield(strProp1_) << ofield(strProp2_)
              << ofield(collectionProp3_) << ofield(primitive4_);
#undef ofield
        } else {
            os << "impl_: nullptr";
        }
        os << "}" << std::endl;
        return os;
    }

    std::string ObjectClass::prop1() const
    {
        return impl_->strProp1_;
    }

    void ObjectClass::set_prop1(const std::string& val)
    {
        impl_->strProp1_ = val;
    }

    std::string ObjectClass::prop2() const
    {
        return impl_->strProp2_;
    }

    void ObjectClass::set_prop2(const std::string& val)
    {
        impl_->strProp2_ = val;
    }
}
/* namespace zuut */
