#include<bits/stdc++.h>
using namespace std;
void dfs(vector< vector<int> >&graph,int src,stack<int> &s,vector<bool> &visit)
{
	visit[src]=true;
	for(int it=0;it<graph[src].size();it++)
	{
		if(!visit[graph[src][it]])
			dfs(graph,graph[src][it],s,visit);
	}
	s.push(src);
}
int againdfs(vector< vector<int> > &rgraph,int src,int par,vector< bool > &visit,vector< int > &result)
{
	visit[src]=true;
	result[src]=par;
	int id=src;
	for(int it=0;it<rgraph[src].size();it++)
	{
		if(!visit[rgraph[src][it]])
		{
			id=min(id,againdfs(rgraph,rgraph[src][it],par,visit,result));
		}
	}
	return id;
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	vector< vector<int> >graph(n);
	vector< vector<int> >rgraph(n);
	while(m--)
	{
		int src,des;
		scanf("%d%d",&src,&des);
		graph[src].push_back(des);
		rgraph[des].push_back(src);
	}
	stack<int> s;
	vector< bool> visit(n,false);
	for(int i=0;i<n;i++)
	{
		if(!visit[i])
			dfs(graph,i,s,visit);
	}
	vector<int> result(n,INT_MAX);
	vector< bool > vi(n,false);
	int com=0;
	vector< int > components;
	while(s.empty()==false)
	{
		int src=s.top();
		s.pop();
		int par=src;
		if(!vi[src])
			components.push_back(againdfs(rgraph,src,com++,vi,result));
	}
	for(int i=0;i<n;i++)
	{
		int j=result[i];
		printf("%d\n",components[j]);
	}
	return 0;
}
