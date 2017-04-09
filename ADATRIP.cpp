#include<bits/stdc++.h>
using namespace std;
struct cmpp
{
	bool operator()(pair<int,int> a,pair<int,int> b)
	{
		return a.second>b.second;
	}
};
int main()
{
	int n,m,q;
	scanf("%d%d%d",&n,&m,&q);
	vector< vector< pair<int,int> > > ed(n);
	while(m--)
	{
		int s,d,val;
		scanf("%d%d%d",&s,&d,&val);
		ed[s].push_back(pair<int,int>(d,val));
		ed[d].push_back(pair<int,int>(s,val));
	}
	while(q--)
	{
		int s1;
		scanf("%d",&s1);
		vector< bool > visit(n,false);
		priority_queue< pair<int,int> , vector< pair<int,int> > ,cmpp > pq;
		pq.push(pair<int,int>(s1,0));
		int r1=-1;
		int r2=-1;
		while(!pq.empty())
		{
			int s=pq.top().first;
			int len=pq.top().second;
			pq.pop();
			if(!visit[s])
			{
				visit[s]=true;
				bool end=true;
				for(int i=0;i<ed[s].size();i++)
				{
					int d=ed[s][i].first;
					int dis=ed[s][i].second;
					if(visit[d]==false)
					{
						pq.push(pair<int,int>(d,len+dis));
					}
				}
				if(end)
				{
					if(len==r1)
					{
						r2++;
					}
					else if(len>r1)
					{
						r1=len;
						r2=1;
					}
				}
			}
		}
		printf("%d %d",r1,r2);
		if(q!=0)
			printf("\n");
	}
	return 0;
}
