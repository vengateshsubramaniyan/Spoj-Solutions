#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	int test;
	scanf("%d",&test);
	ll te=0;
	for(int t=1;t<=test;t++)
	{
		int n;
		scanf("%d",&n);
		ll a[n+1];
		for(int i=0;i<n;i++)
			scanf("%lld",&a[i]);
		a[n]=0;
		for(int i=n-1;i>=0;i--)
		{
			if(a[i]>0)
			{
				if(a[i+1]==0)
					a[i]=0;
				else if(a[i+1]>a[i])
				{
					a[i]=a[i+1]-a[i];
				}
				else if(a[i+1]<a[i])
				{
					a[i]=0;
				}
				else 
				{
					a[i]=0;
				}
			}
			else
			{
				if(a[i+1]==0)
					a[i]=-a[i]+1;
				else
					a[i]=a[i+1]-a[i];
			}
//			cout<<a[i]<<" ";
		}
		printf("%lld\n",a[0]);
	}
	return 0;
}
