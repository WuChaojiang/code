#include "RGBA.h"

RGBA::RGBA(uint8 R, uint8 G, uint8 B, uint8 A) : r(R), g(G), b(B), a(A) {}

RGBA operator"" _C(const char *col, size_t n)
{
    const char *p = col;
    const char *end = col + n;
    const char *r, *g, *b, *a;

    for (; p != end; ++p)
    {
        if (*p == 'r')
            r = p;
        else if (*p == 'g')
            g = p;
        else if (*p == 'b')
            b = p;
        else if (*p == 'a')
            a = p;
    }

    if ((r == nullptr) || (g == nullptr) || (b == nullptr))
    {
        throw;
    }
    else if (a == nullptr)
    {
        return RGBA(atoi(r + 1), atoi(g + 1), atoi(b + 1));
    }
    else
    {
        return RGBA(atoi(r + 1), atoi(g + 1), atoi(b + 1), atoi(a + 1));
    }
}

Watt operator "" _w(unsigned long long v) {
    return {(unsigned int) v};
}

std::ostream &operator<<(std::ostream &out, RGBA &col) // 最后给cout
{
    return out << "r: " << (int)col.r
               << ", g: " << (int)col.g
               << ", b: " << (int)col.b
               << ", a: " << (int)col.a << endl;
}

void blend(RGBA &&col1, RGBA &&col2)
{
    cout << "blend " << endl
         << col1 << col2 << endl;
}