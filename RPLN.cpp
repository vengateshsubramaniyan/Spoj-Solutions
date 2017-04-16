#include<bits/stdc++.h>
#define ll long long
using namespace std;
void construct(ll arr[],ll seg[],ll s,ll e,ll i)
{
	if(s==e)
	{
		seg[i]=arr[s];
		return;
	}
	ll m=s+(e-s)/2;
	construct(arr,seg,s,m,i*2+1);
	construct(arr,seg,m+1,e,i*2+2);
	seg[i]=min(seg[i*2+1],seg[i*2+2]);	
}
ll query(ll seg[],ll qs,ll qe,ll ss,ll se,ll in)
{
	if(qs<=ss && qe>=se)
		return seg[in];
	if(qe<ss || qs>se)
		return INT_MAX;
	ll m=ss+(se-ss)/2;
	return min(query(seg,qs,qe,ss,m,in*2+1),query(seg,qs,qe,m+1,se,in*2+2));
}
int main()
{
	ll test;
	scanf("%lld",&test);
	for(ll t=1;t<=test;t++)
	{
		ll n,q;
		scanf("%lld%lld",&n,&q);
		ll arr[n];
		for(ll i=0;i<n;i++)
			scanf("%lld",&arr[i]);
		ll n1=(ceil(log2(n)));
		n1=2*(ll)pow(2,n1)-1;
		ll seg[n1];
		construct(arr,seg,0,n-1,0);
		printf("Scenario #%lld:\n",t);
		while(q--)
		{
			ll s,e;
			scanf("%lld%lld",&s,&e);
			s--;
			e--;
			printf("%lld\n",query(seg,s,e,0,n-1,0));
		}
	}
	return 0;
}
