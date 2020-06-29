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
#[[#include]]# <iostream>
#[[#include]]# <boost/operators.hpp>

${NAMESPACES_OPEN}
    // We make our value classes immutable
    // SINCE ITS IMMUTABLE, WE CAN USE SHARED POINTER INSTEAD OF UNIQUE PTR
    // This allows us to use default copy and move ops
    class ${NAME} : boost::operators<${NAME}>{
    public:
        ${NAME}();
        ${NAME}(const ${NAME}& other) = default;
        ${NAME}(${NAME}&& rref) noexcept = default;
        // Custom constructor
        ${NAME}(std::string prop1, std::string prop2);
        virtual ~${NAME}();

        ${NAME}& operator = (const ${NAME}& other) = default;
        ${NAME}& operator = (${NAME}&& rref) noexcept = default;

        bool operator == (const ${NAME}& other) const;

        friend std::ostream& operator << (std::ostream& os, const ${NAME}& obj);

        std::string prop1() const;
        std::string prop2() const;
    private:
        struct Impl;
        std::shared_ptr<Impl> impl_;
    };
}

${API_EXTERN} template class std::shared_ptr<${nsNAME}>;
${API_EXTERN} template class std::unique_ptr<${nsNAME}>;
${API_EXTERN} template class std::weak_ptr<${nsNAME}>;

${API_EXTERN} template class std::vector<${nsNAME}>;
${API_EXTERN} template class std::vector<std::shared_ptr<${nsNAME}> >;
${API_EXTERN} template class std::vector<std::weak_ptr<${nsNAME}> >;



#endif //${INCLUDE_GUARD}
