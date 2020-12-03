#include "has_ptr_mem.h"
#include <iostream>
#include <type_traits>
using namespace std;

HasPtrMem::HasPtrMem() :d(new int(3)) {
    cout << "HasPtrMem Construct: "  << ++n_cstr << endl;
}

HasPtrMem::HasPtrMem(const HasPtrMem &h) : d(new int(*h.d)) {
    cout << "HasPtrMem Copy construct: " << ++n_cptr << endl;
}

HasPtrMem::HasPtrMem(HasPtrMem &&h) : d(h.d) {
    h.d = nullptr;
    cout << "HasPtrMem Move construct: " << ++n_mvtr << endl;
}

HasPtrMem::~HasPtrMem() {
    delete d;
    cout << "HasPtrMem Destruct: " << ++n_dstr << endl;
}

int HasPtrMem::n_cstr = 0;
int HasPtrMem::n_dstr = 0;
int HasPtrMem::n_cptr = 0;
int HasPtrMem::n_mvtr = 0;

HasPtrMem GetTemp() {
    HasPtrMem h;
    cout << "HasPtrMem Resource from " << __func__ << ": " << hex << h.d << endl;
    return h;
}

void JudgeReferenceType() {
    std::cout << std::boolalpha;
    std::cout << std::is_rvalue_reference<HasPtrMem>::value << '\n';
    std::cout << std::is_rvalue_reference<HasPtrMem&>::value << '\n';
    std::cout << std::is_rvalue_reference<HasPtrMem&&>::value << '\n';
    std::cout << std::is_lvalue_reference<int>::value << '\n';
    std::cout << std::is_reference<int&>::value << '\n';
    std::cout << std::is_rvalue_reference<int&&>::value << '\n';
}