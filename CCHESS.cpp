#include<bits/stdc++.h>
using namespace std;
int row[]={-1,-2,-2,-1,1,2,2,1};
int col[]={-2,-1,1,2,-2,-1,1,2};
struct cmpp
{
	bool operator()(pair< int , pair<int,int> > &a,pair< int , pair<int,int> > &b)
	{
		return a.first>b.first;
	}
};
int main()
{
	int a,b,c,d;
	while(cin>>a)
	{
		scanf("%d%d%d",&b,&c,&d);
		vector< vector<bool> > visit(8,vector<bool>(8,false));
		priority_queue< pair< int , pair<int,int> >,vector< pair< int , pair<int,int> > >, cmpp > pq;
		pq.push(pair<int,pair<int,int> >(0,pair<int,int>(a,b)));
		int result=-1;
		while(!pq.empty())
		{
			int val=pq.top().first;
			int i=pq.top().second.first;
			int j=pq.top().second.second;
			pq.pop();
			if(i==c && j==d)
			{
				result=val;
				break;
			}
			if(visit[i][j]==false)
			{
				visit[i][j]=true;
				for(int k=0;k<8;k++)
				{
					int ci=i+row[k];
					int cj=j+col[k];
					if(ci>=0 && cj>=0 && ci<8 && cj<8 && !visit[ci][cj])
					{
						pq.push(pair< int , pair<int,int> >(val+(i*ci)+(j*cj),pair<int,int>(ci,cj)));
					}
				}
			}
		}
		printf("%d\n",result);
	}
	return 0;
}
