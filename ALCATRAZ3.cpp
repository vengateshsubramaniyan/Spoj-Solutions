#include<bits/stdc++.h>
using namespace std;
int row[]={1,0,-1,0};
int col[]={0,1,0,-1};
bool bfs(int i,int j,vector<vector<char> > &a,int n,int m,int ei,int ej,int k)
{
	a[i][j]='*';
	for(int k=0;k<4;k++)
	{
		int ci=i+row[k];
		int cj=j+col[k];
		if(ci>=0 && ci<n && cj>=0 && cj<m)
		{
			if(ci==ei && cj==ej)
			{
//				cout<<k<<" ";
				if((k-1)<=0)
					return true;
			}	
			else if(a[ci][cj]!='*')
			{
				if(bfs(ci,cj,a,n,m,ei,ej,k-1))
					return true;
			}
		}
	}
	a[i][j]='.';
	return false;
}
int main()
{
	int n,m,s,e,k;
	scanf("%d%d",&n,&m);
	scanf("%d",&k);
	scanf("%d%d",&s,&e);
	vector< vector<char> > arr(n,vector<char>(m));
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>arr[i][j];
		}
	}
/*	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cout<<arr[i][j];
		}
		cout<<endl;
	}*/
	s--;
	e--;
	bfs(s,e,arr,n,m,s,e,k)?printf("YES"):printf("NO");
	return 0;
}
