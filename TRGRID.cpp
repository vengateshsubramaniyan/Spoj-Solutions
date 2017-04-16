#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		ll r,c;
		scanf("%lld%lld",&r,&c);
		if(r==c)
		{
			if(r%2==0)
			{
				printf("L");
			}
			else
			{
				printf("R");
			}
		}
		else if(r>c)
		{
			if(r%2==0 && c%2==0)
			{
				printf("U");
			}
			else if(r%2!=0 && c%2!=0)
			{
				printf("D");
			}
			else if(r%2!=0)
			{
				printf("U");
			}
			else 
			{
				printf("D");
			}
		}
		else
		{
			if(r%2==0 && c%2==0)
			{
				printf("L");
			}
			else if(r%2!=0 && c%2!=0)
			{
				printf("R");
			}
			else if(r%2!=0)
			{
				printf("R");
			}
			else 
			{
				printf("L");
			}
		}
		printf("\n");
	}
	return 0;
}
