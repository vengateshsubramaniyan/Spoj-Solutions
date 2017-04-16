#include<bits/stdc++.h>
#define ll long long 
#define track(a) cout<<a<<endl;
#define track2(a,b) cout<<a<<" "<<b<<endl;
using namespace std;
bool poss(ll arr[],ll mid,ll reh,ll n)
{
	ll val=0;
	for(ll i=0;i<n;i++)
	{
		if(arr[i]>mid)
			val+=arr[i]-mid;
		if(val>=reh)
			return true;
	}
	return false;
}
void find(ll arr[],ll maxh,ll reh,ll n)
{
	ll low=1;
	ll high=maxh;
	ll result=maxh;
	while(low<high)
	{
//		track2(low,high);
		ll mid=low+(high-low)/2;
		if(poss(arr,mid,reh,n))
		{
			result=mid;
			low=mid+1;
		}
		else
			high=mid;
	}
	printf("%lld",result);
}
int main()
{
	ll n,reh;
	scanf("%lld%lld",&n,&reh);
	ll arr[1000000];
	ll maxh=0;
	for(ll i=0;i<n;i++)
	{
		scanf("%lld",&arr[i]);
		if(maxh<arr[i])
			maxh=arr[i];
	}
	find(arr,maxh,reh,n);
	return 0;
}
