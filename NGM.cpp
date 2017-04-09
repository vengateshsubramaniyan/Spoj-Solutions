#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long n,val;
	scanf("%lld",&n);
	if(n==0 || n%10==0)
	{
		printf("2");
	}
	else
	{
		printf("1\n");
		while(n!=0)
		{
			val=n%10;
			n/=10;
			if(val!=0)
			{
				printf("%lld",val);
				break;
			}
		}
	}
	return 0;
}
