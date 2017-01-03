#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<ctime>
#include"My_Priority_Queue.h"

using namespace std;

int a[100000];
int main()
{
	clock_t t1,t2;
	for(int i=0;i<100000;i++) a[i]=100001-i;
	t1=clock();
	My_Priority_Queue<int> pq(a,0,100000);
	for(int i=0;!pq.empty();i++)
	{
		if(i%10000==0) cout<<pq.pop()<<' ';
		else pq.pop();
	}
	t2=clock();
	cout<<endl<<"time:"<<t2-t1<<endl;
	t1=clock();
	sort(a,a+100000);
	for(int i=0;i<100000;i+=10000) cout<<a[i]<<' ';
	t2=clock();
	cout<<endl<<"time:"<<t2-t1<<endl;
	system("pause");
	return 0;
}