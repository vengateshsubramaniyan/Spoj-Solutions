#include<bits/stdc++.h>
#define ll long long
#define vll vector<ll>
#define lc i*2+1
#define rc i*2+2
using namespace std;
void update(vll &arr,vll &lazy,ll s,ll e,ll x,ll y,ll val,ll i)
{
	if(lazy[i]!=0)
	{
		arr[i]+=(e-s+1)*lazy[i];
		if(s!=e)
		{
			lazy[lc]+=lazy[i];
			lazy[rc]+=lazy[i];
		}
		lazy[i]=0;
	}
	if(s>e || x>e || y<s)
		return ;
	if(x<=s && y>=e)
	{
		arr[i]+=(e-s+1)*val;
		if(s!=e)
		{
			lazy[lc]+=val;
			lazy[rc]+=val;
		}
		return ;
	}
	ll m=s+(e-s)/2;
	update(arr,lazy,s,m,x,y,val,lc);
	update(arr,lazy,m+1,e,x,y,val,rc);
	arr[i]=arr[lc]+arr[rc];
}
ll find(vll &arr,vll &lazy,ll s,ll e,ll x,ll y,ll i)
{
	if(lazy[i]!=0)
	{
		arr[i]+=(e-s+1)*lazy[i];
		if(s!=e)
		{
			lazy[lc]+=lazy[i];
			lazy[rc]+=lazy[i];
		}
		lazy[i]=0;
	}
	if(s>e || x>e || y<s)
		return 0;
	if(x<=s && y>=e)
		return arr[i];
	ll l,r,m;
	m=s+(e-s)/2;
	l=find(arr,lazy,s,m,x,y,lc);
	r=find(arr,lazy,m+1,e,x,y,rc);
	arr[i]=arr[lc]+arr[rc];
	return l+r;
}
int main()
{
	ll t;
	scanf("%lld",&t);
	while(t--)
	{
		 ll n,n1,c;
		 scanf("%lld%lld",&n,&c);
		 n1=(int)(ceil(log2(n)));
		 n1=2*pow(2,n1)-1;
		 vll arr(n1,0);
		 vll lazy(n1,0);
		 while(c--)
		 {
		 	int op;
		 	scanf("%d",&op);
		 	if(op==0)
		 	{
		 		ll x,y,val;
		 		scanf("%lld%lld%lld",&x,&y,&val);
		 		x--;
		 		y--;
		 		update(arr,lazy,0,n-1,x,y,val,0);
//		 		for(ll i=0;i<n1;i++)
//		 			cout<<i<<" "<<arr[i]<<" "<<lazy[i]<<endl;
		 	}
		 	else
		 	{
		 		ll x,y;
		 		scanf("%lld%lld",&x,&y);
		 		x--;
		 		y--;
		 		printf("%lld\n",find(arr,lazy,0,n-1,x,y,0));
		 	}
//		 	cout<<endl;
		 }
		 arr.clear();
		 lazy.clear();
	}
	return 0;
}
