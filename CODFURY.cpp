#include<bits/stdc++.h>
#define ll long long unsigned int
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		ll n,m;
		scanf("%lld%lld",&n,&m);
		deque< ll > dq;
		ll dcost=0;
		ll dc=0;
		ll result=0;
		ll rc=0;
		while(n--)
		{
			ll val;
			scanf("%lld",&val);
			dq.push_back(val);
			dcost=dcost+val;
			dc++;
			while(!dq.empty() && dcost>m)
			{
				dcost-=dq.front();
				dq.pop_front();
				dc--;
			}
			if(dc>=rc)
			{
				if(dc==rc)
				{
					if(result>dcost)
						result=dcost;
				}
				else
				{
					rc=dc;
					result=dcost;
				}
			}
		}
		printf("%lld %lld",result,rc);
		if(t!=0)
			printf("\n");
	}
	return 0;
}
