#include "mutating.h"
#include <iostream>
#include <algorithm>
using namespace std;

struct Print
{
    void operator()(int x)
    {
        std::cout << x << ' ';
    }
};

void testTemplate2()
{
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8};
    const int length = sizeof(a) / sizeof(int);
    std::for_each(a, a + length, Print());
    std::cout << std::endl;
}

void testComplex()
{
    Complex<int> c1(1, 2);
    Complex<int> c2(3, 4);

    Complex<int> c = c1 + c2;

    std::cout << c;
}

void testFunctionObject()
{
    {

        testTemplate2();
        testComplex();
    }
}