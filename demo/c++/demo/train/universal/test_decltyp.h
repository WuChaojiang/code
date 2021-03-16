_Pragma("once")
#include <iostream>
#include <type_traits>

////////////////////////////////////////
//
// int (*)() 表示一个函数指针
// (*pf())() 表示一个函数，没有参数，而函数名是一个
//
//
//
////////////////////////////////////////

//*************************
/* 
int a；
int fun(int i)；
int (*pf)(int i);
则可以直接赋值：
pf = fun；
调用：
a = pf(1); //等价与 a = fun(1);
*/
 /////////////////////////////


// 该函数的等价式
// typedef int (*pa)();
// typedef pa (*pb)();
// pb pfex() { return nullptr; }

// pb pf()

int (*(*pf())())() { 
    return nullptr;
}

int (*pf2())() {
    return nullptr;
}

auto pf1() -> auto(*)() -> int(*)() {
    return nullptr;
}

int test_pp() {
    return 1;
}

int func_test001(int i) {
    std::cout << i << std::endl; 
    return i;
}

int (*ptr_ft001)(int);



void test_is_function_same() {
    using fuc_p = int(*(*()))();
    
    std::cout << std::is_same<decltype(pf), decltype(pf1)>::value << std::endl;
    std::cout << std::is_same<decltype(pf2), decltype(pf)>::value << std::endl;

    ptr_ft001 = func_test001;
    ptr_ft001(1);

}