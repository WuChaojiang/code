// console.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "X.h"
#include "derive_static.h"
#include <iostream>
#include "test_stl.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	//X *p = new("A new class") X;
	//delete p;

	CDeriveStaticA a;
	a.set(1);

	CDeriveStaticB b;
	b.set(2);

	cout << "a count is: " << a.getCount() << endl;
	cout << "b count is: " << b.getCount() << endl;


	// test stl
	CTestSTL testSTL;
	testSTL.test();

	getchar();
	return 0;
}

