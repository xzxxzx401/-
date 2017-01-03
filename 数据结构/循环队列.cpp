#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include "My_Vector.h"
#include "My_Stack.h"
#include "My_List.h"
#include "My_Queue.h"
#include <string>
using namespace std;

struct squeue{
	const int max_size=15;
	int que[15];
	int front=0;
	int rear=0;

	int squeue_size()
	{
		return (rear-front+max_size)%max_size;
	}
	int squeue_push(int t)
	{
		if((rear+1)%max_size==front) return -1;
		que[rear]=t;
		rear=(rear+1)%max_size;
		return t;
	}
	int squeue_pop()
	{
		if(front==rear) return -1;
		int re=que[front];
		front=(front+1)%max_size;
		return re;
	}
	int squeue_front()
	{
		if(front==rear) return -1;
		return que[front];
	}
	bool squeue_empty()
	{
		return front==rear;
	}
};

int main()
{
	squeue que;
	for(int i=0;i<20;i++) que.squeue_push(i);
	cout<<que.squeue_front()<<endl;
	while(!que.squeue_empty())
	{
		cout<<que.squeue_pop()<<' ';
	}
	system("pause");
}