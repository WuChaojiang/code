_Pragma("once")

#include <iostream>
using namespace std;

class Copyable
{
public:
    Copyable() {
        cout << "Copyable default construct." << endl;
    }
    Copyable(const Copyable &o) {
        cout << "Copied" << endl;
    }
};

Copyable returnRvalue() {
    return Copyable(); // 在return时，发生拷贝构造函数
}

// 当编译器关闭返回值优化，-fno-elide-constructors，就会严格按照C++标准执行而没有优化过程
void acceptVal(Copyable a) {} // 实参输入时，发生拷贝构造函数
void acceptRef(const Copyable &a) {} // 即常量左值引用能够绑定一个右值，可以减少一次拷贝


void testCopy() {
    cout << "pass by value: " << endl;
    acceptVal(returnRvalue());  
    cout << "pass by reference: " << endl;
    acceptRef(returnRvalue());
}