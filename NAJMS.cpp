#include<bits/stdc++.h>
#define ll long long
#define left(i) 2*i+1
#define right(i) 2*i+2
using namespace std;
void create(ll a[],ll seg[],ll s,ll e,ll i)
{
	if(s==e)
	{
		seg[i]=a[s];
		return;
	}
	ll m=s+(e-s)/2;
	create(a,seg,s,m,left(i));
	create(a,seg,m+1,e,right(i));
	seg[i]=0;
}
void add(ll seg[],ll ss,ll se,ll qs,ll qe,ll k,ll i)
{
	if(seg[i]!=0)
	{
		if(ss!=se)
		{
			seg[left(i)]+=seg[i];
			seg[right(i)]+=seg[i];
			seg[i]=0;
		}
	}
	if(qe< ss || ss> se || qs> se)
		return;
	if(qs<=ss && qe>=se)
	{
		seg[i]+=k;
		return ;
	}
	ll m=ss+(se-ss)/2;
	add(seg,ss,m,qs,qe,k,left(i));
	add(seg,m+1,se,qs,qe,k,right(i));
}
void rem(ll seg[],ll s,ll e,ll pos,ll i)
{
	if(s > e || pos>e || pos< s)
		return;
	if(s==e)
	{
		if(s==pos)
			seg[i]=0;
		return;
	}
	if(seg[i]!=0)
	{
		if(s!=e)
		{
			seg[left(i)]+=seg[i];
			seg[right(i)]+=seg[i];
		}
		seg[i]=0;
	}
	ll m=s+(e-s)/2;
	if(pos<=m)
		rem(seg,s,m,pos,left(i));
	else
		rem(seg,m+1,e,pos,right(i));	
}
void find(ll seg[],ll s,ll e,ll pos,ll i,ll &result)
{
	if(s==e)
	{
		if(s==pos)
			result=seg[i];
		return;
	}
	if(seg[i]!=0)
	{
		if(s!=e)
		{
			seg[left(i)]+=seg[i];
			seg[right(i)]+=seg[i];
		}
		seg[i]=0;
	}
	ll m=s+(e-s)/2;
	if(pos<=m)
		find(seg,s,m,pos,left(i),result);
	else
		find(seg,m+1,e,pos,right(i),result);
}
int main()
{
	int test;
	scanf("%d",&test);
	for(int t=1;t<=test;t++)
	{
		printf("Case %d:\n",t);
		ll n,n1,q;
		scanf("%lld%lld",&n,&q);
		ll a[n];
		for(ll i=0;i<n;i++)
			scanf("%lld",&a[i]);
		n1=(ll)(ceil(log2(n)));
		n1=2*(ll)pow(2,n1)-1;
		ll seg[n1];
		create(a,seg,0,n-1,0);
		while(q--)
		{
			char op;
			scanf("\n%c",&op);
			if(op=='w')
			{
				ll s,e,k;
				scanf("%lld%lld%lld",&s,&e,&k);
				s--,e--;
				add(seg,0,n-1,s,e,k,0);
			}
			else if(op=='m')
			{
				ll s;
				scanf("%lld",&s);
				s--;
				rem(seg,0,n-1,s,0);
			}
			else
			{
				ll s;
				scanf("%lld",&s);
				s--;
				ll result=0;
				find(seg,0,n-1,s,0,result);
				printf("%lld\n",result);
			}
		}
	}
	return 0;
}
