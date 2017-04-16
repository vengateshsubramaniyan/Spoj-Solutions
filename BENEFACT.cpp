#include<bits/stdc++.h>
#define ll long long
using namespace std;
void findlong(vector< vector< pair<ll,ll> > > &arr,vector<bool> &visit,ll src,ll &rl,ll &result)
{
	ll m1=0,m2=0;
	visit[src]=true;
	for(ll i=0;i<arr[src].size();i++)
	{
		ll w=arr[src][i].second;
		ll v=arr[src][i].first;
		if(visit[v]==false)
		{
			findlong(arr,visit,v,w,result);
			if(w>m1)
			{
				m2=m1;
				m1=w;
			}
			else if(w>m2)
				m2=w;
			if(m1+m2>result)
				result=m1+m2;
		}
	}
	rl=rl+m1;
}
int main()
{
	ll t;
	scanf("%lld",&t);
	while(t--)
	{
		ll n;
		scanf("%lld",&n);
		vector< vector< pair<ll,ll> > > edge(n+1);
		for(int i=0;i<n-1;i++)
		{
			ll src,des,w;
			scanf("%lld%lld%lld",&src,&des,&w);
			edge[src].push_back(pair<ll,ll>(des,w));
			edge[des].push_back(pair<ll,ll>(src,w));
		}
		vector< bool > visited(n+1,false);
		ll result=0;
		for(ll i=1;i<=n;i++)
		{
			if(visited[i]==false)
			{
				ll rl=0;
				findlong(edge,visited,i,rl,result);
			}
		}
		printf("%lld\n",result); 
	}
	return 0;
}
