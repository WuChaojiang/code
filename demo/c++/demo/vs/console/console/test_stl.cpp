#include "StdAfx.h"
#include "test_stl.h"
#include <algorithm>
#include <functional>

CTestSTL::CTestSTL(void)
{
}


CTestSTL::~CTestSTL(void)
{
}

void CTestSTL::test()
{
	test_remove_copy();
	test_binder2nd();

}

void CTestSTL::test_remove_copy()
{
	vector<int> v;
	v.push_back(7);
	v.push_back(2);
	v.push_back(5);
	v.push_back(4);
	v.push_back(1);

	print<decltype(v), int>(v);

	auto iter_rci = remove_if(v.begin(), v.end(), [](int i){
		return i % 2 == 0 ? 0 : 1;
	});

	std::for_each(v.begin(), iter_rci, [](int item){
		std::cout << item << " ";
	});
	std::cout << std::endl;

	auto iter = remove(v.begin(), v.end(), 4);
	int count = iter - v.begin();

	std::for_each(v.begin(), iter, [](int item){
		std::cout << item << " ";
	});
	std::cout << std::endl;

	vector<int> v2(v.size());

	remove_copy_if(v.begin(), v.end(), v2.begin(), [](int i){
		return i % 2 == 0 ? false : true;
	});


	// 移除所有小于100的元素
	int a[] = {1, 2, 100, 200};
	std::vector< int> arr(a, a + 4);
	auto n = std::remove_if(arr.begin(), arr.end(), std::binder2nd<std::less<int>>(std::less<int>(), 100)); // 说明大于100的往前，返回更新数据的下个数据
	std::for_each(arr.begin(), arr.end(), [](int i){
		std::cout << i << " ";
	});
	std::cout << endl;

	iter = arr.erase(
		std::remove_if(arr.begin(), arr.end(), std::bind2nd(std::less<int>(), 100)),
		arr.end()); // 将无效数据去掉

	std::for_each(arr.begin(), iter, [](int item){
		std::cout << item << " ";
	});
	std::cout << std::endl;


	vector<int> v3;
	v3.push_back(4);
	v3.push_back(5);
	v3.push_back(6);
	v3.push_back(1);

	for_each(v3.begin(), v3.end(), [](int n){
		cout << n << " ";
	});


	//std::bind2nd(std::less<int>(), 100);
}

void CTestSTL::test_binder2nd()
{
	// 把小于100的数据排除掉
	int a[] = {1,2, 100, 200};
	std::vector<int> arr(a, a+4);
	//arr.erase(
	//	std::remove_if(
	//		arr.begin(), 
	//		arr.end(),
	//		std::bind2nd(std::less<int>(), 100)), 
	//	arr.end());

	//// 去掉大于100的数据
	//arr.erase(
	//	std::remove_if(
	//		arr.begin(), 
	//		arr.end(),
	//		std::bind1st(std::less<int>(), 100)), 
	//	arr.end());

	//// 去掉大于100的数据
	//arr.erase(
	//	std::remove_if(
	//		arr.begin(),
	//		arr.end(),
	//		std::bind2nd(std::greater<int>(), 100)),
	//	arr.end());


	// 去掉小于100的数据
	arr.erase(
		std::remove_if(
			arr.begin(),
			arr.end(),
			std::bind1st(std::greater<int>(), 100)),
		arr.end());

	br();
	for(auto item : arr){
		cout << item << " ";
	};
	br();
}
