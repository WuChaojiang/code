#include "MyString.h"
#include <string.h>

MyString::MyString() 
{
    p = new char[1];
    *p = '\0';
    std::cout << "default construct" << std::endl;
}

MyString::MyString(char p0[])
{
    if (p0 != nullptr)
    {
        int len = strlen(p0);
        p = new char[len + 1];
        memset(p, 0, len + 1);
        strcpy(p, p0);

        std::cout << "cstr：" << p << std::endl;
    } 
    else
    {
        p = new char[1];
        *p = '\0';
    }
    
    std::cout << "pointer construct" << std::endl;
}

MyString::MyString(const MyString &rhs)
{
    std::cout << "copy construct" << std::endl;

    if (rhs.p != nullptr)
    {
        int len = strlen(rhs.p);

        p = new char[len + 1];
        memset(p, 0, len + 1);
        strcpy_s(p, len, rhs.p);

        std::cout << "cpstr" << p << std::endl;
    }
}

MyString &MyString::operator=(const MyString &rhs)
{
    std::cout << "operator assignment" << std::endl;

    if (this == &rhs)
    {
        return *this;
    }

    if (rhs.p != nullptr)
    {
        int len = strlen(rhs.p);
        p = new char[len + 1];
        memset(p, 0, len + 1);
        strcpy_s(p, len, rhs.p);
    }

    return *this;
}

MyString::~MyString() 
{
    if (p != nullptr) 
    {
        delete [] p;
        p = nullptr;
    }

}