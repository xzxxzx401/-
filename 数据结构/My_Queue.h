#ifndef _HEADERNAME_Myqueue
#define _HEADERNAME_Myqueue

#include "My_List.h"
//��������������
template <typename T> class My_Queue:public My_List<typename T>
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
