#pragma once
#include "base_static.h"
class CDeriveStaticA : public CBaseStatic<CDeriveStaticA>
{
public:
	CDeriveStaticA(void);
	~CDeriveStaticA(void);

	int count() { return getCount();}
	void set(int count) { setCount(count);}
};


class CDeriveStaticB : public CBaseStatic<CDeriveStaticB>
{
public:
	CDeriveStaticB(void);
	~CDeriveStaticB(void);

	int count() { return getCount();}
	void set(int count) { setCount(count);}
};
