#include "StdAfx.h"
#include "X.h"


X::X(void)
{
	cout << "X's constructor" << endl;
}


X::~X(void)
{
	cout << "X's destructor" << endl;
}

void* X::operator new(size_t size, string str) 
{											   
	cout << "operator new size " << size << " with string " << str << endl;
	return ::operator new(size);
}

void X::operator delete(void *pointer)
{
	cout << "operator delete" << endl;
	::operator delete(pointer);
}