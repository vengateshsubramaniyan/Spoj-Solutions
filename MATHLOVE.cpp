#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define pi pair<int,int>
#define pll pair<ll,ll>
#define vl vector< ll >
#define bug(a) cout<<a<<endl;
#define bug2(a,b) cout<<a<<" "<<b<<endl;
#define bug3(a,b,c) cout<<a<<" "<<b<<" "<<c<<endl;
using namespace std;
int main()
{
	ll t;
	scanf("%lld",&t);
	while(t--)
	{
		ll n;
		scanf("%lld",&n);
		ll l=0;
		ll h=1;
		ll res=-1;
		ll sum=1;
		while(((h*(h+1))/2)<=n)
		{
			if((h*(h+1)/2)==n)
			{
				res=h;
				break;
			}
			l=h;
			h*=2;
		}
		if(res==-1)
		{
			while(l<h)
			{
				ll m=l+(h-l)/2;
				if(((m*(m+1))/2)<=n)
				{
					if(((m*(m+1))/2)==n)
					{
						res=m;
						break;
					}
					l=m+1;
				}
				else
					h=m;
			}
		}
		res==-1?printf("NAI\n"):printf("%lld\n",res);
	}
	return 0;
}


