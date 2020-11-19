#include "BaseFeature.h"
#include <algorithm>

void A::testForeach()
{
    auto i = 1;
    auto l = 42LL;

    std::vector<int> iv = {1, 2, 3, 4, 5, 6};

    for (auto i : iv)
    {
        std::cout << i << " ";
    }

    std::cout << std::endl;
}

void A::testUniquePtr()
{
    std::unique_ptr<int> p1(new int(42));
    std::unique_ptr<int> p2 = std::move(p1);

    if (p1)
    {
        foo(p1.get());
    }

    if (p2)
    {
        foo(p2.get());
    }
}

void A::testSharePtr()
{
    // std::shared_ptr<int> p1(new int(42));
    auto p11 = std::make_shared<int>(42);
    std::shared_ptr<int> p2(p11);

    // p2.reset();  // reset()表示将nullptr交给p2智能指针对象管理，而对原来内存块计数减1

    if (!p2.unique())
    {
    }

    bar(p11);
    foo(p2.get());
}

void A::testWeakPtr()
{
    auto p = std::make_shared<int>(42);

    std::weak_ptr<int> wp = p;

    {
        auto sp = wp.lock(); // 只能使用lock获得共享对象
        std::cout << "test weak_ptr: " << *sp.get() << std::endl;
    }

    
    std::shared_ptr<int> p2 = p;
    p.reset(); // 对原有对象进行引数减1操作

    if (wp.expired())
    {
        std::cout << "weak_ptr is expired" << std::endl;
    }
    else
    {
        std::cout << "weak_ptr is not expired" << std::endl;
    }
    
}

void A::foo(int *p)
{
    std::cout << "ptr content is: " << *p << std::endl;
}

void A::bar(std::shared_ptr<int> p)
{
    ++(*p);
}

Options A::getOptions(int num)
{
    if (num > 45)
    {
        return Options::All;
    }
    else if (num > 20)
    {
        return Options::One;
    }
    else
    {
        return Options::None;
    }
}

void A::testLoopReference()
{
    std::shared_ptr<AStruct> spA(new AStruct);
    std::shared_ptr<BStruct> spB(new BStruct);

    spA->bPtr = spB;
    spB->aPtr = spA;
}

void A::testLambda()
{
    std::vector<int> v;
    v.push_back(1);
    v.push_back(3);
    v.push_back(4);
    v.push_back(6);

    std::cout << "lambda: ";
    int x;
    std::for_each(v.begin(), v.end(), [&x](int n){
        x = n;
        std::cout << x << " ";
    });

    auto is_odd = [](int n) { return n % 2 == 1; };
    auto pos = std::find_if(std::begin(v), std::end(v), is_odd);
    if (pos != std::end(v)) 
    {
        std::cout << "" << *pos << std::endl;
    }
}

void A::testBeginEnd()
{
    
}