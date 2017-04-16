#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define mod 2147483647
#define pi pair<int,int>
#define pll pair<ll,ll>
#define vl vector< ll >
#define bug(a) cout<<a<<endl;
#define bug2(a,b) cout<<a<<" "<<b<<endl;
#define bug3(a,b,c) cout<<a<<" "<<b<<" "<<c<<endl;
using namespace std;
char grid[1001][1001];
int row[]={1,-1,0,0};
int col[]={0,0,1,-1};
bool possible(int n)
{
	queue< pair<int,int> > q;
	q.push(pi(0,0));
	bool visit[n][n];
	memset(visit,false,sizeof(visit));
	visit[0][0]=true;
	while(!q.empty())
	{
		int i=q.front().first;
		int j=q.front().second;
		q.pop();
		if(i==n-1 && j==n-1)
			return true;
		for(int k=0;k<4;k++)
		{
			int ci=i+row[k];
			int cj=j+col[k];
			if(ci>=0 && ci<n && cj>=0 && cj<n && visit[ci][cj]==false && grid[ci][cj]!='#')
			{
				visit[ci][cj]=true;
				if(ci==n-1 && cj==n-1)
					return true;
				q.push(pi(ci,cj));
			}
		}
	}
	return false;
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%s",grid[i]);
	ll dp[n][n];
	memset(dp,0,sizeof(dp));
	for(int i=0;i<n;i++)
	{
		if(grid[0][i]=='#')
			break;
		dp[0][i]=1;
	}
	for(int i=0;i<n;i++)
	{
		if(grid[i][0]=='#')
			break;
		dp[i][0]=1;
	}
	for(int i=1;i<n;i++)
	{
		for(int j=1;j<n;j++)
		{
			if(grid[i][j]=='#')
				dp[i][j]=0;
			else
				dp[i][j]=(dp[i-1][j]+dp[i][j-1])%mod;
		}
	}
	if(dp[n-1][n-1]!=0)
		printf("%lld",dp[n-1][n-1]);
	else
	{
		if(possible(n))
			printf("THE GAME IS A LIE");
		else
			printf("INCONCEIVABLE");
	}
	return 0;
}


