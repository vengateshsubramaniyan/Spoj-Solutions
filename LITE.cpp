#include<bits/stdc++.h>
#define ll long long
#define left(i) 2*i+1
#define right(i) 2*i+2
using namespace std;
void toggle(ll seg[],ll lazy[],ll ss,ll se,ll qs,ll qe,ll in)
{
	if(lazy[in]!=0)
	{
		if(lazy[in]%2!=0)
		{
			seg[in]=(se-ss+1)-seg[in];
		}
		if(ss!=se)
		{
			lazy[left(in)]+=lazy[in];
			lazy[right(in)]+=lazy[in];
		}
		lazy[in]=0;
	}
	if(ss>se ||ss>qe || qs>se)
		return;
	if(ss>=qs && se<=qe)
	{
		seg[in]=(se-ss+1)-seg[in];
		if(ss!=se)
		{
			lazy[left(in)]+=1;
			lazy[right(in)]+=1;
		}
		return;
	}
	ll m=ss+(se-ss)/2;
	toggle(seg,lazy,ss,m,qs,qe,left(in));
	toggle(seg,lazy,m+1,se,qs,qe,right(in));
	seg[in]=seg[left(in)]+seg[right(in)];
}
ll find(ll seg[],ll lazy[],ll ss,ll se,ll qs,ll qe,ll in)
{
	if(lazy[in]!=0)
	{
		if(lazy[in]%2!=0)
		{
			seg[in]=(se-ss+1)-seg[in];
		}
		if(ss!=se)
		{
			lazy[left(in)]+=lazy[in];
			lazy[right(in)]+=lazy[in];
		}
		lazy[in]=0;
	}
	if(ss>se ||ss>qe || qs>se)
		return 0;
	if(ss>=qs && se<=qe)
	{
		return seg[in];
	}
	ll m=ss+(se-ss)/2;
	ll l=find(seg,lazy,ss,m,qs,qe,left(in));
	ll r=find(seg,lazy,m+1,se,qs,qe,right(in));
	seg[in]=seg[left(in)]+seg[right(in)];
	return l+r;
}
int main()
{
	ll n,m;
	scanf("%lld%lld",&n,&m);
	ll size=(ll)(ceil(log2(n)));
	size=2*(ll)pow(2,size)-1;
	ll seg[size];
	ll lazy[size];
	memset(seg,0,size*sizeof(ll));
	memset(lazy,0,size*sizeof(ll));
	while(m--)
	{
		int op;
		ll s,e;
		scanf("%d%lld%lld",&op,&s,&e);
		s--;
		e--;
		if(op==0)
		{
			toggle(seg,lazy,0,n-1,s,e,0);
		}
		else
		{
			printf("%lld\n",find(seg,lazy,0,n-1,s,e,0));
		}
	}
	return 0;
}
