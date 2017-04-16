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
int main()
{
	int n;
	scanf("%d",&n);
	int dp[2][3];
	dp[1][0]=1,dp[1][1]=1,dp[1][2]=1;
	for(int i=2;i<=n;i++)
	{
		int in=i&1;
		dp[in][0]=dp[1-in][0]+dp[1-in][1];
		dp[in][1]=dp[1-in][0]+dp[1-in][1]+dp[1-in][2];
		dp[in][2]=dp[1-in][1]+dp[1-in][2];
	}
	int in=n&1;
	int res=dp[in][0]+dp[in][1]+dp[in][2];
	printf("%d",res);
	return 0;
}


