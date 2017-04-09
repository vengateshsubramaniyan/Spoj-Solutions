#include<bits/stdc++.h>
using namespace std;
int vertexcover(vector< vector<int> > &arr, int u, int par, int dp[])
{
	if(dp[u]!=-1)
		return dp[u];
	int incl=1,excl=0;
	for(int i=0;i<arr[u].size();i++)
	{
		int v=arr[u][i];
		if(v!=u && v!=par)
		{
			if(dp[v]==-1)
				vertexcover(arr,v,u,dp);
			incl+=dp[v];
		}
	}
	for(int i=0;i<arr[u].size();i++)
	{
		int v=arr[u][i];
		if(v!=u && v!=par)
		{
			excl++;
			for(int j=0;j<arr[v].size();j++)
			{
				int w=arr[v][j];
				if(w!=v && w!=u)
				{
					if(dp[w]==-1)
						vertexcover(arr,w,v,dp);
					excl+=dp[w];
				}
			}
		}
	}
	dp[u]=min(incl,excl);
	return dp[u];
}
int main() 
{
	int n;
	scanf("%d",&n);
	vector< vector<int> > arr(n+1);
	for(int i=1;i<n;i++)
	{
		int s,d;
		scanf("%d%d",&s,&d);
		arr[s].push_back(d);
		arr[d].push_back(s);
	}
	int dp[n+1];
	memset(dp,-1,sizeof(int)*(n+1));
	for(int i=1;i<=n;i++)
//	{
//		if(arr[i].size()==1)
//			dp[i]=0;
//	}
	vertexcover(arr,1,0,dp);
	printf("%d",dp[1]);
	return 0;
}
