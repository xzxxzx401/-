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
void make_node(node* &last,int data)//��ӽڵ�
{
	last->next=(node*) malloc(sizeof(node)*1);
	last=last->next;

	last->data=data;
	last->next=NULL;
}
void init(int n,node* &head)//��ʼ����������
{
	head=(node*) malloc(sizeof(node)*1);
	head->data=1;
	head->next=NULL;
	node *pa=head;
	for(int i=2;i<=n;i++) make_node(pa,i);
	pa->next=head;
}
void moni(int n,int y,int x)//ģ�����
{
	node *head=NULL;
	init(n,head);//����ѭ��������
	node *now=head;
	node *pre=head;
	for(int i=0;i<x-1;i++) now=now->next;//nowָ��ָ��ʼ��������
	for(int i=0;i<x-2;i++) pre=pre->next;//preָ��ָ��ǰ��
	while(x==1&&pre->next!=now)  pre=pre->next;//���⴦��now��preָ����ͬԪ�ص����
	int res,rs_check;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<y-1;j++)
		{
			now=now->next;
			pre=pre->next;
		}
		cout<<now->data<<"�ų���"<<endl;

		if(now==head) head=head->next;
		now=now->next;
		pre->next=now;
	}
}
void check(int n,int y,int x)//��ʽ����
{
	//y--;
	int res=0;
	for(int i=2;i<=n;i++)
	{
		res=(res+y)%i;
	}
	cout<<"check�����ӵ�����"<<(x+res-1)%n+1<<endl;
}
int main()
{
	int n,x,y;//n��������x��ʼ��������yִ������
	for(cout<<"������n x y:(n��������x��ʼ��������yִ������)"<<endl,cin>>n>>x>>y;
		x==0||y==0||n==0;
		cout<<"����Ƿ�����������n x y:(n��������x��ʼ��������yִ������)"<<endl,cin>>n>>x>>y);

	moni(n,x,y);
	check(n,x,y);
	system("pause");
}