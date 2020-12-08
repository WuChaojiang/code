_Pragma("once")
#include <iostream>
using namespace std;

namespace ns1 {
    void ns_fun1() {
        cout << "ns1::ns_fun1(): " << __func__ << endl;
    }
}

void ns_fun1() {
    cout <<  "::ns_fun1(): " << __func__ << endl;
}

using fun1_alias = void (*)();

void test_ns_func() {
    using ns1::ns_fun1;
    ns_fun1();
    ::ns_fun1();

    fun1_alias alias_ns1_ns_fun1 = ns1::ns_fun1;
    fun1_alias alias_ns_fun1 = ::ns_fun1;

    alias_ns1_ns_fun1();
    alias_ns_fun1();
}

