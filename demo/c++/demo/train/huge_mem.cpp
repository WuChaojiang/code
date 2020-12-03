#include "huge_mem.h"
#include <iostream>
using namespace std;

HugeMem::HugeMem(int size) : sz(size > 0 ? size : 1)
{
    c = new int[sz];
    cout << "HugeMem cstr" << endl;
}

HugeMem::HugeMem(HugeMem &&rhs) : c(rhs.c),
                                  sz(rhs.sz)
{
    cout << "HugeMem mvtr" << endl;
    rhs.c = nullptr;
}

HugeMem::~HugeMem()
{
    cout << "HugeMem destruct" << endl;
    delete[] c;
}

Moveable::Moveable() : i(new int(3)),
                       h(1024)
{
    cout << "Moveable ctr" << endl;
}

Moveable::Moveable(Moveable &&rhs) : i(rhs.i),
                                     h(move(rhs.h))
{
    cout << "Moveable mvtr" << endl;
    rhs.i = nullptr;
}

Moveable::~Moveable() {
    cout << "Moveable destruct" << endl;
    delete i; 
}

Moveable GetMoveableTemp() {
    Moveable tmp = Moveable();
    cout << hex << "Huge Mem from " << __func__ 
    << " @" << tmp.h.c << endl;

    return tmp;
}

Maythrow::Maythrow() {}
Maythrow::Maythrow(const Maythrow &) {
    cout << "Maythrow copy constructor." << endl;
}
Maythrow::Maythrow(Maythrow &&) {
    cout << "Maythrow move constructor." << endl;
}

Nothrow::Nothrow() {}
Nothrow::Nothrow(const Nothrow &) {
    cout << "Nothrow copy constructor." << endl;
}
Nothrow::Nothrow(Nothrow &&) noexcept {
    cout << "Nothrow" << endl;
}