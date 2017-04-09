#include<bits/stdc++.h>
#define debug(a) cout<<a<<" ";
using namespace std;
int row[]={1,-1,0,0};
int col[]={0,0,1,-1};
int visit[41][41];
char a[41][41];
int r,c,k;
bool dfs(int i,int j,int s,bool trea)
{
//	cout<<i<<" "<<j<<endl;
	if(s>k)
		return false;
	visit[i][j]=s;
	for(int l=0;l<4;l++)
	{
		int ci=i+row[l];
		int cj=j+col[l];
		if(ci>=0 && ci<r && cj>=0 && cj<c && a[ci][cj]!='#')
		{
			bool found=false;
			if(visit[ci][cj]!=-1)
			{
				if(s+visit[ci][cj]<=k && trea)
					return true;
			}
			else
			{
				if(a[ci][cj]=='s')
					found=dfs(ci,cj,s+1,trea);
				else if(a[ci][cj]=='x')
				{
					if(visit[i][j]*2<=k)
						return true;
					found=dfs(ci,cj,s,true);
				}
				else if(a[ci][cj]=='@')
				{
					if(trea)
					{
						if(visit[i][j]<=k)
							return true;
					}
					else
					{
						found=dfs(ci,cj,0,false);
					}
				}
				else
				{
					found=dfs(ci,cj,s,trea);
				}
			}
			if(found)
				return true;
		}
	}
	visit[i][j]=-1;
	return false;
}
int main()
{
	scanf("%d%d%d",&r,&c,&k);
	for(int i=0;i<r;i++)
		scanf("%s",a[i]);
	bool found=false;
	memset(visit,-1,sizeof(visit));
	for(int i=0;i<r;i++)
	{
		if(found)
			break;
		for(int j=0;j<c;j++)
		{
			if(a[i][j]=='@')
			{
				if(dfs(i,j,0,false))
					found=true;
				if(found)
					break;
			}
		}
	}
	found?printf("SUCCESS"):printf("IMPOSSIBLE");
	return 0;
}
