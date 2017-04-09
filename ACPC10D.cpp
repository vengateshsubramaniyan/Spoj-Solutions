#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	ll n;
	scanf("%lld",&n);
	ll k=1;
	while(n)
	{
		if(k!=1)
			printf("\n");
		ll arr[n][3];
		for(ll i=0;i<n;i++)
		{
			for(int j=0;j<3;j++)
			{
				scanf("%lld",&arr[i][j]);
				if(i==0 && j<2)
					continue;
				else if(i==0 && j==2)
					arr[0][2]+=arr[0][1];
				else
				{
					if(j==0)
					{
						if(i!=1)
							arr[i][j]+=min(arr[i-1][0],arr[i-1][1]);
						else
							arr[i][j]+=arr[i-1][1];
					}
					else if(j==1)
					{
						if(i!=1)
							arr[i][j]+=min(min(arr[i-1][1],arr[i-1][2]),min(arr[i][0],arr[i-1][0]));
						else
							arr[i][j]+=min(min(arr[i-1][1],arr[i-1][2]),arr[i][0]);							
					}
					else
					{
						arr[i][j]+=min( min(arr[i-1][2],arr[i-1][1]),arr[i][1]);
					}
				}
			}
		}
		printf("%lld. %lld",k++,arr[n-1][1]);
		scanf("%lld",&n);
	}
	return 0;
}
