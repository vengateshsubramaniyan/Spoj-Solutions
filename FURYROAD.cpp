#include<bits/stdc++.h>
using namespace std;
int row[]={1,-1,0,0,1,-1,1,-1};
int col[]={0,0,1,-1,1,-1,-1,1};
void dfs(bool a[1001][1001],int i,int j)
{
	a[i][j]=false;
	for(int k=0;k<8;k++)
	{
		int ci=i+row[k];
		int cj=j+col[k];
		if(ci>=0 && ci<=1000 && cj>=0 && cj<=1000 && a[ci][cj])
		{
			dfs(a,ci,cj);
		}
	}
}
int main()
{
	int test;
	scanf("%d",&test);
	bool a[1001][1001];
	for(int t=1;t<=test;t++)
	{
		memset(a,false,sizeof(a));
		int n;
		scanf("%d",&n);
		while(n--)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			a[x][y]=true;
		}
		int result=0;
		for(int i=0;i<=1000;i++)
		{
			for(int j=0;j<=1000;j++)
			{
				if(a[i][j])
				{
					result++;
					dfs(a,i,j);
				}
			}
		}
		printf("Case %d: %d\n",t,result);
	}
	return 0;
}
