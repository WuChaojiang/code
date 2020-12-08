// Substitution failure is not a error

_Pragma("once")
#include <iostream>
    using namespace std;

struct Test
{
    typedef int foo;
};

template <typename T>
void f(typename T::foo)
{
    cout << "void f(typename T::foo): " << endl;
}

template <typename T>
void f(T)
{
    cout << "void f(T) : " << endl;
}

void test_sfinae()
{
    f<Test>(10);
    f<int>(10);
}

template <int I>
struct AA
{
    AA()
    {
        cout << "template <int I> struct A" << endl;
    }
};

char xxx(int)
{
    cout << "char xxx(int)" << endl;
    return 'a';
}

char xxx(float)
{
    cout << "char xxx(float)" << endl;
    return 'a';
}

template <class T>
AA<sizeof(xxx((T)0))> ff(T)
{
    cout << "template <class T> A<sizeof(xxx((T)0))> f(T)" << endl;
    // return T(1.0);
}

template <int i>
class XX
{
public:
    XX()
    {
        cout << "--------------template<int i> class X" << i << std::endl;
    }
};
