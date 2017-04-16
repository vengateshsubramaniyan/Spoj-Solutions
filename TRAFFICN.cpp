#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct cmpp
{
	bool operator()(pair<ll,pair<int,bool> > a,pair<ll, pair<int,bool> > b)
	{
		return a.first>b.first;
	}
};
int main()
{
	int t1;
	scanf("%d",&t1);
	while(t1--)
	{
		int n,m,k,s,t;
		scanf("%d%d%d%d%d",&n,&m,&k,&s,&t);
		vector< vector< pair<int,ll> > > oroad(n+1);
		vector< vector< pair<int,ll> > > troad(n+1);
		while(m--)
		{
			int src,des;
			ll len;
			scanf("%d%d%lld",&src,&des,&len);
			oroad[src].push_back(pair<int,ll>(des,len));
		}
		while(k--)
		{
			int src,des;
			ll len;
			scanf("%d%d%lld",&src,&des,&len);
			troad[src].push_back(pair<int,ll>(des,len));
			troad[des].push_back(pair<int,ll>(src,len));
		}
		priority_queue< pair<ll , pair<int,bool> > ,vector< pair<ll, pair<int,bool> > >,cmpp> pq;
		pq.push(pair< ll ,pair<int,bool> >(0,pair<int,bool>(s,false)));
		vector< bool > visit(n+1,false);
		bool fo=false;
		while(!pq.empty())
		{
			ll res=pq.top().first;
			int s=pq.top().second.first;
			bool ad=pq.top().second.second;
			pq.pop();
			if(s==t)
			{
				fo=true;
				printf("%lld\n",res);
				break;
			}
			visit[s]=true;
			for(int i=0;i<oroad[s].size();i++)
			{
				int d=oroad[s][i].first;
				ll dis=oroad[s][i].second;
				if(!visit[d])
					pq.push(pair<ll, pair<int,bool> >(res+dis,pair<int,bool>(d,ad)));
			}
			if(!ad)
			{
				for(int i=0;i<troad[s].size();i++)
				{
					int d=troad[s][i].first;
					ll dis=troad[s][i].second;
					if(!visit[d])
						pq.push(pair<ll, pair<int,bool> >(res+dis,pair<int,bool>(d,true)));
				}
			}
		}
		if(!fo)
			printf("-1\n");
	}
	return 0;
}
