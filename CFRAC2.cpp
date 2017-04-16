#include<bits/stdc++.h>
#define ll long long 
using namespace std;
int main()
{
	ll r,c;
	scanf("%lld%lld",&r,&c);
	bool first=true;
	while(r && c)
	{
		if(first)
			first=false;
		else
			cout<<endl;
		ll p=1,q=1;
		vector< string > arr(r);
		for(ll i=0;i<r;i++)
			cin>>arr[i];
		bool pos=true;
		for(ll i=r-1;i>=0;i--)
		{
			if(pos)
			{
				ll t=q;
				q=p;
				p=t;
				pos=false;
			}
			else
			{
				ll j=0;
				ll val=0;
				for(;j<c && arr[i][j]=='.';j++);
				{
					//do nothing
				}
				for(;j<c && arr[i][j]>='0' && arr[i][j]<='9';j++)
				val=(val*10)+(arr[i][j]-'0');	
				p+=(q*val);
				pos=true;
			}
		}
		arr.clear();
		printf("%lld %lld",q,p);
		scanf("%lld%lld",&r,&c);
	}
	return 0;
}
