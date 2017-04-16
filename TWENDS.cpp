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
int findsol(int a[],int dp[1001][1001],int i,int j,bool first)
{
	if(i>=j)
		return 0;
	if(dp[i][j]!=-1)
		return dp[i][j];
	if(first)
	{
		dp[i][j]=max(a[i]+findsol(a,dp,i+1,j,false),a[j]+findsol(a,dp,i,j-1,false));
	}
	else
	{
		if(a[i]>=a[j])
			dp[i][j]=findsol(a,dp,i+1,j,true);
		else
			dp[i][j]=findsol(a,dp,i,j-1,true);
	}
	return dp[i][j];
}
int main()
{
	int a[1001];
	int dp[1001][1001];
	int n;
	scanf("%d",&n);
	int t=1;
	while(n)
	{
		int sum=0;
		memset(dp,-1,sizeof(dp));
		for(int i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			sum+=a[i];
		}
		int res=findsol(a,dp,0,n-1,true);
		sum-=res;
//		bug2(sum,res);
		printf("In game %d, the greedy strategy might lose by as many as %d points.\n",t++,res-sum);
		scanf("%d",&n);
	}
	return 0;
}


