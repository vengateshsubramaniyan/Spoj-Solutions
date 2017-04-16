#include<bits/stdc++.h>
#define ll long long
using namespace std;
void construct(ll arr[],ll seg[],ll s,ll e,ll in)
{
	if(s==e)
	{
		seg[in]=arr[s]*arr[s];
		return;
	}
	ll m=s+(e-s)/2;
	construct(arr,seg,s,m,in*2+1);
	construct(arr,seg,m+1,e,in*2+2);
	seg[in]=seg[in*2+1]+seg[in*2+2];
}
ll find(ll seg[],ll s,ll e,ll ss,ll ee,ll in)
{
	if(ss>e || ee<s)
		return 0;
	if(ss<= s && ee>=e)
		return seg[in];
	ll m=s+(e-s)/2;
	ll l=find(seg,s,m,ss,ee,in*2+1);
	ll r=find(seg,m+1,e,ss,ee,in*2+2);
	return l+r;
}
void changeval(int op,ll seg[],ll s,ll e,ll ss,ll ee,ll in,ll val)
{
	if(ss>e || ee<s)
		return;
	if(s==e)
	{
		if(s>=ss && s<=ee)
		{
			if(op==1)
			{
				val+=sqrt(seg[in]);
				seg[in]=val*val;
			}
			else
			{
				seg[in]=val*val;
			}
		}
		return;
	}
	ll m=s+(e-s)/2;
	changeval(op,seg,s,m,ss,ee,in*2+1,val);
	changeval(op,seg,m+1,e,ss,ee,in*2+2,val);
	seg[in]=seg[in*2+1]+seg[in*2+2];
}
int main()
{
	int test;
	scanf("%d",&test);
	for(int t=1;t<=test;t++)
	{
		ll n,q;
		scanf("%lld%lld",&n,&q);
		ll arr[n];
		for(ll i=0;i<n;i++)
			scanf("%lld",&arr[i]);
		ll n1=(ll)(ceil(log2(n)));
		n1=2*(ll)pow(2,n1)-1;
		ll seg[n1];
		construct(arr,seg,0,n-1,0);
		int op;
		ll start,end,val;
		printf("Case %d:\n",t);
		while(q--)
		{
			scanf("%d %lld %lld",&op,&start,&end);
			start--;
			end--;
			if(op==2)
			{
				printf("%lld\n",find(seg,0,n-1,start,end,0));
			}
			else
			{
				scanf("%lld",&val);
				changeval(op,seg,0,n-1,start,end,0,val);
			}
		}
	}
}
