#include <stdio.h>
#include "Container.h"
#include "BaseFeature.h"


int main() 
{
    printf("Hello World!");
    // system("pause");
    Container c;
    c.testVector();
    c.testMismatch();
    c.testFind();

    A a;
    a.testForeach();
    a.testUniquePtr();
    a.testSharePtr();
    a.testWeakPtr();
    a.testLoopReference(); 
    a.testLambda();
    a.testC99();
    a.testPrintf();
    a.testMacro();
    a.testUnicodeLib();
    a.testUnicodeLib2();

    a.testBeginEnd();
    a.testStaticAssert();

    return 0;
}