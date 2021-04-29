_Pragma("once")
#include <atomic>

void do_print_id(int id);
void go();
void test_thread1();


void count1m(int id);
void test_thread_yield();

class TestThread
{
public:
    void test();
    int thead1(int);
    int thead2(int);

private:
    std::atomic<int> _a;
    std::atomic<int> _b;
};