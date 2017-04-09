#include<bits/stdc++.h>
#define ll long long unsigned int
using namespace std;
int main()
{
	ll n,m;
	scanf("%lld%lld",&n,&m);
	deque< ll > dq;
	ll dcost=0;
	ll result=0;
	while(n--)
	{
		ll val;
		scanf("%lld",&val);
		dq.push_back(val);
		dcost=dcost+val;
		while(!dq.empty() && dcost>m)
		{
			dcost-=dq.front();
			dq.pop_front();
		}
		if(m-dcost>=0 && m-dcost< m-result)
		{
			result=dcost;
		}
	}
	printf("%lld",result);
	return 0;
}
