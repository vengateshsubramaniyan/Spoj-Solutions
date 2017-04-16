#include<bits/stdc++.h>
using namespace std;
int main()
{
	int k,n;
	scanf("%d%d",&k,&n);
	int wei[n+1];
	int val[n+1];
	for(int i=1;i<=n;i++)
		scanf("%d%d",&val[i],&wei[i]);
	int dp[k+1];
	for(int i=0;i<=n;i++)
	{
		for(int j=k;j>=0;j--)
		{
			if(i==0 || j==0)
				dp[j]=0;
			else if(wei[i]<=j)
				dp[j]=max(val[i]+dp[j-wei[i]],dp[j]);
		}
	}
	printf("%d",dp[k]);
	return 0;
}
