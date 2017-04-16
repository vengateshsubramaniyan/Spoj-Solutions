#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
	ll t;
	scanf("%lld",&t);
	while(t--)
	{
		ll n;
		scanf("%lld",&n);
		ll tn;
		if(n%2!=0)
		{
			tn=(n+1)/2;
		}
		else
			tn=n/2;
		ll res=((2+((tn-1)*2)))*tn/2;
		if(n%2==0)
			res-=(n-1);
		else
			res-=n;
		printf("%lld\n",res%n);
	}
	return 0;
}
