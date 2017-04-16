#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	ll test,n,excl,incl;
	scanf("%lld",&test);
	for(ll t=1;t<=test;t++)
	{
		excl=0;
		incl=0;
		scanf("%lld",&n);
		for(ll i=0;i<n;i++)
		{
			ll val;
			scanf("%lld",&val);
			val=excl+val;
			excl=max(excl,incl);
			incl=val;
		}
		if(incl>excl)
			excl=incl;
		printf("Case %lld: %lld\n",t,excl);
	}
	return 0;
} 
