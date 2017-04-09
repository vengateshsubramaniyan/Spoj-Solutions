#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	ll a[n];
	for(int i=0;i<n;i++)
		scanf("%lld",&a[i]);
	ll res=0;
	int si=0,sj=0;
	for(int i=0;i<n;i++)
	{
		if(res<a[i])
		{
			res=a[i];
			si=i,sj=i;
		}
		ll temp=a[i];
		for(int j=i+1;j<n;j++)
		{
			temp^=a[j];
			if(res<temp)
			{
				res=temp;
				si=i;
				sj=j;
			}
		}
	}
	printf("%lld\n",res);
	printf("%d %d",si+1,sj+1);
	return 0;
}
