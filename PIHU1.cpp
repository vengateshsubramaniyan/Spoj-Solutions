#include<bits/stdc++.h>
#define ll long long
#define vll vector<ll>
using namespace std;
bool find(vll &arr,ll &n,ll &p)
{
	for(ll i=0;i<n-2;i++)
	{
		ll j=i+1;
		ll k=n-1;
		while(j<k)
		{
			if(arr[i]+arr[j]+arr[k]==p)
				return true;
			else if(arr[i]+arr[j]+arr[k]<p)
				j++;
			else 
				k--;
		}
	}
	return false;
}
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
		sort(arr.begin(),arr.end());
		ll p;
		scanf("%lld",&p);
		find(arr,n,p)?printf("YES\n"):printf("NO\n");
	}
	return 0;
}
