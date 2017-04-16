#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define pi pair<int,int>
#define pll pair<ll,ll>
#define vl vector< ll >
#define bug(a) cout<<a<<endl;
#define bug2(a,b) cout<<a<<" "<<b<<endl;
#define bug3(a,b,c) cout<<a<<" "<<b<<" "<<c<<endl;
using namespace std;
void dfs(vector< vector<int> > &bomb,bool visit[],int b,int &temp)
{
	temp++;
	visit[b]=true;
	for(int i=0;i<bomb[b].size();i++)
	{
		int a=bomb[b][i];
		if(!visit[a])
			dfs(bomb,visit,a,temp);
	}
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	vector< vector<int> >bomb(n+1);
	while(m--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		bomb[a].push_back(b);
	}
	bool visit[n+1];
	int res=0;
	for(int i=1;i<=n;i++)
	{
		memset(visit,false,sizeof(visit));
		int temp=0;
		dfs(bomb,visit,i,temp);
		res=max(temp,res);
	}
	printf("%d",res);
	return 0;
}


