#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	int t;
	int c[]={6,1,4};
	scanf("%d",&t);
	while(t--)
	{
		ll n;
		scanf("%lld",&n);
		ll q=n/3;
		ll r=n%3;
		if(q%2==0 && r==0)
		{
			printf("0\n");
		}
		else if(q%2!=0 && r==0)
		{
			printf("6\n");
		}
		else if(q%2==0 && r!=0)
		{
			printf("%d\n",c[r]);
		}
		else if(q%2!=0 && r!=0)
		{
			printf("%d\n",(6-c[r]));
		}
	}
	return 0;
}
