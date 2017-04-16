#include<bits/stdc++.h>
using namespace std;
int findparent(int parent[],int node)
{
	if(parent[node]!=parent[parent[node]])
		parent[node]=findparent(parent,parent[node]);
	return parent[node];
}
void unionnode(int parent[],int rank[],int src,int dest)
{
	int pa=findparent(parent,src);
	int pb=findparent(parent,dest);
	if(pa!=pb)
	{
		if(rank[pa]>=rank[pb])
		{
			parent[pb]=pa;
			rank[pa]+=rank[pb];
		}	
		else
		{
			parent[pa]=pb;
			rank[pb]+=rank[pa];
		}
	}
}
int main()
{
	int test;
	scanf("%d",&test);
	for(int t=1;t<=test;t++)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		int parent[1005];
		int rank[1005];
		int cost[1005];
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&cost[i]);
			parent[i]=i;
			rank[i]=1;
		}
		for(int i=0;i<m;i++)
		{
			int src,dest;
			scanf("%d%d",&src,&dest);
			unionnode(parent,rank,src,dest);
		}
		int gcount=0;
		long long result[1005]={0};
		for(int i=1;i<=n;i++)
		{
			result[findparent(parent,i)]+=cost[i];
			if(parent[i]==i)
				gcount++;
		}
		printf("Case %d: %d\n",t,gcount);
		sort(result,result+n+1);
		for(int i=0;i<=n;i++)
		{
			if(result[i]!=0)
				printf("%lld ",result[i]);
		}
		printf("\n");
	}
	return 0;
}
