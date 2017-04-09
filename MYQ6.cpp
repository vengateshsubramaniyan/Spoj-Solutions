#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		ll n;
		scanf("%lld",&n);
		ll wei[n+2];
		ll tw=0;
		ll rec=0;
		for(ll i=1;i<=n;i++)
			scanf("%lld",&wei[i]);
		ll dist[n+2];
		wei[0]=0,wei[n+1]=0;
		dist[0]=0,dist[n+1]=0;
		for(ll i=1;i<n;i++)
			scanf("%lld",&dist[i]);
		ll curr=10;
		bool ten=true;
		if(wei[1]==0)
		{
			curr=0;
			ten=false;
		}
		for(ll i=2;i<=n;i++)
		{
			curr+=(wei[i]*dist[i-1]*2);
			wei[i]+=wei[i-1];
			dist[i]+=dist[i-1];
		}
		ll rval=curr;
		ll ri=1;
//		cout<<curr<<endl;
		for(ll i=2;i<=n;i++)
		{
			if(wei[i]-wei[i-1]==0)
			{
				if(ten)
				{
					curr-=10;
					ten=false;
				}
			}
			else 
			{
				if(!ten)
				{
					curr+=10;
					ten=true;
				}
			}
			curr-=((wei[i]-wei[i-1])*(dist[i-1]-dist[i-2])*2);
			curr+=(wei[i-1]*(dist[i-1]-dist[i-2]));
			curr-=((dist[i-1]-dist[i-2])*(wei[n]-wei[i])*2);
			if(curr<rval)
			{
				rval=curr;
				ri=i;
			}
//			cout<<curr<<endl;
		}
		printf("%lld %lld\n",rval,ri);
	}
	return 0;
}
