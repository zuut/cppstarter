#parse("C++TemplateVariables.template")
#[[#ifndef]]# ${INCLUDE_GUARD}
#[[#define]]# ${INCLUDE_GUARD}

#[[#ifndef]]# ${API_EXTERN}
#[[#define]]# ${API_EXTERN} extern
#[[#endif]]#

/*
 * File ${FILE_NAME}
 * PROJECT_NAME=${PROJECT_NAME}
 */
#[[#include]]# <memory>
#[[#include]]# <vector>
#[[#include]]# <boost/operators.hpp>

${NAMESPACES_OPEN}
    // Object classes must be mutable
    // ALSO: MUTABLE => MUST USE UNIQUE PTR to IMPL.
    class ${NAME} : boost::operators<${NAME}>
    {
    public:
        ${NAME}();
        ${NAME}(const ${NAME}& other);
        ${NAME}(${NAME}&& rref) noexcept;
        // custom constructors
        ${NAME}(std::string prop1, int prop2);
        virtual ~${NAME}();

        // operations
        ${NAME}& operator = (const ${NAME}& other); // copies object
        ${NAME}& operator = (${NAME}&& rref) noexcept ; // transfers object
        bool operator == (const ${NAME}& other) const {
            return impl_ == other.impl_; // objects are the same iff pointers are the same
        }

        friend std::ostream& operator << (std::ostream& os, const ${NAME}& obj);

        // General methods
        void DoSomethingNow();
        
        // Properties        
        std::string prop1() const; void set_prop1(const std::string& val);
        int prop2() const; void set_prop2(int val);
    private:
        struct Impl;
        std::unique_ptr<Impl> impl_;
    };

${NAMESPACES_CLOSE}

${API_EXTERN} template class std::shared_ptr<${nsNAME}>;
${API_EXTERN} template class std::unique_ptr<${nsNAME}>;
${API_EXTERN} template class std::weak_ptr<${nsNAME}>;

${API_EXTERN} template class std::vector<std::shared_ptr<${nsNAME}> >;
${API_EXTERN} template class std::vector<std::weak_ptr<${nsNAME}> >;

#[[#endif]]# //${INCLUDE_GUARD}
