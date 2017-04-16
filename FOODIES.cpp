#include<bits/stdc++.h>
#define ll long long 
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		ll n,val,start=0,result=0,m;
		scanf("%lld",&n);
		vector< ll > arr(100001,0);
		while(n--)
		{
			scanf("%lld",&val);
			if(start<val)
				start=val;
			arr[val]++;
		}
		scanf("%lld",&m);
		while(m>0)
		{
			if(arr[start]>m)
				result+=(start*m);
			else
				result+=(start*arr[start]);
			m-=arr[start];
			arr[start-1]+=arr[start];
			start--;
		}
		printf("%lld\n",result);
	}
	return 0;
}
