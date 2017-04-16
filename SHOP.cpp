#include<bits/stdc++.h>
using namespace std;
struct cmpp
{
	bool operator()(const pair< pair<int,int> , int > a,const pair< pair<int,int> , int > b)
	{
		return a.second>b.second;		
	}
};
int row[]={0,0,1,-1};
int col[]={1,-1,0,0};
int main()
{
	int c,r;
	scanf("%d%d",&c,&r);
	while(c && r)
	{	
		priority_queue< pair< pair<int,int> , int > ,vector< pair< pair<int,int> , int > > ,cmpp > q;
		char arr[r][c];
		for(int i=0;i<r;i++)
			scanf("\n%[^\n]s",arr[i]);
		bool cc=false;
		for(int i=0;i<r&&!cc;i++)
		{
			for(int j=0;j<c;j++)
			{
				if(arr[i][j]=='S')
				{
					q.push(pair<pair<int,int>,int>(pair<int,int>(i,j),0));
					cc=true;
					break;
				}
			
			}
		}
		while(!q.empty())
		{
			int i=q.top().first.first;
			int j=q.top().first.second;
			int d=q.top().second;
			q.pop();
			if(arr[i][j]=='X')
				continue;
			bool found=false;
			for(int k=0;k<4 && !found;k++)
			{
				int ci=i+row[k];
				int cj=j+col[k];
				if(ci>=0 && cj>=0 && ci<r && cj<c && arr[ci][cj]!='X' && arr[ci][cj]!='S')
				{
					if(arr[ci][cj]=='D')
					{
						found=true;
						break;
					}
					else
					{
						q.push(pair<pair<int,int>,int>(pair<int,int>(ci,cj),d+(arr[ci][cj]-'0')));
					}
				}
			}
			if(found)
			{
				printf("%d\n",d);
				break;
			}
			arr[i][j]='X';
		}
		char ccc;
		scanf("%c",&ccc);
		scanf("%d%d",&c,&r);
	}
	return 0;
}
