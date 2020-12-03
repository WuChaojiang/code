#include "MyData.h"
#include <iostream>

MyData& MyData::operator[](initializer_list<int> l)
{
    for (auto i = l.begin(); i < l.end(); i++)
    {
        idx.push_back(*i);
    }
    return *this;
}

MyData& MyData::operator=(int v) {
    if (idx.empty() != true) {
        for (auto i = idx.begin(); i != idx.end(); i++)
        {
            d.resize((*i > d.size()) ? *i : d.size());   // 每次都会resize，大的话调整，相同的话，底层是不会调整的。
            d[*i - 1] = v;
        }
        idx.clear();
    }
    return *this;
}

void MyData::Print() {
    for(auto i = d.begin(); i != d.end(); ++i) {
        cout << *i << " ";
    }
    cout << endl;
}
