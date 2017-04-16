#include<bits/stdc++.h>
#define mod 10000007
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	for(int test=1;test<=t;test++)
	{
		int n;
		scanf("%d",&n);
		int a[n];
		for(int i=0;i<n;i++)
			scanf("%d",&a[i]);
		vector< pair<int,int> > co(32);
		for(int i=0;i<32;i++)
		{
			if(a[0]>>i&1)
				co[i].second=1;
			else
				co[i].first=1;
		}
		int result=0;
		for(int i=1;i<n;i++)
		{
			for(int j=0;j<32;j++)
			{
				if(a[i]>>j & 1)
				{
					result=(result+co[j].first)%mod;
					co[j].second++;
				}
				else
				{
					result=(result+co[j].second)%mod;
					co[j].first++;
				}
			}
		}
		result=(result*2)%mod;
		printf("Case %d: %d\n",test,result);
	}
	return 0;
}
