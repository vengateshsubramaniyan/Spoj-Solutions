#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct cmpp
{
	bool operator()(pair<pair<ll,ll>,ll> a,pair<pair<ll,ll>,ll> b)
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
		ll p,c;
		scanf("%lld",&p);
		scanf("%lld",&c);
		int arr[c];
		priority_queue< pair<pair<ll,ll>,ll> , vector< pair<pair<ll,ll>,ll> > ,cmpp > pq;
		for(ll i=0;i<c;i++)
		{
			scanf("%d",&arr[i]);
			pq.push(pair<pair<ll,ll>,ll>(pair<ll,ll>(i,1),arr[i]));
		}
		ll result;
		while(p)
		{
			ll i=pq.top().first.first;
			ll cc=pq.top().first.second;
			ll j=pq.top().second;
			p--;
			if(p==0)
			{
				result=j;
				break;
			}
			pq.pop();
			pq.push(pair<pair<ll,ll>,ll>(pair<ll,ll>(i,cc+1),j+(arr[i]*(cc+1))));
		}
		printf("%lld\n",result);
	}
	return 0;
}
