#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll binaryfloor(vector<ll> &a,ll x,ll low,ll high,ll n)
{
	if(a[high]<x)
		return high;
	ll mid=low+(high-low)/2;
	if(mid+1<=n && a[mid]<x && a[mid+1]>=x)
		return mid;
	if(mid>1 && a[mid]>=x && a[mid-1]<x)
		return mid-1;
	if(a[mid]>=x)
		return binaryfloor(a,x,low,mid-1,n);
	return binaryfloor(a,x,mid+1,high,n);
}
ll binary(vector<ll> &a,ll x,ll low,ll high,ll n)
{
	if (x >= a[high])
    	return high;
    ll mid = (low+high)/2;
    if (a[mid] == x)
	{
		if(mid+1<=n && a[mid]>x)
			return mid;
		return binary(a,x,mid+1,high,n);
	}
    if (mid > 1 && a[mid-1] <= x && x < a[mid])
        return mid-1;
    if (x < a[mid])
        return binary(a,x,low, mid-1,n);
    return binary(a,x,mid+1,high,n);
}
int main()
{
	ll n;
	scanf("%lld",&n);
	vector< ll > a(n+1);
	for(ll i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	sort(a.begin(),a.end());
//	for(ll i=0;i<n;i++)
//		cout<<a[i]<<" ";
//	cout<<endl;
	ll res[n+1];
	res[0]=0;
	for(ll i=1;i<=n;i++)
	{
		res[i]=res[i-1]+a[i];
	}
	ll q;
	scanf("%lld",&q);
	while(q--)
	{
		ll a1,b1;
		scanf("%lld%lld",&a1,&b1);
		ll ai,bi;
		if(a1<=a[1])
			ai=0;
		else
		{
			ai=binaryfloor(a,a1,1,n,n);
		}
		if(b1>=a[n])
			bi=n;
		else
		{
			bi=binary(a,b1,1,n,n);
		}
//		cout<<ai<<" "<<bi<<endl;
		printf("%lld\n",res[bi]-res[ai]);
	}
	return 0;
}
