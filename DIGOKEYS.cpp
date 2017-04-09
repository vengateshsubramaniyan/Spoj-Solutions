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
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		vector< set<int> >key(n+1);
		for(int i=1;i<n;i++)
		{
			int m;
			scanf("%d",&m);
			while(m--)
			{
				int box;
				scanf("%d",&box);
				key[i].insert(box);
			}
		}
		vector<int> par(n+1,-1);
		par[1]=0;
		queue< pi >q;
		q.push(pi(1,1));
		int res=false;
		while(!q.empty())
		{
			set<int>::iterator it;
			int k=q.front().first;
			int box=q.front().second;
			q.pop();
			for(it=key[k].begin();it!=key[k].end();it++)
			{
				int bo=*it;
				if(par[bo]==-1)
				{
					par[bo]=k;
					if(bo==n)
					{
						res=true;
						break;
					}
					q.push(pi(bo,box+1));
				}
			}
			if(res)
				break;
		}
		if(res==false)
		{
			printf("-1\n\n");
			continue;
		}
		vector<int> re;
		for(int i=par[n];i!=0;i=par[i])
			re.push_back(i);
		printf("%d\n",re.size());
		for(int i=re.size()-1;i>=0;i--)
		{
			printf("%d ",re[i]);
		}
		printf("\n\n");
	}
	return 0;
}


