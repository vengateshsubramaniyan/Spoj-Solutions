#include<bits/stdc++.h>
#define ll long long
#define vll vector<ll>
using namespace std;
int main()
{
	ll t;
	scanf("%lld",&t);
	while(t--)
	{
		ll n;
		scanf("%lld",&n);
		vll arr(n);
		for(ll i=0;i<n;i++)
			scanf("%lld",&arr[i]);
		vll arr1(n);
		for(ll i=0;i<n;i++)
			scanf("%lld",&arr1[i]);
		sort(arr.begin(),arr.end());
		sort(arr1.begin(),arr1.end());
		ll result=0;
		for(ll i=0;i<n;i++)
		{
			result+=(arr[i]*arr1[i]);
		}
		printf("%lld\n",result);
	}
	return 0;
}
