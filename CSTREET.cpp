#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct cmpp
{
	bool operator()(const pair<ll,ll> &a,pair<ll,ll> &b)
	{
		return a.second>b.second;
	}
};
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		ll cost;
		scanf("%lld",&cost);
		ll n,m;
		scanf("%lld%lld",&n,&m);
		vector< vector< pair<ll ,ll > > > edge(n+1);
		while(m--)
		{
			ll src,des,w;
			scanf("%lld%lld%lld",&src,&des,&w);
			edge[src].push_back(pair<ll,ll>(des,w));
			edge[des].push_back(pair<ll,ll>(src,w));
		}
		vector<ll> key(n+1,INT_MAX);
		vector<bool> visit(n+1,false);
		priority_queue<pair<ll,ll>,vector<pair<ll,ll> > , cmpp > q;
		key[1]=0;
		q.push(pair<ll,ll>(1,0));
		while(!q.empty())
		{
			ll u=q.top().first;
			visit[u]=true;
			q.pop();
			for(ll i=0;i<edge[u].size();i++)
			{
				ll v=edge[u][i].first;
				ll wei=edge[u][i].second;
				if(visit[v]==false && key[v]>wei)
				{
					key[v]=wei;
					q.push(pair<ll,ll>(v,wei));
				}
			}
		}
		ll result=0;
		for(ll i=1;i<=n;i++)
			result+=key[i];
		printf("%lld\n",result*cost);
	}
	return 0;	
}
