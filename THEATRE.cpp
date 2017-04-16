#include<bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	stack<ll> s;
	ll res=1;
	for(int i=0;i<n;i++)
	{
		ll val;
		scanf("%lld",&val);
		while(!s.empty() && s.top()<val)
		{
//			cout<<val<<" ";
			res=(res*val)%mod;
			s.pop();
		}
		s.push(val);
	}
	printf("%lld",res);
	return 0;
}
