#include "type_id.h"
#include <type_traits>
#include <map>
#include <vector>
#include <string>

void test_type_id() {
    White a;
    Black b;

    std::cout << "void test_type_id()" << std::endl;
    std::cout << typeid(a).name() << std::endl;
    std::cout << typeid(b).name() << std::endl;

    White c;

    bool a_b_sametype = (typeid(a).hash_code() == typeid(b).hash_code());

    bool a_c_sametype = (typeid(a).hash_code() == typeid(c).hash_code());

    std::cout << "Same type? " << std::endl;
    std::cout << "A and B? " << (int)a_b_sametype << std::endl;
    std::cout << "A and C? " << (int)a_c_sametype << std::endl;
}

// ***********************************************************
//
// 推导出变量的类型，decltype以普通的表达式为参数，返回该表达式的类型
// 与auto一样，都是类型指示符，都在编译时进行的。decltype可以来定义另外一个变量
//
// 典型的应用是decltype与typdef/using合用
// 
// ***********************************************************


void test_decltype() {
    int i;
    decltype(i) j = 0;
    std::cout << typeid(j).name() << std::endl;

    float a;
    double b;
    decltype(a + b) c;
    std::cout << typeid(c).name() << std::endl;

    using size_t = decltype(sizeof(0));
    using ptrdiff_t = decltype((int*)0 - (int*)0);
    std::cout << typeid(ptrdiff_t).name() << std::endl;
}

void test_template_decltyp() {
    int a = 3;
    long b = 5;
    float c = 1.0f, d = 2.3f;

    long e;
    float f;
    sum(a, b, e);   // s的类型被推导为long
    sum(c, d, f);   // s的类型被推导为float
}

int hash(char*); 

double func(int a) {
    return 0.0;
}

typedef double (*func_ptr)(int);
typedef double (&func_ref)();

void test_decltype_2() {

    std::map<char*, decltype(hash(nullptr))> dict_key; // 存放字符串和hash值
    using TypeA = std::result_of<decltype(func)&(int)>::type;  // 知道输入参数，但是并不知道返回类型，在泛型编程中使用
    using TypeB = std::result_of<func_ref()>::type;

    std::cout << "TypeA: " << std::is_same<double, TypeA>::value << std::endl;
    std::cout << "TypeB: " << std::is_same<double, TypeB>::value << std::endl;
}

void Overloaded(int) {}
// void Overloaded(char) {}
int && RvalRef() { return std::move(1); }

void test_for() 
{	std::vector<std::string> v = {"Hello", "World"};
	for (auto &e : v)
	{
        e.append("haha");
	}

    for(auto e : v) {
        std::cout << e << std::endl;
    }
}

void test_decltype_rool() {
    // int i = 4;
    // int arr[5] = {0};
    // int *ptr = arr;

    // struct S {double d; } s;

    // const bool Func(int);

    // // 规则1：单个标记符表达式以及访问类成员，推导为本类型
    // decltype(arr) var1; // int[5]
    // decltype(ptr) var2; // int*
    // decltype(s.d) var4; // double
    // decltype(Overloaded) var5;
    
    // std::cout << "The type name of decltype(Overloaded) is: " << typeid(var5).name() << std::endl;
    // // std::cout << "decltype(Overloaded): " << std::is_same<void(), var5>::value << std::endl;


    // // 规则2：将亡值，推导为类型的右值引用
    // decltype(RvalRef()) var6 = 1;

    // // 规则3：左值，推导为类型的引用
    // decltype(true ? i : i) var7 = i;
    // decltype((i)) var8 = i;
    // decltype(++i) var9 = i;
    // decltype(arr[3]) var10 = i;
    // decltype(*ptr) var11 = i;
    // decltype("lval") var12 = "lval";

    // // 规则4：以上都不是，推导为本类型
    // decltype() var13;
    // decltype(i++) var14;
    // decltype((Func(1))) var15;

    auto a = 3;
    auto b = 4L;
    auto pi = 3.1416;
    
    auto c = Sum_test(b, pi);

    std::cout << c;
}