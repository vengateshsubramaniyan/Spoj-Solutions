#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long t;
	scanf("%lld",&t);
	while(t--)
	{
		long long n;
		scanf("%lld",&n);
		if(n%2==0)
			printf("1\n");
		else
			printf("0\n");
	}
	return 0;
}
