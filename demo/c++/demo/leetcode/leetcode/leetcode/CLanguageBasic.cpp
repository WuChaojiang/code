#include "CLanguageBasic.h"
#include <functional>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

void CLanguageBasic::test()
{
	bool** f = new bool* [10];
	bool b1 = false;
	f[0] = &b1;

	testBinder1st();
	testFunction();

}

void CLanguageBasic::testBinder1st()
{
	binder1st<greater<int>> big = bind1st(greater<int>(), 3);
	int number = 4;
	if (big(number))
	{
		cout << "great base number 3 ? " << number << " : No";
	}
	else
	{
		cout << "great base number 3 ? " << number << " : Yes";
	}

	vector<int> a;

}

void CLanguageBasic::testFunction()
{
	vector<int> v;
	v.push_back(10);
	v.push_back(30);
	v.push_back(40);
	v.push_back(20);
	v.push_back(60);
	v.push_back(50);

	sort(v.begin(), v.end(), greater<int>());   //内建关系函数对象（无名 临时对象）greater<int>()   大于
	for_each(v.begin(), v.end(), [](int val) {cout << val << endl; });

	int a[] = { 1,2,3,4,5,6,7,8 };

	const int N = sizeof(a) / sizeof(int);

	std::vector<int> vec(a, a + N);

	int vcount = std::count_if(vec.begin(), vec.end(), std::bind1st(std::less<int>(), 5));

	std::cout << vcount << std::endl;


	vector<int> num1(5);
	vector<int> num2(5);
	num2.push_back(6);

	bool ret = equal(num1.begin(), num1.end(), num2.begin());


	vector<int> vf(20);
	for (unsigned i = 0; i < v.size(); ++i)
		vf[i] = (i + 1) * (i + 3);

	vector<int>::iterator it = find_if(vf.begin(), vf.end(), [](int x)->bool {
		return x % 5 == 0;
		});

	cout << "first can be divided by 5:  " << *it << " index: " << it - vf.begin();

	const char* cszStr[] = { "Hello", "World", "I", "love", "you", "you", "love", "me" };
	vector<string> vstr1(cszStr, cszStr+8);

	int count = std::count(vstr1.begin(), vstr1.end(), "love");
	int count2 = std::count_if(vstr1.begin(), vstr1.end(), [](string x)->bool {
		return -1 != x.find("o");
		});
	

}
