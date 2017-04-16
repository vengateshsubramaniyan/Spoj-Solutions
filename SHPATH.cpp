#include<bits/stdc++.h>
#define ll long long 
#define track1(a) cout<<a<<endl;
#define track2(a,b) cout<<a<<" "<<b<<endl;
using namespace std;
struct cmpp
{
	bool operator()(const pair<ll,ll> &a,pair<ll,ll> &b)
	{
		return a.first>b.first;
	}
};
void findshort(ll src,ll des,vector< vector<pair<ll,ll> > >&path,ll n)
{
	vector<ll> dist(n+1,INT_MAX);
	dist[src]=0;
	priority_queue<pair<ll,ll>, vector<pair<ll,ll> > ,cmpp> pq;
	pq.push(make_pair(0,src));
	vector<bool> visit(n+1,false);
	while(!pq.empty())
	{
		ll w=pq.top().first;
		ll u=pq.top().second;
		pq.pop();
		if(visit[u])
			continue;
		ll sz=path[u].size();
		for(ll i=0;i<sz;i++)
		{
			ll v=path[u][i].first;
			ll wei=path[u][i].second;
			if(!visit[v] && dist[v]>wei+w)
			{
				dist[v]=wei+w;
				pq.push(make_pair(dist[v],v));
			}
		}
		visit[u]=true;
		if(u==des)
			break;
	}
	printf("%lld\n",dist[des]);
}
int main()
{
	ll t;
	scanf("%lld",&t);
	while(t--)
	{
		ll n;
		scanf("%lld",&n);
		vector< vector<pair<ll,ll> > >path(n+1);
		map<string,ll> m;
		for(ll i=1;i<=n;i++)
		{
			string city;
			cin>>city;
			m[city]=i;
			ll p;
			scanf("%lld",&p);
			while(p--)
			{
				ll nei,wei;
				scanf("%lld%lld",&nei,&wei);
				path[i].push_back(make_pair(nei,wei));
				path[nei].push_back(make_pair(i,wei));
			}
		}
		ll pf;
		scanf("%lld",&pf);
		char start[100];
		char dest[100];
		while(pf--)
		{
			scanf("%s",start);
			map<string,ll>::iterator it;
			it=m.find(start);
			ll u=it->second;
			scanf("%s",dest);
			it=m.find(dest);
			ll v=it->second;
			findshort(u,v,path,n);
		}
	}
	return 0;
}
