#include "Container.h"
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void Container::testVector()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(2);

    for(auto it = v.begin(); it != v.end(); ++it) 
    {
        it = v.erase(it);
        --it;
    }

    std::cout << "v.size() = " << v.size();

    // v.clear();
}

void Container::testMismatch()
{
    std::vector<int> v1;
    v1.push_back(1);
    v1.push_back(0);
    v1.push_back(6);

    std::vector<int> v2;
    v2.push_back(1);
    v2.push_back(0);
    v2.push_back(6);
    v2.push_back(7);

    std::cout << "\ntest mismatch: " << std::endl;
    auto iter = std::mismatch(std::begin(v1), std::end(v1), std::begin(v2));
    if (iter.first == v1.end() && iter.second == v1.end())
    {
        std::cout << "same";
    }
    else
    {
        std::cout << "not same: " << *iter.first << " - " << *iter.second;
    }
}

void Container::testFind()
{
    std::cout << "testFind: ";
    std::string wucj("Wuchaojiang");
    std::vector<std::string> vstr;
    vstr.push_back("Yulibing");
    vstr.push_back("Taozhijia");
    vstr.push_back(wucj);

    auto iter = std::find(vstr.begin(), vstr.end(), wucj);
    if (iter != vstr.end())
        std::cout << "find " << wucj;
    else
        std::cout << "not find " << wucj;
}
