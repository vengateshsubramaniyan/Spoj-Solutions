#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define pi pair<int,int>
#define pll pair<ll,ll>
#define vl vector< ll >
#define bug(a) cout<<a<<endl;
#define bug2(a,b) cout<<a<<" "<<b<<endl;
#define bug3(a,b,c) cout<<a<<" "<<b<<" "<<c<<endl;
using namespace std;
ll f[1000000];
ll a[1000000];
int main()
{
	memset(f,0,sizeof(f));
	for(ll i=1;i<=1000000;i++)
	{
		for(ll j=i+i;j<1000000;j+=i)
		{
			f[j]+=i;
		}
	}
	a[0]=0;
	a[1]=0;
	for(ll i=2;i<1000000;i++)
	{
		a[i]=a[i-1]+f[i];
	}
	int t;
	scanf("%d",&t);
	while(t--)
	{
		ll n;
		scanf("%lld",&n);
		printf("%lld\n",a[n]);
	}
	return 0;
}


