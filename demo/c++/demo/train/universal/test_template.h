_Pragma("once")

#include <string>
#include <map>
#include <iostream>
using namespace std;

template <typename T>
void test_fun1(T t)
{
    std::cout << "test_fun1: " << t << std::endl;
}


template <typename T>
using MapString = std::map<T, char *>;

template <typename T>
class TemplateA
{
public:
    TemplateA(T t1) : t(t1) {}

    T get_value()
    {
        return t;
    }

private:
    T t;
};

template <typename T>
using AliasTemplateA = class TemplateA<T>;

//template <typename T> using AliasTestFun1 = void test_fun1<T>(T);

// 定义了一个非类型参数的模板Fibonacci,每次实例化模板，都将产生一个类
template<long num>
struct Fibonacci{
    const static long val = Fibonacci<num - 1>::val + Fibonacci<num -2>::val;
};

// 通过偏特化定义模板推导的边界条件
template<> struct Fibonacci<2> { const static long val = 1; };
template<> struct Fibonacci<1> { const static long val = 1; };
template<> struct Fibonacci<0> { const static long val = 0; };

void test_template_compile();