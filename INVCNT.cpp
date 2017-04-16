#include<bits/stdc++.h>
#define ll long long 
#define vll vector<ll>
using namespace std;
ll mergesort(vll &arr,vll &temp,ll start,ll mid,ll end,ll &n)
{
	ll count=0;
	ll i=start;
	ll j=mid+1;
	ll k=start;
	ll result=0;
	while(i<=mid && j<=end)
	{
		if(temp[i]<=temp[j])
		{
			result+=count;
			arr[k++]=temp[i++];
		}
		else
		{
			arr[k++]=temp[j++];
			count++;
		}
	}
	while(i<=mid)
	{
		result+=count;
		arr[k++]=temp[i++];
	}
	while(j<=end)
		arr[k++]=temp[j++];
	for(ll i=start;i<=end;i++)
		temp[i]=arr[i];
	return result;
}
ll merge(vll &arr,vll &t,ll start,ll end,ll &n)
{
	if(start>=end)
		return 0;
	ll mid=start+(end-start)/2;
	ll count=0;
	count+=merge(arr,t,start,mid,n);
	count+=merge(arr,t,mid+1,end,n);
	count+=mergesort(arr,t,start,mid,end,n);
	return count;
}
int main()
{
	ll test;
	scanf("%lld",&test);
	while(test--)
	{
		ll n;
		cin>>n;
		vll arr(n);
		vll t(n);
		for(ll i=0;i<n;i++)
			scanf("%d",&arr[i]);
		t=arr;
		printf("%lld\n",merge(arr,t,0,n-1,n));
	}
	return 0;
}
