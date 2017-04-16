#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct cmpp
{
	bool operator()(const pair<ll,pair<ll,ll> >&a,const pair<ll,pair<ll,ll> >&b)
	{
		return a.first>=b.first;
	}
};
int main()
{
	ll n,m;
	scanf("%lld%lld",&n,&m);
	priority_queue< pair<ll,pair<ll,ll> >, vector< pair<ll,pair<ll,ll> > >, cmpp > pq; 
	for(ll i=1;i<=n;i++)
	{
		ll val;
		scanf("%lld",&val);
		if(val==1)
			pq.push(pair<ll,pair<ll,ll> >(0,pair<ll,ll>(0,i)));
	}
	vector< bool > milk(n+1,false);
	vector< vector< pair<ll,ll> > > road(n+1);
	while(m--)
	{
		ll src,des,dis;
		scanf("%lld%lld%lld",&src,&des,&dis);
		road[src].push_back(pair<ll,ll>(des,dis));
		road[des].push_back(pair<ll,ll>(src,dis));
	}
	ll result=0;
	while(!pq.empty())
	{
		ll s,par,val,fv;
		fv=pq.top().first;
		val=pq.top().second.first;
		s=pq.top().second.second;
		pq.pop();
		if(!milk[s])
			result+=val;
		milk[s]=true;
		for(ll i=0;i<road[s].size();i++)
		{
			ll d=road[s][i].first;
			val=road[s][i].second;
			if(!milk[d])
				pq.push(pair<ll,pair<ll,ll> >(fv+val,pair<ll,ll>(val,d)));
		}
	}
	bool all=true;
	for(ll i=1;i<=n;i++)
	{
		if(!milk[i])
		{
			all=false;
			break;
		}
	}
	if(!all)
		printf("impossible");
	else
		printf("%lld",result);
	return 0;
}
