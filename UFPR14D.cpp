#include<bits/stdc++.h>
#define ll long long 
using namespace std;
int main()
{
	ll n;
	scanf("%lld",&n);
	ll arr[n+2];
	arr[0]=0;
	arr[n+1]=0;
	for(ll i=1;i<=n;i++)
	{
		scanf("%lld",&arr[i]);
		arr[i]+=arr[i-1];
	}
	ll q;
	scanf("%lld",&q);
	while(q--)
	{
		ll l,r;
		scanf("%lld%lld",&l,&r);
		printf("%lld\n",arr[r]-arr[l-1]);
	}
	return 0;
}
