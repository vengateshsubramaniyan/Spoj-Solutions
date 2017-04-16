#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n;
ll arr[2001];
ll cache[2001][2001];
ll profit(ll be,ll en)
{
	if(be>en)
		return 0;
	if(cache[be][en]!=-1)
		return cache[be][en];
	ll y=n-(en-be+1)+1;
	cache[be][en]=max(profit(be+1,en)+(y*arr[be]),profit(be,en-1)+(y*arr[en]));
	return cache[be][en];
}
int main()
{
	scanf("%lld",&n);
	for(ll i=0;i<n;i++)
		scanf("%lld",&arr[i]);
	memset(cache,-1,sizeof(cache));
	printf("%lld",profit(0,n-1));
	return 0;
}
