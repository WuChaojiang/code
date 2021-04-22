#include "test_template.h"

void test_template_compile() {
    int fib[] = {
        Fibonacci<11>::val, Fibonacci<12>::val,
        Fibonacci<13>::val, Fibonacci<14>::val,
        Fibonacci<15>::val, Fibonacci<16>::val,
    };

    for(int i : fib) {
        std::cout << i << std::endl;
    }
}