#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		ll n;
		scanf("%lld",&n);
		ll a[n],b[n];
		for(ll i=0;i<n;i++)
			scanf("%lld",&a[i]);
		for(ll i=0;i<n;i++)
			scanf("%lld",&b[i]);
		ll len=1;
		ll val=min(a[0],b[0]);
		for(ll i=1;i<n;i++)
		{
			ll mi=a[i],ma=b[i];
			if(a[i]>b[i])
			{
				mi=b[i];
				ma=a[i];
			}
			if(ma<val)
				break;
			if(mi>=val)
				val=mi;
			else
				val=ma;
			len++;
		}
		if(len!=n)
			printf("NO\n");
		else
			printf("YES\n");
	}
}
