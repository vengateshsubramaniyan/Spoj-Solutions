#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	ll dp[11][2001];
	for(int i=1;i<=10;i++)
	{
		dp[i][0]=0;
		for(int j=1;j<=2000;j++)
		{
			if(i==1)
				dp[i][j]=j;
			else
			{
				dp[i][j]=dp[i][j-1]+dp[i-1][j/2];
			}
		}
	}
	int test;
	scanf("%d",&test);
	for(int t=1;t<=test;t++)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		printf("Data set %d: %d %d %lld\n",t,n,m,dp[n][m]);
	}
	return 0;
}
