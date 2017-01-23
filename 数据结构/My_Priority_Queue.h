#ifndef MY_PRIORITY_QUEUE
#define MY_PRIORITY_QUEUE
#include"My_Vector.h"
#include"My_P_Queue.h"

#define lchild(i) (i<<1|1)
#define rchild(i) ((i+1)<<1)
#define parent(i) ((i-1)>>1)

template <typename T> class My_Priority_Queue :protected My_P_Queue<T>,protected My_Vector<T>
{
	protected:
	int PushUp(int n,int head=0)//上滤,参数是待pushup元素的rank与上滤最大高度
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
	int PushDown(int n, int tail)//下滤,参数是待pushdown元素的rank与下滤最大深度
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
	void heapify(int start, int tail)//从下往上的下滤,O(n)
	{
		int LastParent=parent(tail-1);
		for(int i=LastParent;i>=start;i--) PushDown(i, tail);
	}
	public:
	My_Priority_Queue(){}
	My_Priority_Queue(const T* A,int start,int tail)//[start,tail)
	{
		My_Vector<T>::copyFrom(A, start, tail);
		heapify(start, tail);
	}
	My_Priority_Queue(My_Vector<T> Vec)//未测试！！
	{
		My_Vector(vec);
		heapify(0, _size);
	}
	const T top() { return (_elem[0]); }
	void push(T _e)
	{
		My_Vector<T>::push_back(_e);
		PushUp(_size-1);
	}
	T pop()
	{
		T _temp=_elem[0];
		_elem[0]=_elem[--_size];
		PushDown(0,_size);
		return _temp;
	}
	bool empty() { return My_Vector<T>::empty(); }
};

#endif // !PRIORITY_QUEUE#pragma once
