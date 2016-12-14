#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <list>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>
#include <stack>
#include <sstream>
#define HEAD_NODE -oo;
using namespace std;

const int oo=0x3f3f3f3f;
typedef long long LL;
struct node{
	int data=0;
	node *next=NULL;
};
void make_node(node* &last,int data)//添加节点
{
	last->next=(node*) malloc(sizeof(node)*1);
	last=last->next;

	last->data=data;
	last->next=NULL;
}
void init(int n,node* &head)//初始化报数队列
{
	head=(node*) malloc(sizeof(node)*1);
	head->data=1;
	head->next=NULL;
	node *pa=head;
	for(int i=2;i<=n;i++) make_node(pa,i);
	pa->next=head;
}
void moni(int n,int y,int x)//模拟出队
{
	node *head=NULL;
	init(n,head);//构造循环单链表
	node *now=head;
	node *pre=head;
	for(int i=0;i<x-1;i++) now=now->next;//now指针指向开始报数的人
	for(int i=0;i<x-2;i++) pre=pre->next;//pre指针指向前驱
	while(x==1&&pre->next!=now)  pre=pre->next;//特殊处理now和pre指向相同元素的情况
	int res,rs_check;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<y-1;j++)
		{
			now=now->next;
			pre=pre->next;
		}
		cout<<now->data<<"号出队"<<endl;

		if(now==head) head=head->next;
		now=now->next;
		pre->next=now;
	}
}
void check(int n,int y,int x)//公式计算
{
	//y--;
	int res=0;
	for(int i=2;i<=n;i++)
	{
		res=(res+y)%i;
	}
	cout<<"check最后出队的人是"<<(x+res-1)%n+1<<endl;
}
int main()
{
	int n,x,y;//n人数，从x开始数，数到y执行任务
	for(cout<<"请输入n x y:(n人数，从x开始数，数到y执行任务)"<<endl,cin>>n>>x>>y;
		x==0||y==0||n==0;
		cout<<"输入非法！！请输入n x y:(n人数，从x开始数，数到y执行任务)"<<endl,cin>>n>>x>>y);

	moni(n,x,y);
	check(n,x,y);
	system("pause");
}