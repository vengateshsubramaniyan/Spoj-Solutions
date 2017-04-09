#include<bits/stdc++.h>
using namespace std;
int dfs(int s,vector< vector<int> > &edge,vector<bool> &visit,int &result)
{
	visit[s]=true;
	int re=0;
	for(int i=0;i<edge[s].size();i++)
	{
		if(visit[edge[s][i]]==false)
		{
			int rr=dfs(edge[s][i],edge,visit,result);
			if(re+rr>result)
				result=rr+re;
			if(rr>re)
				re=rr;
		}
	}
	return re+1;
}
int main()
{
	int n;
	scanf("%d",&n);
	vector <vector< int> > edge(n+1);
	for(int i=0;i<n-1;i++)
	{
		int src,des;
		scanf("%d%d",&src,&des);
		edge[src].push_back(des);
		edge[des].push_back(src);
	}
	vector <bool> visit(n+1,false);
	int result=0;
	for(int i=1;i<=n;i++)
	{
		if(visit[i]==false)
		{
			dfs(i,edge,visit,result);
		}
	}
	printf("%d",result);
	return 0;
}
