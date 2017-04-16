#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll gcd(ll a,ll b)
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
	ll n,k;
	scanf("%lld%lld",&n,&k);
	while(n!=-1 && k!=-1)
	{
		if(n==0 || k==0)
			printf("0\n");
		else
		{
			ll q=((n-1)*n)/2;
			k=k-1;
			ll nt;
			if(k%2==0)
			{
				nt=k/2;
			}
			else
			{
				nt=(k+1)/2;
			}
			ll p=((2*(k-1)+((nt-1)*-2))*(nt))/2;
			if(p==q)
				printf("1\n");
			else if(p==0 || q==0)
				printf("0\n");
			else
			{
				ll gd=gcd(p,q);
				printf("%lld/%lld\n",p/gd,q/gd);
			}
		}
		scanf("%lld%lld",&n,&k);
	}
	return 0;
}
