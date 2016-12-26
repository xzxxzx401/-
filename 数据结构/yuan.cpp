#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<ctime>
#include"My_Priority_Queue.h"

using namespace std;

int main()
{
	Priority_Queue<int> pq;
	for(int i=10;i>=0;i--)
	{
		pq.push(i);
		cout<<pq.top()<<' ';
	}
	cout<<endl;
	for(int i=0;i<5;i++)
	{
		cout<<pq.pop()<<' ';
	}
	cout<<pq.top()<<endl;

	system("pause");
	return 0;


}