#include<bits/stdc++.h>
#define ll long long 
#define pll pair<ll,ll>
using namespace std;
void construct(ll arr[],pll seg[],ll s,ll e,ll i)
{
	if(s==e)
	{
		seg[i].first=arr[s];
		seg[i].second=arr[s];
		return ;
	}
	ll m=s+(e-s)/2;
	construct(arr,seg,s,m,i*2+1);
	construct(arr,seg,m+1,e,i*2+2);
	seg[i].first=seg[i*2+1].first+seg[i*2+2].first;
	seg[i].second=min(seg[i*2+1].second,seg[i*2+2].second);
}
void eat(pll seg[],ll &x,ll &y,ll s,ll e,ll i)
{
	if(s==e && s==y)
	{
		seg[i].first=x;
		seg[i].second=x;
		return ;
	}
	if(s==e)
		return;
	ll m=s+(e-s)/2;
	if(y<=m)
		eat(seg,x,y,s,m,i*2+1);
	else
		eat(seg,x,y,m+1,e,i*2+2);
	seg[i].first=seg[i*2+1].first+seg[i*2+2].first;
	seg[i].second=min(seg[i*2+1].second,seg[i*2+2].second);
}
pll count(pll seg[],ll qs,ll qe,ll s,ll e,ll i)
{
	if(qs>e || qe<s)
	{
		pll temp;
		temp.first=0;
		temp.second=INT_MAX;
		return temp;
	}
	if(qs<=s && qe>=e)
		return seg[i];
	ll m=s+(e-s)/2;
	pll t1=count(seg,qs,qe,s,m,i*2+1);
	pll t2=count(seg,qs,qe,m+1,e,i*2+2);
	t1.first+=t2.first;
	t1.second=min(t1.second,t2.second);
	return t1;
}
int main()
{
	ll n;
	scanf("%lld",&n);
	ll arr[n];
	for(int i=0;i<n;i++)
		scanf("%lld",&arr[i]);
	ll p,n1;
	n1=(ll)(ceil(log2(n)));
	n1=2*pow(2,n1)-1;
	pll seg[n1];
	construct(arr,seg,0,n-1,0);
	scanf("%lld",&p);
	char op[10];
	while(p--)
	{
		scanf("%s",op);
		if(strcmp(op,"EAT")==0)
		{
			ll x,y;
			scanf("%lld%lld",&x,&y);
			arr[y]-=x;
			if(arr[y]<=0)
				arr[y]=0;
			eat(seg,arr[y],y,0,n-1,0);
		}
		else if(strcmp(op,"GROW")==0)
		{
			ll x,y;
			scanf("%lld%lld",&x,&y);
			arr[y]+=x;
			eat(seg,arr[y],y,0,n-1,0);
		}
		else
		{
			ll x,y;
			scanf("%lld%lld",&x,&y);
			pll result=count(seg,x,y,0,n-1,0);
			printf("%lld\n",result.first-result.second);
		}
	}
	return 0;
}
