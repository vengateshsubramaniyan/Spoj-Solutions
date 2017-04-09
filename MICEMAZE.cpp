#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct cmpp
{
	bool operator()(const pair<int,int> &a,pair<int,int> &b)
	{
		return a.second>b.second;
	}
};
int main()
{
	int n,e,t;
	scanf("%d%d%d",&n,&e,&t);
	vector< vector<pair<int,int> > > edge(n+1);
	edge.clear();
	int m;
	scanf("%d",&m);
	while(m--)
	{
		int src,des,we;
		scanf("%d%d%d",&src,&des,&we);
		edge[des].push_back(make_pair(src,we));
	}
	vector<int> dist(n+1,INT_MAX);
	priority_queue< pair<int,int> ,vector<pair<int,int> > ,cmpp> pq;
	dist[e]=0;
	pq.push(make_pair(e,0));
	vector<bool> visit(n+1,false);
	while(!pq.empty())
	{
		int u=pq.top().first;
		int w=pq.top().second;
		pq.pop();
		if(visit[u])
			continue;
		for(int i=0;i<edge[u].size();i++)
		{
			int v=edge[u][i].first;
			int we=edge[u][i].second;
			if(!visit[v] && dist[v]>we+w)
			{
				dist[v]=we+w;
				pq.push(pair<int,int>(v,dist[v]));
			}
		}
		visit[u]=true;
	}
	int result=0;
	for(int i=1;i<=n;i++)
		if(dist[i]<=t)
			result++;
	printf("%d",result);
	return 0;
}
