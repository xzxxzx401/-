#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#define Vertex_num 10//Ä¬ÈÏ10¸öµã
using namespace std;
const int oo=0x3f3f3f3f;
struct node
{
	int data;
	int adjvex;
	node *nextarc;
	node() { data=0;adjvex=-1;nextarc=nullptr; }
};
struct vertex_list
{
	int data;
	node* firstarc;
	vertex_list() { data=0;firstarc=nullptr; }
};
vertex_list G[Vertex_num];
int indegree[Vertex_num];
int outdegree[Vertex_num];
void read_in(int &e_num)
{
	memset(indegree, 0, sizeof(indegree));
	int a, b, c=0;
	while(cin>>a)
	{
		cin>>b>>c;

		node* now=G[a].firstarc;
		if(now==nullptr)
		{
			G[a].firstarc=new node;
			now=G[a].firstarc;
		}

		else
		{
			while(now->nextarc!=nullptr) now=now->nextarc;
			now->nextarc=new node;
			now=now->nextarc;
		}
		now->data=c;now->adjvex=b;now->nextarc=nullptr;
		indegree[b]++;
		e_num++;
	}
}

int main()
{
	int e_num=0;
	read_in(e_num);
	int max_lenth=0;
	for(int i=0;i<e_num;i++)
	{
		for(int j=0;j<Vertex_num;j++)
		{
			if(indegree[j]==0)
			{
				node* now=G[j].firstarc;
				while(now!=nullptr)
				{
					if(now->data==-1) continue;
					int v=now->adjvex;
					G[v].data=max(G[j].data+now->data,G[v].data);
					indegree[v]--;
					now=now->nextarc;
				}
				indegree[j]=-1;
			}
		}
	}
	for(int i=0;i<Vertex_num;i++)
	{
		max_lenth=max(max_lenth, G[i].data);
	}
	cout<<max_lenth<<endl;

	system("pause");
	return 0;
}