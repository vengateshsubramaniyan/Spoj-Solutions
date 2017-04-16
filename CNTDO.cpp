#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		vector< pair< bool ,bool > > a(10001,pair<bool,bool>(false,false));
		int val;
		int n;
		scanf("%d",&n);
		while(n--)
		{
			scanf("%d",&val);
			if(val>=0)
				a[val].first=true;
			else
				a[abs(val)].second=true;
		}
		int count=0;
		for(int i=0;i<10001;i++)
		{
			if(a[i].first)
			{
				int d=2*i;
				if(d<=10000 && a[d].first)
					count++;
			}
			if(a[i].second)
			{
				int d=2*i;
				if(d<=10000 && a[d].second)
					count++;
			}
		}
		a.clear();
		printf("%d\n",count);
	}
	return 0;
}
