#include<bits/stdc++.h>
using namespace std;
int main()
{
	int test;
	scanf("%d",&test);
	for(int t=1;t<=test;t++)
	{
		int n,k;
		scanf("%d%d",&n,&k);
		int arr[n];
		for(int i=0;i<n;i++)
		{
			scanf("%d",&arr[i]);
		}
		int dp[n+1][k+1];
		for(int i=0;i<=n;i++)
		{
			for(int j=0;j<=k;j++)
			{
				if(i==0 || j==0)
					dp[i][j]=0;
				else if(i==1)
				{
					if(j>=arr[i-1])
						dp[i][j]=arr[i-1];
					else
						dp[i][j]=0;
				}
				else if(arr[i-1]<=j)
				{
					dp[i][j]=max(arr[i-1]+dp[i-2][j-arr[i-1]],dp[i-1][j]);
				}
				else
				{
					dp[i][j]=max(dp[i-1][j],dp[i-2][j]);
				}
			}
		}
		printf("Scenario #%d: %d\n",t,dp[n][k]);
	}	
	return 0;
}
