#parse("C++TemplateVariables.template")
// indicate that this is the 1 file implementing the ${NAME} class
#[[#define]]# ${API_EXTERN}
#[[#include]]# "${Header_Filename}"

#[[#include]]# <string>
#[[#include]]# <iostream>
#[[#include]]# <boost/core/demangle.hpp>

${NAMESPACES_OPEN}

    // this just holds the class fields in a struct to isolate
    // clients from changes to the class structure.
    struct ${NAME}::Impl final
    {
        Impl() :
                strProp1_(),
                strProp2_()
        {
        }

        std::string strProp1_;
        std::string strProp2_;

        bool operator == (const Impl& other) const {
            return strProp1_ == other.strProp1_
                && strProp2_ == other.strProp2_;
        }
    };

    ${NAME}::${NAME}() :
            impl_(std::make_shared<Impl>())
    {
    }

    ${NAME}::${NAME}(std::string prop1, std::string prop2) :
            impl_(std::make_shared<Impl>())
    {
        impl_->strProp1_ = prop1;
        impl_->strProp2_ = prop2;
    }

    // put the destructor in a cpp file to let the compiler know it can put
    // generated implementations here.
    ${NAME}::~${NAME}() = default;

    bool ${NAME}::operator == (const ${NAME}& other) const
    {
        if (this == &other || impl_.get() == other.impl_.get() ) {
            return true;
        }
        return impl_ != nullptr
            && other.impl_ != nullptr
            && *impl_ == *other.impl_;
    }

    std::ostream& operator << (std::ostream& os, const ${NAME}& obj)
    {
        const std::string className = boost::core::demangle(typeid(&obj).name());
        os << "{" << className << ":";
        if (obj.impl_ != nullptr) {
#[[#define]]# ofield(nm)  #nm << ":" << obj.impl_->nm << " "
             os << "address:" << obj.impl_.get() << " "
                << ofield(strProp1_) << ofield(strProp2_);
#[[#undef]]# ofield
        } else {
            os << "impl_: nullptr";
        }
        os << "}" << std::endl;
        return os;
    }

    // no setters . this is immutable so we can use the std::shared_ptr
    std::string ${NAME}::prop1() const
    {
        return impl_->strProp1_;
    }

    // no setters . this is immutable so we can use the std::shared_ptr
    std::string ${NAME}::prop2() const
    {
        return impl_->strProp2_;
    }

${NAMESPACES_CLOSE}


