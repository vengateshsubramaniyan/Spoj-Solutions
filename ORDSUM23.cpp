#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
int main()
{
	int dp[1000001];
	dp[0]=1;dp[1]=0;dp[2]=1,dp[3]=1;
	for(int i=4;i<=1000000;i++)
		dp[i]=(dp[i-2]+dp[i-3])%mod;
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		printf("%d\n",dp[n]);
	}
	return 0;
}
