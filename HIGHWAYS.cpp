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
	ll t;
	scanf("%lld",&t);
	while(t--)
	{
		ll n,m,sc,ec;
		scanf("%lld%lld%lld%lld",&n,&m,&sc,&ec);
		vector< vector< pair<ll,ll> > >edge(n+1);
		while(m--)
		{
			ll src,des,we;
			scanf("%lld%lld%lld",&src,&des,&we);
			edge[src].push_back(make_pair(des,we));
			edge[des].push_back(make_pair(src,we));
		}
		vector<ll> dist(n+1,INT_MAX);
		priority_queue< pair<int,int> ,vector<pair<int,int> > ,cmpp> pq;
		dist[sc]=0;
		pq.push(make_pair(sc,0));
		vector<bool> visit(n+1,false);
		ll result=INT_MIN;
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
			if(u==ec)
			{
				result=dist[u];
				break;
			}
		}
		if(result==INT_MIN)
			printf("NONE\n");
		else
			printf("%lld\n",result);
	}
}
