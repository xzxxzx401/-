#ifndef _HEADERNAME_Mystack
#define _HEADERNAME_Mystack
#include "My_Vector.h"
//向量派生栈
template <typename T> class My_Stack:public My_Vector<typename T>
{
	public:
	//入栈
	T& push(T const _temp) { return push_back(_temp); }
	//出栈
	T pop() { return pop_back(); }
	//返回栈顶元素的引用
	T& top(){ return (this*)[size-1]; }
	
	private:

};
#endif
