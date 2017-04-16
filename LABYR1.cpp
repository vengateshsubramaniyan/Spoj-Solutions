#include<bits/stdc++.h>
using namespace std;
int row[]={1,0,-1,0};
int col[]={0,1,0,-1};
void find(vector<string> &arr,vector< vector<bool> > &visit,int i,int j,int &r,int &c,int &l,int &res)
{
	int m1=0,m2=0,re;
	visit[i][j]=true;
	for(int k=0;k<4;k++)
	{
		int ci=i+row[k];
		int cj=j+col[k];
		if(ci>=0 && ci<r && cj>=0 && cj<c && arr[ci][cj]=='.' && visit[ci][cj]==false)
		{
			re=1;
			find(arr,visit,ci,cj,r,c,re,res);
			if(re>m1)
			{
				m2=m1;
				m1=re;
			}
			else if(re>m2)
			{
				m2=re;
			}
		}
	}
	if(m1+m2>res)
		res=m1+m2;
	l+=m1;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int r,c;
		scanf("%d%d",&c,&r);
		vector<string> arr(r);
		for(int i=0;i<r;i++)
		{
			cin>>arr[i];
		}
		vector< vector<bool> > visit(r,vector<bool>(c,false));
		int result=0;
		for(int i=0;i<r;i++)
		{
			for(int j=0;j<c;j++)
			{
				int rl=0;
				if(visit[i][j]==false && arr[i][j]=='.')
					find(arr,visit,i,j,r,c,rl,result);
			}
		}	
		printf("Maximum rope length is %d.\n",result);	
	}
	return 0;
}
