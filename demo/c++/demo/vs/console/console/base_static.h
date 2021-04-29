#pragma once

template<typename T>
class CBaseStatic
{
public:
	static void setCount(int count);
	static int getCount();

private:
	static int _count;

};

template<typename T>
int CBaseStatic<T>::getCount()
{
	return _count;
}

template<typename T>
__declspec(selectany) int CBaseStatic<T>::_count;

template<typename T>
void CBaseStatic<T>::setCount(int count)
{
	_count = count;
}

