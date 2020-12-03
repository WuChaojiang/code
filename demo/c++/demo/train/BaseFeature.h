#pragma once
_Pragma("once")
#include <type_traits>

#include <iostream>
#include <vector>
#include <memory>
#include "TestTemplate.h"


#define LOG(...) {\
    fprintf(stderr, "%s line:%d ", __FILE__, __LINE__);\
    fprintf(stderr, __VA_ARGS__);\
    fprintf(stderr, "\n");\
    }

#define PR(...) printf(__VA_ARGS__)

enum class Options {
    None,
    One,
    All
};


class A
{
    public:
    void testForeach();

    Options getOptions(int num);

    void testUniquePtr();
    void testSharePtr();
    void testWeakPtr();
    void testLoopReference();
    void testLambda();
    void testC99();

    void testPrintf();
    void testMacro(...);
    void testUnicodeLib();
    void testUnicodeLib2(void);
    void testUnicodeLibStream(void);

    void testBeginEnd();
    void testStaticAssert();

    void foo(int *p);
    void bar(std::shared_ptr<int> p);

    void testRawStringLiteral();

    void testRightReference();
    void testDecay(void);

    void testDestructor();
    void testForwarding();

    void testTemplate();
};

class B
{
    public:
    virtual void f(int) { std::cout << "B::f" << std::endl;}
};

class D : public B
{
    public:
    virtual void f(int) override final { std::cout << "D::f" << std::endl; }
};

class F : public D
{
    public:
    void f(short)  { std::cout << "F:f" << std::endl; }    

    // virtual void f(int) override { std::cout << "F::f" << std::endl; }
};

struct AStruct;
struct BStruct;

struct AStruct
{
    // std::shared_ptr<BStruct> bPtr;
    std::weak_ptr<BStruct> bPtr;
    ~AStruct() { std::cout << "AStruct is deleted!" << std::endl; }
};

struct BStruct
{
    // std::shared_ptr<AStruct> aPtr;
    std::weak_ptr<AStruct> aPtr;
    ~BStruct() { std::cout << "BStruct is deleted!" << std::endl; }
};

// 可以根据输入类型，进行不同逻辑判断和操作，感觉模板和std::is_same<T, S>::value，就是绝配。
template<typename T>
void typeCheck(T data)
{
    if (std::is_same<typename std::decay<T>::type, int>::value)
    {
        std::cout << "int type, value is: " << data << std::endl;
    }
    else
    {
        std::cout << "not int type, value is: " << data << std::endl;
    }
}

template<typename T, typename U>
struct decay_equiv : std::is_same<typename std::decay<T>::type, U>::type
{};

struct X
{
    ~X() {}
    void a() {}
};
