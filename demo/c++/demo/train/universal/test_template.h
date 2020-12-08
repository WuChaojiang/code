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
