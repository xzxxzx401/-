#ifndef _HEADERNAME_Mystack
#define _HEADERNAME_Mystack
#include "My_Vector.h"
//��������ջ
template <typename T> class My_Stack:public My_Vector<typename T>
{
	public:
	//��ջ
	T& push(T const _temp) { return push_back(_temp); }
	//��ջ
	T pop() { return pop_back(); }
	//����ջ��Ԫ�ص�����
	T& top(){ return (this*)[size-1]; }
	
	private:

};
#endif
