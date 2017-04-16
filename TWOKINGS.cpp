#include<bits/stdc++.h>
using namespace std;
int row[]={1,-1,0,0,1,1,-1,-1};
int col[]={0,0,1,-1,-1,1,-1,1};
void dfs(char s[11][11],int i,int j,int r,int c,char che)
{
	s[i][j]='1';
	for(int k=0;k<8;k++)
	{
		int ci=i+row[k];
		int cj=j+col[k];
		if(ci>=0 && ci<r && cj>=0 && cj<c && s[ci][cj]==che)
			dfs(s,ci,cj,r,c,che);
	}
}
int main()
{
	int t;
	scanf("%d",&t);
	char s[11][11];
	while(t--)
	{
		int r,c;
		scanf("%d%d",&r,&c);
		for(int i=0;i<r;i++)
			scanf("%s",s[i]);
		int xc=0;
		for(int i=0;i<r;i++)
		{
			for(int j=0;j<c;j++)
			{
				if(s[i][j]=='X')
				{
					dfs(s,i,j,r,c,'X');
					xc++;
				}
			}
		}
		int oc=0;
		for(int i=0;i<r;i++)
		{
			for(int j=0;j<c;j++)
			{
				if(s[i][j]=='O')
				{
					dfs(s,i,j,r,c,'O');
					oc++;
				}
			}
		}
		if(xc<oc)
			printf("O\n");
		else if(xc>=oc)
			printf("X\n");
	}
	return 0;
}
