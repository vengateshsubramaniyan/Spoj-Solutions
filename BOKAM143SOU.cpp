#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	ll n;
	scanf("%lld",&n);
	ll res=0;
	for(ll i=1;i<=ceil(cbrt(n));i++)
	{
		ll a=i*i*i;
		if(a==n)
			res++;
		for(ll j=i;j<=ceil(cbrt(n));j++)
		{
			ll b=j*j*j;
			b+=a;
			if(b==n)
				res++;
			for(ll k=j;k<=ceil(cbrt(n));k++)
			{
				ll c=k*k*k;
				c+=b;
				if(c==n)
					res++;
				for(ll l=k;l<=ceil(cbrt(n));l++)
				{
					ll d=l*l*l;
					d+=c;
					if(d==n)
						res++;
					for(ll m=l;m<=ceil(cbrt(n));m++)
					{
						ll e=m*m*m;
						e+=d;
						if(e==n)
							res++;
					}
				}
			}
		}
	}
	printf("%lld\n",res);
	return 0;
}
