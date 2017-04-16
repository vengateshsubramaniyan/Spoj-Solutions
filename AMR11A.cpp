#include<bits/stdc++.h>
#define ll long long 
using namespace std;
int main()
{
	ll t,r,c,v1,v2;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld%lld",&r,&c);
		ll arr[r][c];
		for(ll i=0;i<r;i++)
			for(ll j=0;j<c;j++)
				scanf("%lld",&arr[i][j]);
		for(ll i=r-1;i>=0;i--)
		{
			for(ll j=c-1;j>=0;j--)
			{
				v1=INT_MAX,v2=INT_MAX;
				if(i==r-1 && j==c-1)
				{
					if(arr[i][j]<0)
						arr[i][j]=-arr[i][j];
					else
						arr[i][j]=0;
				}
				else
				{
					if(arr[i][j]>=0)
					{
						if(i+1<r)
						{
							v1=arr[i+1][j]-arr[i][j];
							v1=(v1<0)?0:v1;
						}
						if(j+1<c)
						{
							v2=arr[i][j+1]-arr[i][j];
							v2=(v2<0)?0:v2;	
						}
						arr[i][j]=min(v1,v2);
					}
					else
					{
						if(i+1<r)
							v1=arr[i+1][j];
						if(j+1<c)
							v2=arr[i][j+1];
						arr[i][j]=min(v1,v2)+(-arr[i][j]);
					}
				}
			}
		}
		printf("%lld\n",arr[0][0]+1);	
	}
	return 0;
}
