#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	int a[1005];
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		bool dp[n+1];
		memset(dp,false,sizeof(dp));
		bool result=true;
		for(int i=1;i<=n;i++)
		{
			int val=a[i];
			if(val==n)
			{
				result=false;
				break;
			}
			if(dp[val+1]==false)
				dp[val+1]=true;
			else if(dp[n-val]==false)
				dp[n-val]=true;
			else
			{
				result=false;
				break;
			}
		}
		result?printf("YES\n"):printf("NO\n");
	}
	return 0;
}
