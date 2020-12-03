#include <stdio.h>
#include "Container.h"
#include "BaseFeature.h"
#include "Copyable.h"
#include "TestTemplate.h"
#include "MyString.h"
#include "has_ptr_mem.h"
#include "huge_mem.h"
#include "MyData.h"
#include "RGBA.h"

extern template void test_fun1<int>(int);
// HasPtrMem GetTemp();

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
    a.testForwarding();

    a.testTemplate();
    test_fun1(2);

    char p[] = "Hello, World!";
    MyString ms(p);
    MyString ms1(ms);
    MyString ms2 = ms;

    HasPtrMem hpm = GetTemp();
    cout << "Resource from " << __func__ << ": " << hex << hpm.d << endl;

    JudgeReferenceType();

    Moveable moveable = GetMoveableTemp();

    MyData d;
    d[{2, 3, 5}] = 7;
    d[{1, 4, 5, 8}] = 4;
    d.Print();


    blend("r255 g240 b155"_C, "r15 g255 b10 a10"_C); // 用户自定义字面量
    Watt capacity = 1024_w;

    return 0;
}