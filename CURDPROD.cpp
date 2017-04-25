#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define ull unsigned long long
#define pi pair<int,int>
#define pll pair<ll,ll>
#define vl vector< ll >
#define bug(a) cout<<a<<endl;
#define bug2(a,b) cout<<a<<" "<<b<<endl;
#define bug3(a,b,c) cout<<a<<" "<<b<<" "<<c<<endl;
using namespace std;
bool pos(ll a[],int n,ll tar,ll mid)
{
	for(int i=0;i<n;i++)
	{
		tar-=(mid/a[i]);
		if(tar<=0)
			return true;
	}
	return false;
}
void binary(ll a[],int n,ll tar)
{
	ll low=0;
	ll high=1e19;
	ll res=0;
	while(low<high)
	{
		ll mid=low+(high-low)/2;
		if(pos(a,n,tar,mid))
		{
			res=mid;
			high=mid;
		}
		else
			low=mid+1;
	}
	printf("%lld\n",res);
}
int main()
{
	int t,n;
	ll tar;
 	ll a[10001];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%lld",&n,&tar);
		for(int i=0;i<n;i++)
			scanf("%lld",&a[i]);
		binary(a,n,tar);	
	}
	return 0;
}


