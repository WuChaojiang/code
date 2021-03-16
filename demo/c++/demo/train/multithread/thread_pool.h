_Pragma("once")
#include <functional>
#include <vector>
#include <queue>
#include <thread>
#include <atomic>
#include <condition_variable>
#include <future>
#include <stdexcept>

namespace train
{
    const int MAX_TREAD_NUM = 256;

    class ThreadPool
    {
        // 线程池
        std::vector<std::thread> pool;

        // 任务列表
        using Task = std::function<void()>;
        std::queue<Task> tasks;

        // 同步
        std::mutex m_lock;

        // 条件阻塞
        std::condition_variable cv_task;

        // 是否关闭提交
        std::atomic<bool> stoped;

        // 空闲线程数量
        std::atomic<int> idlThreadNum;

    public:
        ThreadPool(unsigned size = 4);
    };
}
