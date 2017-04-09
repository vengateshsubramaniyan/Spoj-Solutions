#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll rev(ll val)
{
	ll temp=0;
	while(val!=0)
	{
		temp<<=1;
		if(val&1)
			temp=temp|1;
		val>>=1;
	}	
	return temp;
}
int main()
{
	ll n;
	scanf("%lld",&n);
	while(n--)
	{
		ll val;
		scanf("%lld",&val);
		if(val%2!=0)
			printf("%lld\n",val);
		else
			printf("%lld\n",rev(val));
	}
	return 0;
}
