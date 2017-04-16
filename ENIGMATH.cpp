#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll gd(ll a,ll b)
{
	while(b!=0)
	{
		ll t=a%b;
		a=b;
		b=t;
	}
	return a;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		ll a,b;
		scanf("%lld%lld",&a,&b);
		if(a==b)
		{
			printf("1 1\n");
		}
		else
		{
			ll gcd=gd(a,b);
			if(gcd==1)
			{
				printf("%lld %lld\n",b,a);
			}
			else
			{
				gcd=(a*b)/gcd;
				printf("%lld %lld\n",gcd/a,gcd/b);
			}
		}
	}
	return 0;
}
