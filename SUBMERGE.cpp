#include<bits/stdc++.h>
using namespace std;
void dfs(int u,vector< vector<int> > &ed,vector< bool > &visit,vector< int > &disc,vector<int> &low,vector<int> &parent,int &time,vector<bool> &ap)
{
	visit[u]=true;
	disc[u]=low[u]=++time;
	int child=0;
	for(int i=0;i<ed[u].size();i++)
	{
		int v=ed[u][i];
		if(!visit[v])
		{
			child++;
			parent[v]=u;
			dfs(v,ed,visit,disc,low,parent,time,ap);
			low[u]=min(low[u],low[v]);
			if(parent[u]==0 && child>1)
				ap[u]=true;
			if(parent[u]!=0 && low[v]>=disc[u])
				ap[u]=true;
		}
		else if(v!=parent[u])
			low[u]=min(low[u],disc[v]);
	}
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	while(n && m)
	{
		vector< vector<int> >ed(n+1);
		while(m--)
		{
			int src,des;
			scanf("%d%d",&src,&des);
			ed[src].push_back(des);
			ed[des].push_back(src);
		}
		vector< bool > visit(n+1,false);
		vector< int > disc(n+1);
		vector< int > low(n+1);
		vector< bool > ap(n+1,false);
		vector< int > parent(n+1,0);
		int time=0;
		int result=0;
		for(int i=1;i<=n;i++)
		{
			if(!visit[i])
				dfs(i,ed,visit,disc,low,parent,time,ap);
		}
		for(int i=1;i<=n;i++)
		{
			if(ap[i])
				result++;
		}
		printf("%d\n",result);
		scanf("%d%d",&n,&m);
	}
	return 0;
}
