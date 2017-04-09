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
bool cmpp(pair<int,int> a,pair<int,int> b)
{
	if(a.first<b.first)
		return true;
	if(a.first>b.first)
		return false;
	return a.second<b.second;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		vector< pair<int,int> >bridge(n);
		for(int i=0;i<n;i++)
			scanf("%d",&bridge[i].first);
		for(int i=0;i<n;i++)
			scanf("%d",&bridge[i].second);
		sort(bridge.begin(),bridge.end(),cmpp);
		vector<int> res(n,1);
		for(int i=1;i<n;i++)
		{
			for(int j=0;j<i;j++)
			{
				if(bridge[j].first<=bridge[i].first && bridge[j].second<=bridge[i].second && res[i]<res[j]+1)
					res[i]=res[j]+1;
			}
		}
		int ma=1;
		for(int i=0;i<n;i++)
			ma=max(ma,res[i]);
		printf("%d\n",ma);
	}
	return 0;
}


