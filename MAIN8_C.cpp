#include<bits/stdc++.h>
#define ll long long
using namespace std;
static bool cmpp(const ll a,const ll b)
{
	return a>b;
}
ll candy[50001];
ll n,k;
bool pos(ll mid)
{
	int temp=k;
	for(ll i=0;i<n;i++)
	{
		int q=candy[i]/mid;
		temp-=q;
		if(temp<=0)
			return true;
	}
	return false;
}
void bs(ll s,ll e,ll &result)
{
	while(s<e)
	{
		ll mid=s+(e-s)/2;
		if(pos(mid))
		{
			if(result<mid)
				result=mid;
			s=mid+1;
		}
		else
		{
			e=mid;
		}
	}
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld%lld",&n,&k);
		ll tq=0,total=0;
		for(ll i=0;i<n;i++)
		{
			scanf("%lld",&candy[i]);
			if(tq<candy[i])
				tq=candy[i];
			total+=candy[i];
		}
		if(k==1)
			printf("%lld\n",tq);
		else if(total<k)
		{
			printf("0\n");
		}
		else
		{
			sort(candy,candy+n,cmpp);
			ll result=0;
			bs(0,tq,result);
			printf("%lld\n",result);
		}
	}
	return 0;
}
