#include<bits/stdc++.h>
#define ll long long unsigned int
using namespace std;
void compute(ll arr[],ll temp[],ll &result,ll s,ll m,ll e)
{
	ll i=s;
	ll j=m+1;
	ll k=s;
	ll inter=0;
	while(i<=m && j<=e)
	{
		if(temp[i]<temp[j])
		{
			arr[k]=temp[i];
			inter+=temp[i];
			k++;
			i++;
		}
		else
		{
			arr[k]=temp[j];
			result+=inter;
			k++;
			j++;
		}
	}
	while(i<=m)
	{
		arr[k]=temp[i];
		k++;
		i++;
	}
	while(j<=e)
	{
		arr[k]=temp[j];
		result+=inter;
		j++;
		k++;
	}
	for(i=s;i<=e;i++)
		temp[i]=arr[i];
}
void merge(ll arr[],ll temp[],ll &result,ll s,ll e)
{
	if(s>=e)
		return;
	ll m=s+(e-s)/2;
	merge(arr,temp,result,s,m);
	merge(arr,temp,result,m+1,e);
	compute(arr,temp,result,s,m,e);
}
int main()
{
	ll t;
	scanf("%lld",&t);
	ll arr[100005];
	ll temp[100005];
	while(t--)
	{
		ll n;
		scanf("%lld",&n);
		for(ll i=0;i<n;i++)
		{
			scanf("%lld",&arr[i]);
			temp[i]=arr[i];
		}
		ll result=0;
		merge(arr,temp,result,0,n-1);
		printf("%lld\n",result);
	}
	return 0;
}
