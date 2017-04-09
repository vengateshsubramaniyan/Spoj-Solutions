#include<bits/stdc++.h>
#define ll long long
using namespace std;
bool possible(ll arr[],ll mid,ll c,ll n)
{
	ll pos=arr[0];
	ll cow=1;
	for(ll i=1;i<n;i++)
	{
		if(arr[i]-pos>=mid)
		{
			pos=arr[i];
			cow++;
			if(cow==c)
				return true;
		}
	}
	return false;
}
ll binary(ll arr[],ll &n,ll &c)
{
	ll result=-1;
	ll start=0,last=arr[n-1];
	while(start<last)
	{
		ll mid=start+(last-start)/2;
		if(possible(arr,mid,c,n))
		{
			if(mid>result)
				result=mid;
			start=mid+1;
		}
		else
		{
			last=mid;
		}		
	}
	return result;
}
int main()
{
	ll t;
	scanf("%lld",&t);
	while(t--)
	{
		ll n,c;
		scanf("%lld%lld",&n,&c);
		ll arr[n];
		for(ll i=0;i<n;i++)
			scanf("%lld",&arr[i]);
		sort(arr,arr+n);
		printf("%lld\n",binary(arr,n,c));
	}	
}
