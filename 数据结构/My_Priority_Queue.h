#ifndef PRIORITY_QUEUE
#define PRIORITY_QUEUE
#include"My_Vector.h"
#include"My_P_Queue.h"

#define lchild(i) (i<<1|1)
#define rchild(i) ((i+1)<<1)
#define parent(i) ((i-1)>>1)

template <typename T> class Priority_Queue :public My_P_Queue<T>,protected My_Vector<T>
{
	protected:
	int PushUp(int n,int head=0)//参数是待pushup元素的rank与上滤最大高度,上滤
	{
		T _temp=_elem[n];
		int p;
		while((p = parent(n))>=head)
		{
			if(_temp<_elem[p])
			{
				_elem[n]=_elem[p];
				n=p;
			}
			else break;
		}
		_elem[n]=_temp;
		return n;
	}
	int PushDown(int n, int tail)//参数是待pushdown元素的rank与下滤最大深度,下滤
	{
		T _temp=_elem[n];
		int p;
		while(1)
		{
			if(lchild(n)<tail)
			{
				p=(_elem[n]<=_elem[lchild(n)] ? n : lchild(n));
				if(rchild(n)<tail) p=(_elem[p]<=_elem[rchild(n)] ? p : rchild(n));
				if(p==n) break;
			}
			else break;
			T __t=_elem[n];_elem[n]=_elem[p];_elem[p]=__t;
			n=p;
		}
		_elem[n]=_temp;
		return n;
	}

	public:
	void push(T _e)
	{
		My_Vector::push_back(_e);
		PushUp(_size-1);
	}
	const T top() { return _elem[0]; }
	T pop()
	{
		T _temp=_elem[0];
		_elem[0]=_elem[--_size];
		PushDown(0,_size);
		return _temp;
	}

};

#endif // !PRIORITY_QUEUE#pragma once
