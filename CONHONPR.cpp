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
int row[]={1,-1,0,0,1,-1,1,-1};
int col[]={0,0,1,-1,1,-1,-1,1};
bool ifneigh(int a[101][101],int i,int j,int r,int c)
{
	for(int k=0;k<8;k++)
	{
		int ci=i+row[k];
		int cj=j+col[k];
		if(ci>=0 && ci<r && cj>=0 && cj<c && a[ci][cj]==a[i][j])
			return true;
	}
	return false;
}
int main()
{
	int t,r,c;
	int a[101][101];
	scanf("%d",&t);
	bool dp[101];
	while(t--)
	{
		memset(dp,false,sizeof(dp));
		scanf("%d%d",&r,&c);
		for(int i=0;i<r;i++)
			for(int j=0;j<c;j++)
				scanf("%d",&a[i][j]);
		int res=0;
		for(int i=0;i<r;i++)
		{
			for(int j=0;j<c;j++)
			{
				if(a[i][j]!=-1 && !dp[a[i][j]])
				{
					if(ifneigh(a,i,j,r,c))
					{
						dp[a[i][j]]=true;
						res++;
					}
				}
			}
		}
		printf("%d\n",res);
	}
	return 0;
}


