#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	int test;
	scanf("%d",&test);
	ll te=1;
	for(int t=1;t<=test;t++)
	{
		int n;
		scanf("%d",&n);
		ll a[n+1];
		for(int i=0;i<n;i++)
			scanf("%lld",&a[i]);
		a[n]=1;
		for(int i=n-1;i>=0;i--)
			a[i]=max(te,a[i+1]-a[i]);
		printf("Scenario #%d: %lld\n",t,a[0]);
	}
	return 0;
}
