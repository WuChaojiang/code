#include "test_thread1.h"
#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <atomic>

using namespace std;

namespace
{
    std::mutex mtx;
    std::condition_variable cv;
    bool ready = false;
    std::atomic<bool> ready_atomic(false);
} // namespace

void do_print_id(int id)
{
    std::unique_lock<std::mutex> lck(mtx);
    while (!ready)
    {
        cv.wait(lck);
    }

    std::cout << "thread " << id << std::endl;
}

void go()
{
    std::unique_lock<std::mutex> lck(mtx);
    ready = true;
    cv.notify_all(); // 唤醒所有线程
}

void test_thread1()
{
    std::thread::id thread_id = std::this_thread::get_id();
    std::thread threads[10];
    for (size_t i = 0; i < 10; i++)
    {
        threads[i] = std::thread(do_print_id, i);
    }

    std::cout << "10 threads ready to race ... " << std::endl;

    go();

    for (auto &th : threads)
    {
        th.join();
    }
}

void count1m(int id) {
    while (!ready_atomic) {
        std::cout << "std::this_thread::yield(): " << id << std::endl;
        std::this_thread::yield();  // 作用，可放于线程函数开始处，
    }

    for (volatile int i = 0; i < 1000000; i++) {
        std::cout << "*";
    }

    std::cout << id;
}

void test_thread_yield() {
    std::thread threads[10];
    std::cout << "race of 10 threads that count to 1 million: ";
    for (size_t i = 0; i < 10; i++)
    {
        threads[i] = std::thread(count1m, i);
    }

    // ready_atomic = true;
    std::this_thread::sleep_for(std::chrono::seconds(5));
    for (auto& th : threads)
    {
        th.join();
    }

    std::cout << std::endl;
}

int TestThread::thead1(int)
{
    int t = 1;
    _a.store(t, std::memory_order_relaxed);
    _b.store(2, std::memory_order_relaxed);
    return 1;
}

int TestThread::thead2(int) 
{
    while(_b.load(std::memory_order_relaxed) != 2);
    std::cout << _a.load(std::memory_order_relaxed) << std::endl;
    return 1;
}

void TestThread::test() 
{
    thread t1(&TestThread::thead1, this, 0);
    thread t2(&TestThread::thead2, this, 0);

    t1.join();
    t2.join();
}