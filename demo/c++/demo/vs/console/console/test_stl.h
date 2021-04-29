#pragma once
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;


class CTestSTL
{
public:
	CTestSTL(void);
	~CTestSTL(void);

	void test();

private:
	void test_remove_copy();
	void test_binder2nd();

	void br() {cout << endl;}

	template<typename T, typename S>
	void print(T t);

	//template<typename T, typename S>
	//void printRange(T s, decltype(s)::iterator it);
};

template<typename T, typename S>
void CTestSTL::print(T t)
{
	std::for_each(t.begin(), t.end(), [](S s){
		std::cout << s << " ";
	});
	std::cout << std::endl;
};

//template<typename T, typename S>
//void CTestSTL::printRange(T s, decltype(s)::iterator it)
//{
//	std::for_each(s.begin(), it, [](S item){
//		std::cout << item << " ";
//	});
//	std::cout << std::endl;
//};
//