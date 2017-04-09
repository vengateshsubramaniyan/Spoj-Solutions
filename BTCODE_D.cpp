#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
	ll t;
	scanf("%lld",&t);
	while(t--)
	{
		ll n,m;
		scanf("%lld%lld",&m,&n);
		ll a[m][n];
		ll b[m][n];
		ll c[m][n];
		for(ll i=0;i<m;i++)
			for(ll j=0;j<n;j++)
				scanf("%lld",&a[i][j]);
		for(ll i=0;i<m;i++)
			for(ll j=0;j<n;j++)
				scanf("%lld",&b[i][j]);
		for(ll i=0;i<m;i++)
			for(ll j=0;j<n;j++)
				scanf("%lld",&c[i][j]);
		ll result=0;
		for(ll i=0;i<m;i++)
		{
			ll temp=0;	
			for(ll j=0;j<n;j++)
			{
				if(a[i][j]<b[i][j])
				{
					if(temp<(a[i][j]*c[i][j]))
						temp=a[i][j]*c[i][j];
				}
				else
				{
					if(temp<(b[i][j]*c[i][j]))
						temp=b[i][j]*c[i][j];
				}
			} 
			result+=temp;
		}
		printf("%lld\n",result);
	}
	return 0;
}
