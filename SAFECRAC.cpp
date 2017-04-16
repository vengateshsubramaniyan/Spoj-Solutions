#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
int main()
{
	vector< vector< ll > > a(2,vector<ll>(10,1));
	vector< ll > result(100001);
	result[1]=10;
	for(int i=2;i<=100000;i++)
	{
		int in=i%2;
		ll res=0;
		a[in][0]=(a[1-in][7])%mod;
		a[in][1]=(a[1-in][2]+a[1-in][4])%mod;
		a[in][2]=(a[1-in][1]+a[1-in][3]+a[1-in][5])%mod;
		a[in][3]=(a[1-in][2]+a[1-in][6])%mod;
		a[in][4]=(a[1-in][1]+a[1-in][7]+a[1-in][5])%mod;
		a[in][5]=(a[1-in][2]+a[1-in][4]+a[1-in][6]+a[1-in][8])%mod;
		a[in][6]=(a[1-in][5]+a[1-in][3]+a[1-in][9])%mod;
		a[in][7]=(a[1-in][0]+a[1-in][4]+a[1-in][8])%mod;
		a[in][8]=(a[1-in][5]+a[1-in][7]+a[1-in][9])%mod;
		a[in][9]=(a[1-in][6]+a[1-in][8])%mod;
		for(int j=0;j<10;j++)
			res=(res+a[in][j])%mod;
		result[i]=res;	
	}
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		printf("%lld\n",result[n]);
	}
	return 0;
}
