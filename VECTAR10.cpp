#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long n;
	scanf("%lld",&n);
	while(n)
	{
		long long p=1;
		while(p<n)
		{
			p*=2;
		}
		printf("%lld\n",(2*n)-p);
		scanf("%lld",&n);
	}
	return 0;
}
