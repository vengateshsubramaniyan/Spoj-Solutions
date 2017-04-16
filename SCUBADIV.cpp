#include<bits/stdc++.h>
#define INF 900000
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int ao,an;
		scanf("%d%d",&ao,&an);
		int n;
		scanf("%d",&n);
		int a[n+1][3];
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
		}
		int dp[n+1][22][80];
		for(int k=0;k<=n;++k)
		{
    		for(int i=0;i<=21;++i)
			{
        		for(int j=0;j<=79;++j)
				{
            		if(k==0)
					{
                	dp[k][i][j] = INF;
                	if(i==0 && j==0)
						 dp[k][i][j] = 0;
            		}
					else	
					{
                		dp[k][i][j] = min(dp[k-1][i][j], a[k][2] + dp[k-1][max(0,i-a[k][0])][max(0,j-a[k][1])]);
            		}
        		}
    		}
		}
		printf("%d\n",dp[n][ao][an]);	
	}
	return 0;
}
