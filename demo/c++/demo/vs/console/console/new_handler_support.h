#pragma once

template<class t>
class NewHandlerSupport
{
public:
	static new_handler set_new_handler(new_handler p);
	static void * operator new(size_t size);

private:
	static new_handler _current_handler;
};

template<class t>
new_handler NewHandlerSupport<t>::set_new_handler(new_handler p)
{
	new_handler old_handler = _current_handler;
	_current_handler = p;
	return old_handler;
}

template<class t>
void * NewHandlerSupport<t>::operator new(size_t size) 
{
	new_handler global_handler = std::set_new_handler(_current_handler);
	void *memory;
	try
	{
		memory = ::operator new(size);
	}
	catch(std::bad_alloc &) 
	{
		std::set_new_handler(global_handler);
		throw;
	}

	std::set_new_handler(global_handler);

	return memory;
}

template<class t>
new_handler NewHandlerSupport<t>::_current_handler;