#include<bits/stdc++.h>
using namespace std;
bool bfs(vector< vector<int> > &edge,vector< bool > &visit,int i,int n)
{
	vector< char > sex(n+1,'N');
	queue< pair<int , char > > q;
	q.push(pair<int,char>(i,'M'));
	while(!q.empty())
	{
		int s=q.front().second;
		int in=q.front().first;
		q.pop();
		visit[in]=true;
		sex[in]=s;
		for(int i=0;i<edge[in].size();i++)
		{
			int d=edge[in][i];
			if(visit[d]==true)
			{
				if(sex[d]==s)
					return true;
			}
			else
			{
				if(s=='M')
					q.push(pair<int,char>(d,'F'));
				else
					q.push(pair<int,char>(d,'M'));
			}
		}
	}
	return false;
}
int main()
{
	int test;
	scanf("%d",&test);
	for(int t=1;t<=test;t++)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		vector< vector<int> > edge(n+1);
		while(m--)
		{
			int src,des;
			scanf("%d%d",&src,&des);
			edge[src].push_back(des);
			edge[des].push_back(src);
		}
		vector< bool > visit(n+1,false);
		bool res=false;
		for(int i=1;i<=n;i++)
		{
			if(!visit[i])
			{
				if(bfs(edge,visit,i,n))
				{
					res=true;
					break;
				}
			}
		}
		printf("Scenario #%d:\n",t);
		if(res)
			printf("Suspicious bugs found!\n");
		else
			printf("No suspicious bugs found!\n");
	}
	return 0;
}
