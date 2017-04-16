#include<bits/stdc++.h>
#define ll long long
#define left(i) 2*i+1
#define right(i) 2*i+2
using namespace std;
void segment(ll seg[],ll lazy[],ll s,ll e,ll qs,ll qe,ll i,ll val)
{
	if(lazy[i]!=0)
	{
		seg[i]=lazy[i];
		if(s!=e)
		{
			lazy[left(i)]=lazy[i];
			lazy[right(i)]=lazy[i];
		}
		lazy[i]=0;
	}
	if(s>e || qs>e || qe < s)
		return ;
	if(s>=qs && e<=qe)
	{
		seg[i]=val;
		if(s!=e)
		{
			lazy[left(i)]=val;
			lazy[right(i)]=val;
		}
		return;
	}
	ll mid=s+(e-s)/2;
	seg[i]=val;
	if(s!=e)
	{
		segment(seg,lazy,s,mid,qs,qe,left(i),val);
		segment(seg,lazy,mid+1,e,qs,qe,right(i),val);
	}
}
void find(ll seg[],ll lazy[],ll result[],ll s,ll e,ll i)
{
	if(lazy[i]!=0)
	{
		seg[i]=lazy[i];
		if(s!=e)
		{
			lazy[left(i)]=lazy[i];
			lazy[right(i)]=lazy[i];
		}
		lazy[i]=0;
	}
	if(s==e)
	{
		result[s]=seg[i];
		return;
	}
	if(s>e)
		return;
	ll mid=s+(e-s)/2;
	if(s!=e)
	{
		find(seg,lazy,result,s,mid,left(i));
		find(seg,lazy,result,mid+1,e,right(i));
	}
}
int main()
{
	ll t;
	scanf("%lld",&t);
	while(t--)
	{
		ll n2,n=0;
		scanf("%lld",&n2);
		vector < pair<ll,ll> > post;
		for(int i=0;i<n2;i++)
		{
			ll s,e;
			scanf("%lld%lld",&s,&e);
			if(e>n)
				n=e;
			s--;
			e--;
			post.push_back(pair<ll,ll>(s,e));
		}
		ll n1=(ll)(ceil(log2(n)));
		n1=(ll)(2*(ll)pow(2,n1))-1;
		ll seg[n1];
		ll lazy[n1];
		memset(seg,0,sizeof(ll)*n1);
		memset(lazy,0,sizeof(ll)*n1);
		for(ll i=0;i<n2;i++)
		{
			ll s=post[i].first;
			ll e=post[i].second;
			segment(seg,lazy,0,n-1,s,e,0,i+1);
		}
		ll result[n];
		find(seg,lazy,result,0,n-1,0);
		bool visit[n2+1];
		ll res=0;
		memset(visit,false,n2+1);
		for(ll i=0;i<n;i++)
		{
			ll val=result[i];
//			cout<<result[i]<<" ";
			if(val!=0 && visit[val]==false)
			{
				visit[val]=true;
				res++;
			}
		}
		printf("%lld",res);
		if(t!=0)
			printf("\n");
		post.clear();
	}
	return 0;
}
