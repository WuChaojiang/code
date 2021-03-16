_Pragma("once")
#include <iostream>

class White{};
class Black{};

void test_type_id();
void test_decltype();


template<typename T1, typename T2>
void sum(T1 & t1, T2 & t2, decltype(t1 + t2) & s) {
    s = t1 + t2;
}

void test_decltype_2();
void test_decltype_rool();