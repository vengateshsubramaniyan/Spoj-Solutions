#include<bits/stdc++.h>
#define ll long long int
#define vll vector<ll>
using namespace std;
int main()
{
	ll n;
	scanf("%lld",&n);
	while(n)
	{
		ll aval=0;
		ll req=0;
		ll i=0;
		ll result=0;
		while(n--)
		{
			ll val;
			scanf("%lld",&val);
//			cout<<aval<<" "<<req<<endl;
			if(val<0)
			{
				val=-val;
				aval+=val;
				if(req>0)
				{
					if(req<aval)
					{
						aval-=req;
						req=0;
						result+=aval;
					}
					else
					{
						req-=aval;
						aval=0;
						result+=req;
					}
				}
				else
					result+=aval;
			}
			else
			{
				req+=val;
				if(aval>0)
				{
					if(req>aval)
					{
						req-=aval;
						aval=0;
						result+=req;
					}
					else
					{
						aval-=req;
						req=0;
						result+=aval;
					}
				}
				else
					result+=req;			
			}
		}
		printf("%lld\n",result);
		scanf("%lld",&n);
	}
	return 0;
}
