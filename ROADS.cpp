#include<bits/stdc++.h>
using namespace std;
struct cmpp
{
	bool operator()(const pair<int,pair<int,int> > &a,const pair<int,pair<int,int> > &b)
	{
		return a.second.first>b.second.first;
	}	
};
int main()
{
	int t;
	scanf("%d",&t);
	while(t)
	{
		int k,n,r;
		scanf("%d%d%d",&k,&n,&r);
		vector< vector< pair<int,int> > > edge(n+1);
		vector< pair<int,int> > road(r+1);
		for(int i=1;i<=r;i++)
		{
			int s,d,l,c;
			scanf("%d%d%d%d",&s,&d,&l,&c);
			edge[s].push_back(pair<int,int>(d,i));
			road[i]=pair<int,int>(l,c);
		}
		bool found=false;
		int result;
		priority_queue< pair< int , pair<int,int> > ,vector< pair<int,pair<int,int> > > ,cmpp > pq;
		pq.push(pair<int,pair<int,int> >(1,pair<int,int>(0,0)));
		while(!pq.empty())
		{
			int s=pq.top().first;
			int l=pq.top().second.first;
			int c=pq.top().second.second;
			pq.pop();
			if(s==n)
			{
				result=l;
				found=true;
				break;
			}
			for(int i=0;i<edge[s].size();i++)
			{
				int d=edge[s][i].first;
				int rn=edge[s][i].second;
				if(d!=s)
				{
					if(c+road[rn].second<=k)
					{
						pq.push(pair<int,pair<int,int> >(d,pair<int,int>(l+road[rn].first,c+road[rn].second)));
					}
				}
			}
		}
		if(!found)
			result=-1;
		printf("%d\n",result);
		t--;
	}
	return 0;
}
