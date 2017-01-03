#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
struct Edge;
struct Node
{
	int data;
	Edge *next;
};

struct Edge
{
	int info;
	Edge *nextarc;
	Node *adjvex;
};


vector<int> maxDis;
vector<Node> node;
vector<int> head;

int findMaxDis(Node *n)
{
	if(maxDis[n->data])return maxDis[n->data];
	if(!n->next) return 0;

	int Max=-1;
	Edge *t=n->next;
	while(t)
	{
		Max=max(Max, findMaxDis(t->adjvex)+t->info);
		t=t->nextarc;
	}
	return maxDis[n->data]=Max;
}

int main(void)
{
	int num;
	int a=1, b=1, w=1;

	cout<<"输入顶点个数: ";
	cin>>num;
	for(int i=0; i<=num; i++)//INIT
	{
		Node T;
		T.data=i;
		T.next=NULL;
		node.push_back(T);
		maxDis.push_back(0);
		head.push_back(i);
	}
	cout<<"输入边: 起始点 终止点 权值"<<endl;
	while(cin>>a)
	{
		cin>>b>>w;
		head[b]=0;
		if(!node[a].next)//出度0
		{
			Edge *T=new Edge;
			T->info=w;
			T->nextarc=NULL;
			T->adjvex=&node[b];
			node[a].next=T;
		}
		else
		{
			Edge *T=node[a].next;
			while(T->nextarc) T=T->nextarc;
			Edge *t=new Edge;
			t->info=w;
			t->nextarc=NULL;
			t->adjvex=&node[b];
			T->nextarc=t;
		}
	}
	int maxDis=-1;
	for(int i=1; i < head.size(); i++)
	{
		if(head[i])
			maxDis=max(maxDis, findMaxDis(&node[i]));
	}

	cout<<"Max Distance is: "<<maxDis<<endl;
	system("pause");
	return 0;
}