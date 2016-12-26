#ifndef MY_P_QUEUE
#define MY_P_QUEUE

template <typename T> class My_P_Queue
{
	public:
	virtual void push()=0;
	virtual T top()=0;
	virtual T pop()=0;

};

#endif // !MY_P_QUEUE#pragma once
