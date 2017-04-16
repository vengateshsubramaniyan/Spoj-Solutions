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
	int test;
	int a[10001];
	scanf("%d",&test);
	for(int t=1;t<=test;t++)
	{
		int n,k;
		scanf("%d%d",&n,&k);
		bool zero=false;
		ll sum=0;
		for(int i=0;i<n;i++)
		{
			scanf("%lld",&a[i]);
			if(a[i]==0)
				zero=true;
			sum+=a[i];
		}
		if(sum<k)
		{
			printf("Case %d: -1\n",t);
			continue;
		}
		ll val=0;
		ll res=n;
		ll start=0,end=0;
		if(k==0)
		{
			printf("Case %d: 0\n",t);
			continue;
		}
		while(end<n)
		{
			if((val+a[end])<k)
			{
				val+=a[end++];
			}
			else
			{
				val+=a[end++];
				while(val>=k)
				{
					res=min(res,end-start);
					val-=a[start++];
				}
			}
		}
		printf("Case %d: %d\n",t,res);
	}
	return 0;
}


