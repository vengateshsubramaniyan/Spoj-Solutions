#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	int dp[100001],count[100001];
	int a[100001],val;
	while(t--)
	{
		int n;
		scanf("%d",&n);
		memset(dp,0,sizeof(dp));
		int dis=0;
		for(int i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			if(dp[a[i]]==0)
				dis++;
			dp[a[i]]++;
			count[i]=dp[a[i]];
		}
		long long res=1;
		if(dis==n)
		{
			res=0;
		}
		for(int i=0;i<n;i++)
		{
			long long temp=n-i-1;
			temp-=(dp[a[i]]-count[i]);
//			cout<<temp<<endl;
			res+=temp;
		}
		printf("%lld\n",res);
	}
	return 0;
}
