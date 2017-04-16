#include<bits/stdc++.h>
using namespace std;
void dfs(int s,vector< bool > &visit,vector< vector<int> > &edge)
{
	visit[s]=true;
	for(int i=0;i<edge[s].size();i++)
	{
		int d=edge[s][i];
		if(visit[d]==false)
			dfs(d,visit,edge);
	}
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,e;
		scanf("%d%d",&n,&e);
		vector< vector<int> > edge(n);
		while(e--)
		{
			int s,d;
			scanf("%d%d",&s,&d);
			edge[s].push_back(d);
			edge[d].push_back(s);
		}
		vector< bool > visit(n,false);
		int re=0;
		for(int i=0;i<n;i++)
		{
			if(visit[i]==false)
			{
				re++;
				dfs(i,visit,edge);
			}
		}
		printf("%d\n",re);
	}
	return 0;
}
