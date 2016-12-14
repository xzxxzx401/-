//有向图强连通分量 Kosaraju算法
#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#define Vertex_num 10//默认10个点
using namespace std;
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
	vertex_list() { data=0;firstarc=new node; }
};
vertex_list G[Vertex_num];
vertex_list G_inv[Vertex_num];
void read_in()
{
	int a, b, c=0;
	while(cin>>a)
	{
		cin>>b/*>>c*/;
		node* now=G[a].firstarc;
		while(now->nextarc!=nullptr) now=now->nextarc;
		now->data=c;now->adjvex=b;now->nextarc=nullptr;

		now=G_inv[b].firstarc;
		while(now->nextarc!=nullptr) now=now->nextarc;
		now->data=c;now->adjvex=a;now->nextarc=nullptr;
	}
}
int vertex_dfsnum[Vertex_num],dfsnum=0;
bool visit[Vertex_num];
void dfs1(int n)
{
	visit[n]=1;
	for(node* a=G[n].firstarc;a!=nullptr&&a->adjvex!=-1;a=a->nextarc)
	{
		if(!visit[a->adjvex]) dfs1(a->adjvex);
	}
	vertex_dfsnum[dfsnum++]=n;
}
void dfs2(int n)
{
	visit[n]=1;
	cout<<n<<' ';
	for(node* a=G_inv[n].firstarc;a!=nullptr&&a->adjvex!=-1;a=a->nextarc)
	{
		if(!visit[a->adjvex]) dfs2(a->adjvex);
	}
}
int main()
{
	read_in();
	memset(vertex_dfsnum, 0, sizeof(vertex_dfsnum));
	memset(visit, 0, sizeof(visit));
	for(int i=0;i<Vertex_num;i++) { if(!visit[i]) dfs1(i); }
	memset(visit, 0, sizeof(visit));
	int scc_num=0;
	for(int i=Vertex_num-1;i>=0;i--)
		if(!visit[vertex_dfsnum[i]])
		{
			cout<<"第"<<++scc_num<<"个强连通分量：";
			dfs2(vertex_dfsnum[i]);
			cout<<endl;
		}
	system("pause");
}