#include<bits/stdc++.h>
#define ll long long
using namespace std;
bool pos(ll work[],ll cost[],ll n,ll m,ll mid)
{
	for(int i=0;i<n;i++)
	{
		if(work[i]<mid)
			m-=((mid-work[i])*cost[i]);
		if(m<0)
			return false;
	}
	return true;
}
ll binarysearch(ll work[],ll cost[],ll n,ll m,ll low,ll high)
{
	ll result=low;
	while(low<high)
	{
		ll mid=low+(high-low)/2;
		if(pos(work,cost,n,m,mid))
		{
			if(mid>result)
				result=mid;
			low=mid+1;
		}
		else
			high=mid;
	}
	return result;
}
int main()
{
	ll t;
	scanf("%lld",&t);
	while(t--)
	{
		ll n,m;
		scanf("%lld%lld",&n,&m);
		ll work[n];
		ll cost[n];
		ll low=0;
		ll high=0;
		for(int i=0;i<n;i++)
		{
			scanf("%lld%lld",&work[i],&cost[i]);
			 if(work[i]<work[low])
				low=i;
			if(work[i]>work[high])
				high=i;
		}
		high=work[high]+((m/cost[high]));
		if(n==1)
			printf("%lld\n",high);
		else
			printf("%lld\n",binarysearch(work,cost,n,m,low,high));
	}
	return 0;
}
