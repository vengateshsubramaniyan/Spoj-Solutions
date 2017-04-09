#include<bits/stdc++.h>
#define ll long long
using namespace std;
int dfs(int s,vector< vector<int> > &edge,bool visit[],int &result)
{
	visit[s]=true;
	if(edge[s].size()==1 && s!=0)
	{
		result+=1;
		return 1;
	}
	int a=0;
	int c=0;
	for(int i=0;i<edge[s].size();i++)
	{
		int d=edge[s][i];
		if(!visit[d])
		{
			c++;
			a+=dfs(d,edge,visit,result);
		}
	}
	a=2+a+(c-1);
	result+=a;
	return a;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		vector< vector<int> > edge(n);
		for(int i=1;i<n;i++)
		{
			int src,des;
			scanf("%d%d",&src,&des);
			edge[src].push_back(des);
			edge[des].push_back(src);
		}
		int result=0;
		bool visit[n];
		memset(visit,false,sizeof(visit));
		dfs(0,edge,visit,result);
		printf("%d\n",result);
	}
	return 0;
}
