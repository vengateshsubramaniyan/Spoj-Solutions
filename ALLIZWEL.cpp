#include<bits/stdc++.h>
using namespace std;
char arr[101][101];
char s[]="ALLIZZWELL";
int row[]={1,0,-1,0,1,1,-1,-1};
int col[]={0,1,0,-1,1,-1,1,-1};
bool dfs(int i,int j,int l,int r,int c,vector< vector<bool> > &visit)
{
	if(l==10)
		return true;
	for(int k=0;k<8;k++)
	{
		int ci=i+row[k];
		int cj=j+col[k];
		if(ci>=0 && ci<r && cj>=0 && cj<c && !visit[ci][cj] && arr[ci][cj]==s[l])
		{
			visit[ci][cj]=true;
			if(dfs(ci,cj,l+1,r,c,visit))
				return true;
			visit[ci][cj]=false;
		}
	}
	return false;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int r,c;
		scanf("%d%d",&r,&c);
		vector< vector<bool> > visit(r,vector<bool>(c,false));
		for(int i=0;i<r;i++)
		{
			scanf("%s",arr[i]);
		}
		bool fo=false;
		for(int i=0;i<r && !fo;i++)
		{
			for(int j=0;j<c && !fo;j++)
			{
				if(arr[i][j]=='A')
				{
					if(dfs(i,j,1,r,c,visit))
						fo=true;
				}
			}
		}
		fo==true?printf("YES"):printf("NO");
		printf("\n");
	}
	return 0;
}
