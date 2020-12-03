_Pragma("once")
#include <initializer_list>
#include <vector>

    using namespace std;

class MyData
{
public:
    MyData& operator[](initializer_list<int> l);
    MyData& operator=(int v);
    void Print();

private:
    vector<int> idx; // 辅助数组，用于记录index，即需要修改的对应索引值
    vector<int> d;
};