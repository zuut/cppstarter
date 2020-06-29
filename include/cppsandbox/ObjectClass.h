//
// Created by bear on 6/18/20.
//

#ifndef CPPSANDBOX_OBJECTCLASS_H
#define CPPSANDBOX_OBJECTCLASS_H


#include <memory>
#include <vector>
#include <boost/operators.hpp>

namespace zuut
{
#ifndef OBJECTCLASS_EXTERN
#define OBJECTCLASS_EXTERN extern
#endif
    // Object classes must be mutable
    // ALSO: MUTABLE => MUST USE UNIQUE PTR to IMPL.
    class ObjectClass : boost::operators<ObjectClass>
    {
    public:
        ObjectClass();
        ObjectClass(const ObjectClass& other);
        ObjectClass(ObjectClass&& rref) noexcept;
        ObjectClass(std::string prop1, std::string prop2);
        ObjectClass(std::string prop1, std::string prop2, int prop4);
        virtual ~ObjectClass();

        ObjectClass& operator = (const ObjectClass& other); // copies object
        ObjectClass& operator = (ObjectClass&& rref) noexcept ; // transfers object
        bool operator == (const ObjectClass& other) const {
            return impl_ == other.impl_;
        }
        friend std::ostream& operator << (std::ostream& os, const ObjectClass& obj);

        std::string prop1() const;
        void set_prop1(const std::string& val);

        std::string prop2() const;
        void set_prop2(const std::string& val);
    private:
        class Impl;
        std::unique_ptr<Impl> impl_;
    };

} /* namespace zuut */

OBJECTCLASS_EXTERN template class std::shared_ptr<zuut::ObjectClass>;
OBJECTCLASS_EXTERN template class std::unique_ptr<zuut::ObjectClass>;
OBJECTCLASS_EXTERN template class std::weak_ptr<zuut::ObjectClass>;

OBJECTCLASS_EXTERN template class std::vector<std::shared_ptr<zuut::ObjectClass> >;
OBJECTCLASS_EXTERN template class std::vector<std::weak_ptr<zuut::ObjectClass> >;

#endif //CPPSANDBOX_OBJECTCLASS_H
