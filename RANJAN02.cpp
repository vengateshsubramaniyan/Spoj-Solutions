#include<bits/stdc++.h>
#define ll long long unsigned 
#define ld long double
#define pi pair<int,int>
#define pll pair<ll,ll>
#define vl vector< ll >
#define bug(a) cout<<a<<endl;
#define bug2(a,b) cout<<a<<" "<<b<<endl;
#define bug3(a,b,c) cout<<a<<" "<<b<<" "<<c<<endl;
using namespace std;
int main()
{
	ll dp[36];
	dp[1]=2;
	for(int i=2;i<=35;i++)
	{
		dp[i]=(dp[i-1]*3)+2;
	}
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		cout<<dp[n]<<endl;
	}
	return 0;
}


