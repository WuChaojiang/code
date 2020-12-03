_Pragma("once")
#include <cstdlib>
#include <iostream>
using namespace std;

struct Watt {
    unsigned int v;
};

typedef unsigned char uint8;
struct RGBA
{
    uint8 r;
    uint8 g;
    uint8 b;
    uint8 a;
    RGBA(uint8 R, uint8 G, uint8 B, uint8 A = 0);
};

std::ostream & operator << (std::ostream & out, RGBA & col);
RGBA operator "" _C(const char *col, std::size_t n);
Watt operator "" _w(unsigned long long v);
void blend(RGBA && col1, RGBA && col2);