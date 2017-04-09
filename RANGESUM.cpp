#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	ll n;
	scanf("%lld",&n);
	ll a[n];
	for(ll i=0;i<n;i++)
		scanf("%lld",&a[i]);
	vector< ll > pre;
	pre.push_back(0);
	for(ll i=n-1;i>=0;i--)
	{
		ll val=a[i]+pre.back();
//		cout<<val<<endl;
		pre.push_back(val);
	}
	ll q;
	scanf("%lld",&q);
	while(q--)
	{
		int op;
		scanf("%d",&op);
		if(op==1)
		{
			ll l,r;
			scanf("%lld%lld",&l,&r);
			l=n-l+1;
			r=n-r;
			printf("%lld\n",pre[l]-pre[r]);
		}
		else
		{
			ll val;
			scanf("%lld",&val);
			val+=pre.back();
			n++;
			pre.push_back(val);
		}
	}
	return 0;
}
