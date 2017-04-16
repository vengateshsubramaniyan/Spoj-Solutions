#include<bits/stdc++.h>
using namespace std;
long long gcd(long long x,long long y)
{
	while(y!=0)
	{
		long long tem=x%y;
		x=y;
		y=tem;
	}
	return x;
}
int main()
{
	int t;
	long long x,y,z;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld%lld%lld",&x,&y,&z);
		if(z>(max(x,y)))
		{
			printf("NO\n");
		}
		else
		{
			long long temp=gcd(x,y);
			if(z%temp==0)
				printf("YES\n");
			else
				printf("NO\n");
		}
	}
	return 0;
}
