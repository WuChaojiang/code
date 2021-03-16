_Pragma("once")
#include <ostream>
using namespace std;

void testFunctionObject();

template <typename T>
class Complex {
    
    //友元函数实现运算符重载
    friend ostream& operator<<(ostream &out, Complex &c)
    {
        out<<c.a << " + " << c.b << "i";
        return out;
    }
    
public:
    Complex(T a, T b)
    {
        this->a = a;
        this->b = b;
    }
    
    //运算符重载+
    Complex operator+(Complex &c)
    {
        Complex temp(this->a + c.a, this->b + c.b);
        return temp;
    }
    
    //普通加法函数
    Complex myAdd(Complex &c1, Complex &c2)
    {
        Complex temp(c1.a + c2.a, c1.b + c2.b);
        return temp;
    }
    
private:
    T a;
    T b;
};

