#include<bits/stdc++.h>
using namespace std;
int row[]={1,-1,0,0};
int col[]={0,0,1,-1};
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int r,c;
		scanf("%d%d",&r,&c);
		char arr[200][200];
		for(int i=0;i<r;i++)
		{
			scanf("\n%[^\n]s",arr[i]);
		}
		bool found=true;
		queue<pair<pair<int ,int> ,int> > q; 
		for(int i=0;i<r && found;i++)
		{
			for(int j=0;j<c && found;j++)
			{
				if(arr[i][j]=='$')
				{
					q.push(pair<pair<int,int> ,int>(pair<int,int>(i,j),0));
					found=false;
				}
			}
		}
		found=false;
		int result=-1;
		while(!q.empty() && !found)
		{
			int i=q.front().first.first;
			int j=q.front().first.second;
			int dist=q.front().second;
			q.pop();
			if(arr[i][j]=='#')
			{
				result=dist;
				found=true;
				break;
			}
			arr[i][j]='*';
			for(int l=0;l<4;l++)
			{
				int ci=i+row[l];
				int cj=j+col[l];
				if(ci>=0 && cj>=0 && ci<r && cj<c && arr[ci][cj]!='*')
				{
					q.push(pair<pair<int,int> ,int>(pair<int,int>(ci,cj),dist+1));	
				}
			}
		}
		printf("%d\n",result);
	}	
	return 0;
}
