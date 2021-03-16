#include "thread_pool.h"

namespace train 
{
    ThreadPool::ThreadPool(unsigned size /* = 4 */) {
        idlThreadNum = size < 1 ? 1: size;
        for (size_t i = 0; i < idlThreadNum; i++)
        {
            pool.emplace_back(
                [this] { // 工作线程函数
                    while (!this->stoped)
                    {
                        
                        std::function<void()> task;
                    }
                    
                }

            );
        }
        
    }
}
