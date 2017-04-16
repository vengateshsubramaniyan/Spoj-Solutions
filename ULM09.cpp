#include<bits/stdc++.h>
using namespace std;
static bool cmpp(const pair< int, pair<int,int> > a,const pair< int, pair<int,int> > b)
{
	return a.first<b.first;
}
int find(vector< pair<int,int> > &par,int i)
{
	if(par[i].first!=i)
		par[i].first=find(par,par[i].first);
	return par[i].first;
}
void un(vector< pair<int,int> > &par,int u ,int v)
{
	int xr=find(par,u);
	int yr=find(par,v);
	if(par[xr].second<par[yr].second)
		par[xr].first=yr;
	else if(par[xr].second>par[yr].second)
		par[yr].first=xr;
	else
	{
		par[yr].first=xr;
		par[xr].second++;
	}
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	while(n && m)
	{
		int tq=0;
		vector< pair<int, pair<int,int> > > edge(m);
		for(int i=0;i<m;i++)
		{
			scanf("%d%d%d",&edge[i].second.first,&edge[i].second.second,&edge[i].first);
			tq+=edge[i].first;
		}
		sort(edge.begin(),edge.end(),cmpp);
		vector< pair<int,int> > parent(n);
		for(int i=0;i<n;i++)
		{
			parent[i].first=i;
			parent[i].second=0;
		}
		int result=0,e=0;
		int i=0;
		while(e<n-1)
		{
			int x=find(parent,edge[i].second.first);
			int y=find(parent,edge[i].second.second);
			if(x!=y)
			{
				result+=edge[i].first;
				un(parent,x,y);
				e++;
			}
			i++;
		}
		printf("%d\n",tq-result);
		scanf("%d%d",&n,&m);
	}
	return 0;
}
