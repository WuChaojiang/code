_Pragma("once")
#include <iostream>
#include <stdexcept>

double SumOfFloat(int count, ...);
void test_demo();


void Printf(const char *s);

template<typename T, typename... Args>
void Printf(const char* s, T value, Args... args) {
    while(*s) {
        if (*s == '%' && *++s != '%')  {
            std::cout << value;
            return Printf(++s, args...);
        }
        std::cout << *s++;
    }
    throw std::runtime_error("extra arguments provided to Printf");
}