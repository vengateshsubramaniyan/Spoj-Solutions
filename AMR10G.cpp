#include<bits/stdc++.h>
#define ll long long 
#define vll vector<long long> 
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		ll n,k;
		scanf("%lld%lld",&n,&k);
		vll arr(n);
		for(ll i=0;i<n;i++)
			scanf("%lld",&arr[i]);
		if(k==1)
			printf("0\n");
		else
		{
			sort(arr.begin(),arr.end());
			ll result=arr[k-1]-arr[0];
			for(ll i=1;i+k-1<n;i++)
			{
				ll temp=arr[i+k-1]-arr[i];
				if(temp<result)
					result=temp;
			}
			printf("%lld\n",result);
		}
		
	}
	return 0;
}
