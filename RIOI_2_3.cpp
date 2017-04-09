#include<bits/stdc++.h>
using namespace std;
struct cmpp
{
	bool operator()(pair< pair<int,int> , pair<int,int> > &a, pair< pair<int,int> , pair<int,int> > &b)
	{
		return a.first.first>b.first.first;
	}
};
int row[]={1,-1,0,0};
int col[]={0,0,1,-1};
int main()
{
	int t,n;
	scanf("%d",&t);
	int a[50][50];
	bool uni[50][50][1024];
	while(t--)
	{
		memset(uni,false,sizeof(uni));
		scanf("%d",&n);
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)	
				scanf("%d",&a[i][j]);
		priority_queue< pair< pair<int,int> ,pair<int,int> > ,vector< pair< pair<int,int> , pair<int,int> > > ,cmpp> pq;
		int sx,sy,ex,ey;
		scanf("%d%d%d%d",&sx,&sy,&ex,&ey);
		int temp=1<<a[sx][sy];
		pq.push(pair< pair<int,int> ,pair<int,int> >(pair<int,int>(1,temp),pair<int,int>(sx,sy)));
		while(!pq.empty())
		{
			int res=pq.top().first.first;
			int apo=pq.top().first.second;
			int i=pq.top().second.first;
			int j=pq.top().second.second;
			if(i==ex && j==ey)
			{
				printf("%d\n",res);
				break;
			}
			pq.pop();
			if(uni[i][j][apo])
				continue;
			uni[i][j][apo]=true;
			for(int k=0;k<4;k++)
			{
				int ci=i+row[k];
				int cj=j+col[k];
				if(ci>=0 && ci<n && cj>=0 && cj<n)
				{
					int t=apo;
					if(t>>a[ci][cj]&1)
					{
						if(!uni[ci][cj][t])
						{
							pq.push(pair< pair<int,int> ,pair<int,int> >(pair<int,int>(res,t),pair<int,int>(ci,cj)));
						}
					}
					else
					{
						t|=1<<a[ci][cj];
						if(!uni[ci][cj][t])
						{
							pq.push(pair< pair<int,int> ,pair<int,int> >(pair<int,int>(res+1,t),pair<int,int>(ci,cj)));
						}
					}
				}
			}
		}
	}
	return 0;
}
