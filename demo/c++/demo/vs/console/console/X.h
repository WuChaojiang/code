#pragma once
#include <iostream>
#include <string>
using namespace std;

class X
{
public:
	X();
	~X();

	void* operator new(size_t size, string str);
	void operator delete(void* pointer);

private:
	int num;
};
