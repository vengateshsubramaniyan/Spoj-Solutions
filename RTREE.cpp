#include<bits/stdc++.h>
#define ll long long
using namespace std;
void dfs(vector< vector<ll> > &edge,ll root,vector< bool > &visit,vector< ll > &result, ll &re)
{
	visit[root]=true;
	ll m1=0,m2=0;
	for(ll i=0;i< edge[root].size();i++)
	{
		ll v=edge[root][i];
		if(!visit[v])
		{
			ll temp=1;
			dfs(edge,v,visit,result,temp);
			if(temp>m1)
			{
				m2=m1;
				m1=temp;
			}
			else if(temp>m2)
			{
				m2=temp;
			}
			if(result[root]<result[v])
				result[root]=result[v];
		}
	}
	re+=m1;
	if(result[root]<m1+m2)
		result[root]=m1+m2;
}
int main()
{
	ll n;
	scanf("%lld",&n);
	vector< vector<ll> > edge(n+1);
	for(ll i=1;i<n;i++)
	{
		ll src,des;
		scanf("%lld%lld",&src,&des);
		edge[src].push_back(des);
		edge[des].push_back(src);
	}
	vector< bool > visit(n+1,false);
	vector< ll > result(n+1,0);
	ll root;
	scanf("%lld",&root);
	ll temp=0;
	dfs(edge,root,visit,result,temp);
	ll q;
	scanf("%lld",&q);
	while(q--)
	{
		scanf("%lld",&root);
		printf("%lld",result[root]);
		if(q!=0)
		{
			printf("\n");
		}
	}
	return 0;
}
