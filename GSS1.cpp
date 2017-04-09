#include<bits/stdc++.h>
#define vll vector<long long> 
#define ll long long
#define lc i*2+1
#define rc i*2+2
using namespace std;
ll construct(vll &pre,vll &suff,vll &res,vll &tsum,vector<int> &arr,ll s,ll e,ll i)
{
	if(s==e)
	{
		pre[i]=arr[s];
		suff[i]=arr[s];
		res[i]=arr[s];
		tsum[i]=arr[s];
		return arr[s];
	}
	ll m=s+(e-s)/2;
	ll ls=construct(pre,suff,res,tsum,arr,s,m,lc);
	ll rs=construct(pre,suff,res,tsum,arr,m+1,e,rc);
	res[i]=max(res[lc],res[rc]);
	pre[i]=max(pre[lc],ls+pre[rc]);
	suff[i]=max(suff[rc],suff[lc]+rs);
	res[i]=max(res[i],max(suff[i],pre[i]));
	res[i]=max(suff[lc]+pre[rc],res[i]);
	tsum[i]=ls+rs;
	return ls+rs;
}
ll find(vll &pre,vll &suff,vll &res,vll &tsum,int s,int e,int &x,int &y,int i,ll &result,ll &p,ll &su)
{
	if(s>e || y<s || x>e)
		return INT_MIN;
	if(x<=s && y>=e)
	{
		p=pre[i];
		su=suff[i];
		result=max(result,res[i]);
		return tsum[i];
	}
	int m=s+(e-s)/2;
	ll p1,su1,p2,su2;
	ll ls=find(pre,suff,res,tsum,s,m,x,y,lc,result,p1,su1);
	ll rs=find(pre,suff,res,tsum,m+1,e,x,y,rc,result,p2,su2);
	if(ls==INT_MIN || rs==INT_MIN)
	{
		if(ls!=INT_MIN)
		{
			p=p1;
			su=su1;
			return ls;
		}
		else if(rs!=INT_MIN)
		{
			p=p2;
			su=su2;
			return rs;
		}
		else
		{
			p=INT_MIN;
			su=INT_MIN;
			return INT_MIN;
		}
	}
	p=max(p1,ls+p2);
	su=max(su2,su1+rs);
	ll tres=max(p,su);
	tres=max(tres,su1+p2);
	result=max(result,tres);
	return ls+rs;
}
int main()
{
	int n;
	scanf("%d",&n);
	vector<int> arr(n);
	for(int i=0;i<n;i++)
	{
		int t;
		scanf("%d",&t);
		arr[i]=t;
	}
	ll m;
	ll n1=(int)(ceil(log2(n)));
	n1=2*pow(2,n1)-1;
	vll pre(n1,0);
	vll suff(n1,0);
	vll res(n1,0);
	vll tsum(n1,0);
	scanf("%lld",&m);
	construct(pre,suff,res,tsum,arr,0,n-1,0);
//	for(ll i=1;i<n1;i++)
//	{
//		cout<<pre[i]<<" "<<suff[i]<<" "<<res[i]<<endl;
//	}
	while(m--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		x--;
		y--;
		long long result=INT_MIN;
		ll p,su;
		find(pre,suff,res,tsum,0,n-1,x,y,0,result,p,su);
		printf("%lld\n",result);
	}
	return 0;
}
