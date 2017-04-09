#include<bits/stdc++.h>
#define ll long long 
using namespace std;
struct cmpp
{
	bool operator()(pair<ll,ll> &a,pair<ll,ll> &b)
	{
		return a.second>=b.second;
	}
};
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		ll n;
		scanf("%lld",&n);
		vector< vector< pair<ll,ll> > >edge(n+1);
		for(ll i=1;i<=n;i++)
		{
			char cname[100];
			scanf("%s",cname);
			ll k;
			scanf("%lld",&k);
			while(k--)
			{
				ll d,cost;
				scanf("%lld%lld",&d,&cost);
				edge[i].push_back(pair<ll,ll>(d,cost));
			}
		}
		priority_queue< pair<ll,ll> , vector< pair<ll,ll> > ,cmpp> pq;
		pq.push(pair<ll,ll>(1,0));
		vector< ll > key(n+1,INT_MAX);
		key[1]=0;
		vector< bool > visit(n+1,false);
		while(!pq.empty())
		{
			ll s=pq.top().first;
			pq.pop();
			visit[s]=true;
			for(ll i=0;i<edge[s].size();i++)
			{
				ll d=edge[s][i].first;
				if(visit[d]==false && key[d]>edge[s][i].second)
				{
					key[d]=edge[s][i].second;
					pq.push(pair<ll,ll>(d,edge[s][i].second));
				}
			}
		}
		ll result=0;
		for(ll i=1;i<=n;i++)
			result+=key[i];
		printf("%lld\n",result);
	}
	return 0;
}
