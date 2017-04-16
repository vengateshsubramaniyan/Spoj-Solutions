#include<bits/stdc++.h>
#define ll long long
using namespace std;
static bool com(const pair<int,ll> a,const pair<int,ll> b)
{
	return a.second<=b.second;
}
int main()
{
	int t;
	scanf("%d",&t);
	vector< pair<int,ll> > arr(t);
	vector< ll > re(t);
	for(int i=0;i<t;i++)
	{
		arr[i].first=i;
		scanf("%lld",&arr[i].second);
		re[i]=arr[i].second;
	}
	sort(arr.begin(),arr.end(),com);
	vector< pair<ll,ll> > result(t);
	ll s=1,e=1,r=1;
	for(int i=0;i<t;i++)
	{
		ll in = arr[i].second;
		while(e<in)
		{
			r++;
			s=e+1;
			e+=r;
		}
		if(r%2!=0)
		{
			in=in-s;
			result[arr[i].first].first=r-in;
			result[arr[i].first].second=1+in;
		}
		else
		{
			in=in-s;
			result[arr[i].first].first=1+in;
			result[arr[i].first].second=r-in;
		}
	}
	for(int i=0;i<t;i++)
		printf("TERM %lld IS %lld/%lld\n",re[i],result[i].first,result[i].second);
	return 0;
}
