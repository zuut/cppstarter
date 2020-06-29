#parse("C++TemplateVariables.template")
#if($NAME.trim().endsWith("Test"))
   #set($newLen = $NAME.length() - 4 )
   #set($CLASS_UNDER_TEST = $NAME.substring(0, $newLen) )
#else
   #set($CLASS_UNDER_TEST = $NAME )
#end
#[[#include]]# "${Header_Filename}"

#[[#include]]# <string>
#[[#include]]# <iostream>

#[[#include]]# "gtest/gtest.h"

${NAMESPACES_OPEN}

TEST(${CLASS_UNDER_TEST}Test, emptyContruct) {
    ${CLASS_UNDER_TEST} underTest;
    std::cout << "underTest" << underTest << std::endl;
    ASSERT_TRUE( 1 == 1 );
}
${NAMESPACES_CLOSE}

