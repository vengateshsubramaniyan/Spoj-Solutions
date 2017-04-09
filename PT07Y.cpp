#include<bits/stdc++.h>
using namespace std;
bool dfs(vector< vector<int> > &arr,int s,int par,vector<bool> &visit)
{
	visit[s]=true;
	for(int i=0;i<arr[s].size();i++)
	{
		int v=arr[s][i];
		if(v!=par)
		{
			if(visit[v])
				return true;
			if(dfs(arr,v,s,visit))
				return true;
		}
	}
	return false;
}
int main()
{
	int n,m,u,v;
	scanf("%d%d",&n,&m);
	vector< vector<int> > arr(n+1);
	for(int i=0;i<m;i++)
	{
		scanf("%d%d",&u,&v);
		arr[u].push_back(v);
		arr[v].push_back(u);
	}
	vector< bool> visit(n+1,false);
	if(dfs(arr,1,-1,visit))
		printf("NO");
	else
	{
		int i;
		for(i=1;i<n;i++)
			if(visit[i]==false)
				break;
		(i==n)?printf("YES"):printf("NO");
	}
	return 0;
}
