#include<bits/stdc++.h>
#define INF 10000
using namespace std;
int row[]={1,-1,0,0};
int col[]={0,0,1,-1};
int main()
{
	char arr[1001][1001];
	int dist[1001][1001];
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int r,c;
		scanf("%d%d",&r,&c);
		for(int i=0;i<r;i++)
			for(int j=0;j<c;j++)
				dist[i][j]=INF;
		for(int i=0;i<r;i++)
			scanf("%s",arr[i]);
		deque< pair<int,int> > pq;
		pq.push_back(pair<int,int>(0,0));
		dist[0][0]=0;
		while(!pq.empty())
		{
			int i=pq.front().first;
			int j=pq.front().second;
			pq.pop_front();
			for(int k=0;k<4;k++)
			{
				int ci=i+row[k];
				int cj=j+col[k];
				if(ci>=0 && ci<r && cj>=0 && cj<c)
				{
					if(arr[ci][cj]==arr[i][j] && dist[ci][cj]>dist[i][j])
					{
						pq.push_front(pair<int,int>(ci,cj));
						dist[ci][cj]=dist[i][j];
					}
					if(arr[ci][cj]!=arr[i][j] && dist[ci][cj]>dist[i][j]+1)
					{
						pq.push_back(pair<int,int>(ci,cj));
						dist[ci][cj]=dist[i][j]+1;
					}
				}
			}
		}
		printf("%d\n",dist[r-1][c-1]);
	}
	return 0;
}
