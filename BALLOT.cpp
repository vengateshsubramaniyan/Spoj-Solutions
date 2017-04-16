#include<bits/stdc++.h>
#define ll long long
using namespace std;
bool pos(ll arr[],ll m,ll n,ll b)
{
	for(ll i=0;i<n;i++)
	{
		b=b-(arr[i]/m);
		if(arr[i]%m!=0)
			b-=1;
		if(b<0)
			return false;
	}
	return b>=0;
}
ll binary(ll arr[],ll n,ll b,ll r)
{
	ll result=r;
	ll l=1;
	while(l<r)
	{
		ll m=l+(r-l)/2;
		if(pos(arr,m,n,b))
		{
			if(result>m)
				result=m;
			r=m;
		}
		else
			l=m+1;
	}
}
int main()
{
	ll n,b;
	scanf("%lld%lld",&n,&b);
	while(n!=-1 && b!=-1)
	{
		ll arr[n];
		ll r=1;
		for(ll i=0;i<n;i++)
		{
			scanf("%lld",&arr[i]);
			if(r<arr[i])
				r=arr[i];
		}
		printf("%lld\n",binary(arr,n,b,r));
		scanf("%lld%lld",&n,&b);
	}
	return 0;
}
