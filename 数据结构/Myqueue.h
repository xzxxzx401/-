#ifndef _HEADERNAME_Myqueue
#define _HEADERNAME_Myqueue

#include "Mylist.h"
//��������������
template <typename T> class Myqueue:public Mylist<typename T>
{
	public:
	//���
	T push(T const _temp) { return InsertAsLast(_temp)->_data; }
	//����
	T pop() { return RemoveFirst(); }
	//���ض���Ԫ�ص�����
	T& front(){ return first()->_data; }

	private:

};


#endif // !_HEADERNAME_Myqueue#pragma once
