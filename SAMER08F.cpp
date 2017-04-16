#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long n;
	scanf("%lld",&n);
	while(n)
	{
		printf("%lld\n",(n*(n+1)*((2*n)+1))/6);
		scanf("%lld",&n);
	}
	return 0;
}
