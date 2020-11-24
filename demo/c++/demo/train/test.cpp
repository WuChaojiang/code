#include <stdio.h>
#include "Container.h"
#include "BaseFeature.h"
#include "Copyable.h"


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

    a.testRawStringLiteral();
    a.testUnicodeLibStream();


    int num = 1;
    const int &num1 = num;
    int &num2 = num;
    int &&num3 = 1;
    std::string str = "Hello World!";
    typeCheck<int>(num);
    typeCheck<const int &>(num1);
    typeCheck<int &>(num2);
    typeCheck(8);

    testCopy();

    a.testDecay();

    
    return 0;
}