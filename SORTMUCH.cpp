#include<bits/stdc++.h>
#define ll long long 
using namespace std;
template <class base_type, class num_type> double log(base_type base, num_type num)
{
  return log(num) / log(base); 
}
ll binary(ll l,ll h,ll n)
{
	ll result=l;
	while(l<h)
	{
		ll m=l+((h-l)/2);
		if((m*log(3,m))<=n)
		{
			if(result<m)
				result=m;
			l=m+1;
		}
		else
			h=m;
	}
	return result;
}
int main()
{
	ll t;
	scanf("%lld",&t);
	while(t--)
	{
		ll n;
		scanf("%lld",&n);
		ll l=0,h=1;
		while((h*log(3,h))<=n)
		{
			l=h;
			h=h*2;
		}
		printf("%lld\n",binary(l,h,n));
	}
}
