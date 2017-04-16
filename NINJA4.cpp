#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		ll n;
		scanf("%lld",&n);
		ll x=0,y=0;
		ll q=n/4;
		q=q*4;
		x=-(q/2);
		y=-(q/2);
		q++;
		int i=1;
		while(q<=n)
		{
			if(i==1)
				x+=q;
			if(i==2)
				y+=q;	
			if(i==3)
				x-=q;
			i++;
			q++;
		}
		printf("%lld %lld\n",x,y);
	}
}
