#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

struct E {
	int to;
	int value;
	E(){}
	E(int _a, int _b) { to=_a;value=_b; }
};
int indegree[1007];
int outdegree[1007];
vector<E>G[1007];
queue<int> que;
int ve[1007];
int vl[1007];
int tp[1007];
int main()
{
	int n, m;
	while(scanf("%d%d", &n, &m)==2)
	{
		memset(indegree, 0, sizeof(indegree));
		memset(outdegree, 0, sizeof(outdegree));
		memset(ve, 0, sizeof(ve));
		memset(vl, 0, sizeof(vl));
		int tuopu=0;
		for(int i=0;i<m;i++)
		{
			int t1, t2, t3;
			scanf("%d%d%d", &t1, &t2, &t3);
			G[t1].push_back(E(t2, t3));
			indegree[t2]++;
			outdegree[t1]++;
		}
		int last=0;
		for(int i=0;i<n;i++) { if(indegree[i]==0) que.push(i); }
		while(!que.empty())
		{
			int i=que.front();que.pop();
			tp[i]=last;
			for(int j=0;j<G[i].size();j++)
			{
				int v=G[i][j].to;
				indegree[v]--;
				if(indegree[v]==0) que.push(v);
				ve[v]=max(ve[j], ve[i]+G[i][j].value);
			}
			last=i;
		}
		for(int i=last;i>0;i=tp[i])
		{
			vl[i]=ve[i];
			for(int j=0;j<G[i].size();j++)
			{
				vl[i]=min(vl[i], ve[i]-G[i][j].value);
			}
		}
		int mmin=0;
		for(int i=0;i<n;i++)
		{
			if(outdegree[i]==0)
			{
				mmin=max(mmin, ve[i]);
			}
		}
		printf("%d\n", mmin);
	}
	system("pause");
	return 0;
}