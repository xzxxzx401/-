//无向图的连通块
#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

vector<int> G[10];
bool visit[10];
void read_graph()
{
	int a, b;
	while(cin>>a>>b)
	{
		G[a].push_back(b);
		G[b].push_back(a);
	}
}
void dfs(int now)
{
	visit[now]=1;
	cout<<' '<<now;
	for(int i=0;i<G[now].size();i++)
	{
		if(!visit[G[now][i]]) 
			dfs(G[now][i]);

	}
}
int main()
{
	read_graph();
	int k=0;
	memset(visit, 0, sizeof(visit));
	for(int i=0;i<10;i++)
	{
		if(!visit[i])
		{
			cout<<"第"<<++k<<"个连通分量:";
			dfs(i);
			cout<<endl;
		}
	}
	system("pause");
	return 0;
}