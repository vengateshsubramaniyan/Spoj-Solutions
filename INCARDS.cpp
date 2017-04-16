#include<bits/stdc++.h>
#define pint pair<int,int>
using namespace std;
struct cmpp
{
	bool operator()(const pint a,const pint b)
	{
		return a.second>b.second;
	}
};
void findshort(vector< vector< pint > > &edge,int &result,int n)
{
	priority_queue< pint, vector<pint> ,cmpp > pq;
	vector< int > dist(n+1,INT_MAX);
	pq.push(pint(1,0));
	dist[1]=0;
	while (!pq.empty())
    {
        int u = pq.top().first;
        pq.pop();
        for (int i = 0; i<edge[u].size();i++)
        {
            int v = edge[u][i].first;
            int weight =edge[u][i].second;
            if (dist[v] > dist[u] + weight)
            {
                dist[v] = dist[u] + weight;
                pq.push(make_pair(v,dist[v]));
            }
        }
    }
    for(int i=1;i<=n;i++)
    	result+=dist[i];
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,q;
		scanf("%d%d",&n,&q);
		vector< vector< pint > > sur(n+1);
		vector< vector< pint > > des(n+1);
		while(q--)
		{
			int s,d,w;
			scanf("%d%d%d",&s,&d,&w);
			sur[s].push_back(pair<int,int>(d,w));
			des[d].push_back(pair<int,int>(s,w));
		}
		int result=0;
		findshort(sur,result,n);
		findshort(des,result,n);
		printf("%d\n",result);
	}
	return 0;
}
