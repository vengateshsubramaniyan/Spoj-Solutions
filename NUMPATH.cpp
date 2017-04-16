#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	int dp[8][8];
	for(int i=0;i<8;i++)
	{
		for(int j=0;j<8;j++)
		{
			if(i==0 || j==0)
			{
				dp[i][j]=1;
			}
			else
				dp[i][j]=dp[i-1][j]+dp[i][j-1];
		}
	}
	scanf("%d",&t);
	while(t--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		printf("%d\n",dp[x-1][y-1]);
	}
	return 0;
}
