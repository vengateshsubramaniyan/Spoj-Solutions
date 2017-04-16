#include<bits/stdc++.h>
#define scand(temp) scanf("%d",&temp)
using namespace std;
int findmindistance(vector<long long> &dist,vector<bool> &visit)
{
	int min=INT_MAX;
	int re;
	for(int i=0;i<=500;i++)
	{
		if(!visit[i] && min>=dist[i])
		{
			min=dist[i];
			re=i;
		}
	}
	return re;
}
void dijsktra(vector<vector<int> > &arr,vector<long long> &dist,int &start)
{
	vector<bool> visit(501,false);
	dist[start]=0;
	for(int i=0;i<500;i++)
	{
		int re=findmindistance(dist,visit);
		visit[re]=true;
		for(int v=0;v<=500;v++)
		{
			if(!visit[v] && arr[re][v] && dist[re]!=INT_MAX && dist[re]+arr[re][v]<dist[v])
				dist[v]=dist[re]+arr[re][v];
		}
	}
}
int main()
{
	int n;
	scand(n);
	vector<vector<int> > arr(501,vector<int>(501,0));
	while(n--)
	{
		int src,des,w;
		scanf("%d%d%d",&src,&des,&w);
		arr[src][des]=w;
		arr[des][src]=w;
	}
	int start;
	scand(start);
	int nod;
	scand(nod);
	vector<int> end(nod);
	for(int i=0;i<nod;i++)
		scand(end[i]);
	vector<long long > dist(501,INT_MAX);
	dijsktra(arr,dist,start);
	for(int i=0;i<nod;i++)
	{
		if(dist[end[i]]==INT_MAX)
			printf("NO PATH\n");
		else
			printf("%lld\n",dist[end[i]]);
	}
	return 0;
}
