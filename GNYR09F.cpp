#include<bits/stdc++.h>
using namespace std;
int main()
{
	int dp[101][101][2];
	dp[1][0][0]=1;
	dp[1][0][1]=1;
	for(int i=2;i<=100;i++)
	{
		for(int j=0;j<i;j++)
		{
			dp[i][j][0]=dp[i-1][j][0]+dp[i-1][j][1];
			dp[i][j][1]=dp[i-1][j][0];
			if(j>0)
				dp[i][j][1]+=dp[i-1][j-1][1];
		}
	}
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int tes,x,y;
		scanf("%d%d%d",&tes,&x,&y);
		printf("%d %d\n",tes,dp[x][y][0]+dp[x][y][1]);
	}
	return 0;
}
