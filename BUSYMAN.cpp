#include<bits/stdc++.h>
using namespace std;
bool cmpp(pair<int,int> a,pair<int,int> b)
{
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
		vector< pair<int,int> > time(n);
		for(int i=0;i<n;i++)
		{
			scanf("%d%d",&time[i].first,&time[i].second);
		}
		sort(time.begin(),time.end(),cmpp);
		int res=1;
		int j=0;
		for(int i=1;i<n;i++)
		{
			if(time[i].first>=time[j].second)
			{
				res++;
				j=i;
			}
		}
		printf("%d\n",res);
	}
	return 0;
}
