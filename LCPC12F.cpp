#include<bits/stdc++.h>
#define ll long long 
using namespace std;
int main()
{
	ll test;
	scanf("%lld",&test);
	for(ll t=1;t<=test;t++)
	{
		ll x;
		ll a[1001];
		ll result=0;
		scanf("%lld",&x);
		memset(a,0,sizeof(a));
		ll n;
		scanf("%lld",&n);
		for(ll i=0;i<n;i++)
		{
			ll val;
			scanf("%lld",&val);
			a[val]++;
		}
		for(ll i=1000;i>=0;i--)
		{
			if(a[i]!=0)
			{
				ll v=x-i;
				if(v>=0 && v<i && a[v]!=0)
				{
					result+=(a[i]*a[v]);
				}
				else if(v==i && a[v]>1)
				{
					ll val=a[v]-1;
					while(val)
					{
						result+=val;
						val--;
					}
				}
			}
		}
		printf("%lld. %lld\n",t,result);
	}
	return 0;
}
