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
int lcs(vector<int> &a,vector<int> &b)
{
	int m=a.size();
	int n=b.size();
	int ltable[2][n+1];
	for(int i=0;i<=m;i++)
	{
		int bi=i&1;
		for(int j=0;j<=n;j++)
		{
			if(i==0 || j==0)
				ltable[bi][j]=0;
			else if(a[i-1]==b[j-1])
			{
				ltable[bi][j]=ltable[1-bi][j-1]+1;
			}
			else
				ltable[bi][j]=max(ltable[1-bi][j],ltable[bi][j-1]);
		}
	}
	int bi=m&1;
	return ltable[bi][n];
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		vector< vector<int> >road;
		vector< int > agn;
		int val;
		while(1)
		{
			scanf("%d",&val);
			if(val==0)
				break;
			agn.push_back(val);
		}
		while(1)
		{
			vector< int > temp;
			int val;
			scanf("%d",&val);
			if(val==0)
				break;
			while(val)
			{
				temp.push_back(val);
				scanf("%d",&val);
			}
			road.push_back(temp);
		}
		int res=0;
		for(int i=0;i<road.size();i++)
		{
			res=max(res,lcs(agn,road[i]));
		}
		printf("%d\n",res);
	}
	return 0;
}


