#include<bits/stdc++.h>
#define ll long long
using namespace std;
map<ll,ll> dp;
ll coin(ll n)
{
	if(n>=0 && n<12)
	{
		if(!dp[n])
			dp[n]=n;
		return dp[n];
	}
	if(!dp[n])
		dp[n]=coin(n/2)+coin(n/3)+coin(n/4);
	return dp[n];
}
int main()
{
	ll n;
	while(cin>>n)
	{
		printf("%lld\n",coin(n));
	}
	return 0;
}
