#include<bits/stdc++.h>
using namespace std;
int a[251][251];
int row[]={1,-1,0,0};
int col[]={0,0,1,-1};
int find(int i,int j,int r,int c)
{
	int res=1;
	a[i][j]=0;
	for(int k=0;k<4;k++)
	{
		int ci=i+row[k];
		int cj=j+col[k];
		if(ci>=0 && ci<r && cj>=0 && cj<c && a[ci][cj]==1)
		{
			res+=find(ci,cj,r,c);
		}
	}
	return res;
}
int main()
{
	int r,c;
	scanf("%d%d",&r,&c);
	while(r && c)
	{
		for(int i=0;i<r;i++)
			for(int j=0;j<c;j++)
				scanf("%d",&a[i][j]);
		map< int ,int > m;
		int count=0;
		for(int i=0;i<r;i++)
		{
			for(int j=0;j<c;j++)
			{
				if(a[i][j]==1)
				{
					int res=find(i,j,r,c);
					m[res]++;
					count++;
				}
			}
		}
		printf("%d\n",count);
		map<int,int>::iterator it;
		for(it=m.begin();it!=m.end();it++)
			printf("%d %d\n",it->first,it->second);
		scanf("%d%d",&r,&c);
	}
	return 0;
}
