#pragma once
#include <iostream>
#include <vector>

class A
{
    public:
    void testForeach() 
    {
        auto i = 1;
        auto l = 42LL;

        std::vector<int> iv = {1,2,3,4,5,6};

        for(auto i : iv) 
        {
            std::cout << i << std::endl;
        }
    }
};

class B
{
    public:
    virtual void f(int) { std::cout << "B::f" << std::endl;}
};

class D : public B
{
    public:
    virtual void f(int) override final { std::cout << "D::f" << std::endl; }
};

class F : public D
{
    public:
    void f(short)  { std::cout << "F:f" << std::endl; }    

    // virtual void f(int) override { std::cout << "F::f" << std::endl; }
};
