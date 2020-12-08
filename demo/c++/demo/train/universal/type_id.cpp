#include "type_id.h"

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

