#include<bits/stdc++.h>
#define ll long long unsigned int
using namespace std;
int main()
{
	ll n;
	scanf("%lld",&n);
	while(n)
	{
		vector<ll> arr(n);
		for(ll i=0;i<n;i++)
		{
			scanf("%lld",&arr[i]);
		}
		ll i=0;
		ll result=0;
		stack<ll> s;
		while(i<n)
		{
			if(s.empty() || arr[s.top()]<=arr[i])
			{
				s.push(i++);
			}
			else
			{
				ll tp=s.top();
				s.pop();
				ll area=arr[tp]*(s.empty()?i:i-s.top()-1);
				if(area>result)
					result=area;
			}
		}
		while(!s.empty())
		{
			ll tp=s.top();
			s.pop();
			ll area=arr[tp]*(s.empty()?i:i-s.top()-1);
			if(area>result)
				result=area;
		}
		printf("%lld\n",result);
		scanf("%lld",&n);
	}
	return 0;
}
