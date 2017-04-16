#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	ll n,n1;
	scanf("%lld",&n);
	while(n)
	{
		ll arr[n];
		for(ll i=0;i<n;i++)
			scanf("%lld",&arr[i]);
		scanf("%lld",&n1);
		ll arr1[n1];
		for(ll i=0;i<n1;i++)
			scanf("%lld",&arr1[i]);
		ll sum1=0;
		ll sum2=0;
		ll result=0;
		ll i=0,j=0;
		while(i<n || j<n1)
		{
			if(i==n)
			{
				sum2+=arr1[j++];
			}
			else if(j==n1)
				sum1+=arr[i++];
			else
			{
				if(arr[i]<arr1[j])
					sum1+=arr[i++];
				else if(arr1[j]<arr[i])
					sum2+=arr1[j++];
				else if(arr[i]==arr1[j])
				{
					result+=max(sum1,sum2)+arr[i];
					sum1=0;
					sum2=0;
					i++;
					j++;
				}
			}
		}
		result+=max(sum1,sum2);
		printf("%lld\n",result);
		scanf("%lld",&n);
	}
	return 0;
}
