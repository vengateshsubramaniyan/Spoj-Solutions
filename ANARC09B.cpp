#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll gcd(ll a, ll b)
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
	long long a,b;
	scanf("%lld%lld",&a,&b);
	while(a && b)
	{
		ll gd=gcd(a,b);
		ll lcm=(a*b)/gd;
		printf("%lld\n",lcm/gd);
		scanf("%lld%lld",&a,&b);
	}
	return 0;
}
