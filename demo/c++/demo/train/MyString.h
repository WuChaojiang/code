_Pragma("once")
#include <string>
#include <iostream>

    class MyString
{
public:
    MyString();
    MyString(char *p);
    MyString(const MyString &rhs);
    MyString &operator=(const MyString &rhs);

    ~MyString();

private:
    char *p { nullptr };
};