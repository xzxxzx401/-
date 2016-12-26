#ifndef MY_P_QUEUE
#define MY_P_QUEUE

template <typename T> class My_P_Queue
{
	public:
	virtual void push(T)=0;
	virtual const T top()=0;
	virtual T pop()=0;

};

#endif // !MY_P_QUEUE#pragma once
