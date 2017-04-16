#include<bits/stdc++.h>
using namespace std;
int n,m;
int row[]={1,0,-1,0};
int col[]={0,1,0,-1};
void dfs(char arr[251][251],bool visit[251][251],int i,int j,int &a,int &b,bool &bound)
{
	if(arr[i][j]=='k')
		a++;
	else if(arr[i][j]=='v')
		b++;
	visit[i][j]=true;
	if(i==0 || j==0 || i==n-1 || j==m-1)
		bound=false;
	for(int k=0;k<4;k++)
	{
		int ci=i+row[k];
		int cj=j+col[k];
		if(ci>=0 && ci<n && cj>=0 && cj<m && !visit[ci][cj] && arr[ci][cj]!='#')
		{
			dfs(arr,visit,ci,cj,a,b,bound);
		}
	}
}
int main()
{

	scanf("%d%d",&n,&m);
	char arr[251][251];
	for(int i=0;i<n;i++)
		scanf("%s",arr[i]);
	int wc=0,sc=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(arr[i][j]=='k')
				sc++;
			else if(arr[i][j]=='v')
				wc++;
		}
//		cout<<arr[i]<<endl;
	}
	bool visit[251][251];
	memset(visit,false,sizeof(visit));
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(visit[i][j]==false && arr[i][j]!='#')
			{
				int a=0,b=0;
				bool bound=true;
				dfs(arr,visit,i,j,a,b,bound);
				if(a>b && bound)
				{
					wc-=b;
				}
				else if(bound)
				{
					sc-=a;
				}
			}
		}
	}
	printf("%d %d",sc,wc);
	return 0;
}
