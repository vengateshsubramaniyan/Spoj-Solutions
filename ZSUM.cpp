#include<bits/stdc++.h>
#define ll long long 
#define mod 10000007
using namespace std;
ll modular(ll a,ll b)
{
//	cout<<a<<" "<<b<<endl;
	a=a%mod;
	ll res=1;
	while(b>0)
	{
		if(b&1)
			res=(res*a)%mod;
		b=b>>1;
		a=(a*a)%mod;
	}
	return res;
}
int main()
{
	ll n,k;
	scanf("%lld%lld",&n,&k);
	while(n && k)
	{
		if(k>n)
		{
			ll a=modular(n-1,n-1);
			ll b=modular(n-1,k-n+1);
			b=(a*b)%mod;
			a=(2*a)%mod;
			b=(2*b)%mod;
			ll res=(a+b)%mod;
			a=modular(n,n);
			b=modular(n,k-n);
			b=(a*b)%mod;
			a=(a+b)%mod;
			res=(res+a)%mod;
			printf("%lld\n",res);
		}
		else if(k<n)
		{
			ll a=modular(n-1,k);
			ll b=modular(n-1,n-1-k);
			b=(a*b)%mod;
			a=(2*a)%mod;
			b=(2*b)%mod;
			ll res=(a+b)%mod;
			a=modular(n,k);
			b=modular(n,n-k);
			b=(a*b)%mod;
			a=(a+b)%mod;
			res=(res+a)%mod;
			printf("%lld\n",res);
		}
		else
		{
			ll a=modular(n-1,n-1);
			ll b=(a*(n-1))%mod;
			a=(2*a)%mod;
			b=(2*b)%mod;
			ll res=(a+b)%mod;
			a=modular(n,n);
			a=(2*a)%mod;
			res=(res+a)%mod;
			printf("%lld\n",res);
		}
		scanf("%lld%lld",&n,&k);
	}
	return 0;
}
