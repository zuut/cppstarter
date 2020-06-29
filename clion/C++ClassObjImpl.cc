#parse("C++TemplateVariables.template")
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
                strProp_(),
                primitive_(0)
        {
        }

        std::string strProp_;
        int primitive_;
    };

    ${NAME}::${NAME}()  :
            impl_(std::make_unique<Impl>())
    {
    }

    ${NAME}::${NAME}(const ${NAME}& other) :
        impl_(other.impl_ ? std::make_unique<Impl>(*other.impl_) : std::make_unique<Impl>())
    {
    }

    ${NAME}::${NAME}(${NAME}&& rref) noexcept = default;

    // Custom constructor
    ${NAME}::${NAME}(std::string prop1, int prop2) :
            impl_(std::make_unique<Impl>())
    {
        impl_->strProp_ = prop1;
        impl_->primitive_ = prop2;
    }

    ${NAME}::~${NAME}() = default;

    ${NAME}& ${NAME}::operator = (const ${NAME}& other)
    {
        // We don't worry about potential object slicing because
        // Impl is never subclassed
        if (impl_ && other.impl_) {
            *this->impl_ = *other.impl_;
        } else if (other.impl_) {
            impl_ = std::make_unique<Impl>(*other.impl_);
        } else {
            impl_.reset();
        }

        return *this;
    }

    ${NAME}& ${NAME}::operator = (${NAME}&& rref) noexcept = default;

    std::ostream& operator << (std::ostream& os, const ${NAME}& obj)
    {
        const std::string className = boost::core::demangle(typeid(&obj).name());
        os << "{" << className << ":";
        if (obj.impl_ != nullptr) {
#[[#define]]# ofield(nm)  #nm << ":" << obj.impl_->nm << " "
             os << "address:" << obj.impl_.get() << " "
                << ofield(strProp_) 
                << ofield(primitive_);
#[[#undef]]# ofield
        } else {
            os << "impl_: nullptr";
        }
        os << "}" << std::endl;
        return os;
    }

    std::string ${NAME}::prop1() const
    {
        return impl_->strProp_;
    }

    void ${NAME}::set_prop1(const std::string& val)
    {
        impl_->strProp_ = val;
    }

    int ${NAME}::prop2() const
    {
        return impl_->primitive_;
    }

    void ${NAME}::set_prop2(const int val)
    {
        impl_->primitive_ = val;
    }


${NAMESPACES_CLOSE}

