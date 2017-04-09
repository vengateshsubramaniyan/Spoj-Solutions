#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	ll t;
	scanf("%lld",&t);
	while(t--)
	{
		ll n;
		scanf("%lld",&n);
		if(n<=3)
		{
			ll tq=0;
			while(n--)
			{
				ll val;
				scanf("%lld",&val);
				tq+=val;
			}
			printf("%lld\n",tq);
		}
		else
		{
			ll rate[n];
			for(ll i=n-1;i>=0;i--)
				scanf("%lld",&rate[i]);
			ll dp[n];
			for(ll i=0;i<n;i++)
			{
				if(i<3)
				{
					if(i==0)
						dp[0]=rate[0];
					else 
						dp[i]=rate[i]+dp[i-1];
				}
				else
				{
					dp[i]=rate[i]+dp[i-2];
					ll t1=rate[i]+rate[i-1];
					if(i-4>=0)
						t1+=dp[i-4];
					if(dp[i]<t1)
						dp[i]=t1;
					t1=rate[i]+rate[i-1]+rate[i-2];
					if(i-6>=0)
						t1+=dp[i-6];
					if(dp[i]<t1)
						dp[i]=t1;
				}
			}
			printf("%lld\n",dp[n-1]);
		}
	}
	return 0;
}
