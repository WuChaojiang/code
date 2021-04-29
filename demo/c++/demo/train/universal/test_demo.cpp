#include "test_demo.h"
#include <stdio.h>
#include <stdarg.h>
#include <string>


void test_mutable_arg() {
    printf("%f\n", SumOfFloat(3, 1.2f, 3.4, 5.6));

    printf("hello %s\n", std::string("world").c_str());
    // 但是一下方式就不行
    // error infomation: error: 'msg' was not declared in this scope
    // constexpr char char *msg = "hello %s";
    // printf(msg, std::string("world").c_str());

    Printf("hello %s\n", std::string("world").c_str());
}

#include <new>
extern void* p;
class NoStackAlloc
{
    public:
        ~NoStackAlloc() = delete;
};

void test_compile_stack_alloc()
{
    // 这个是在栈上分配，所以肯定会调用析构函数。
    // 既然机构函数没有啦，那就编译失败了
    // NoStackAlloc nsa; 
    
    // new是堆上分配内存，通过delete来删除堆上的内存，可以不调用析构函数
    new (p) NoStackAlloc(); // placement new, 假设p无需调用析构函数
}

void test_demo()
{
    test_mutable_arg();

}

double SumOfFloat(int count, ...)
{
    va_list ap;
    double sum = 0;
    va_start(ap, count);
    for(int i = 0; i < count; ++i)
        sum += va_arg(ap, double);

    va_end(ap);
    return sum;
}

void Printf(const char *s) {
    while(*s) {
        if (*s == '%' && *++s != '%') 
            throw std::runtime_error("invalid format string: missing arguments");
        std::cout << *s++;
    }
}