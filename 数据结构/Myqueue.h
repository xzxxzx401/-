#ifndef _HEADERNAME_Myqueue
#define _HEADERNAME_Myqueue

#include "Mylist.h"
//由链表派生队列
template <typename T> class Myqueue:public Mylist<typename T>
{
	public:
	//入队
	T push(T const _temp) { return InsertAsLast(_temp)->_data; }
	//出队
	T pop() { return RemoveFirst(); }
	//返回队首元素的引用
	T& front(){ return first()->_data; }

	private:

};


#endif // !_HEADERNAME_Myqueue#pragma once
