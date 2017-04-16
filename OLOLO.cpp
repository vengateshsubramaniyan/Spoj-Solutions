#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long n;
	scanf("%lld",&n);
	long long result=0;
	for(int i=0;i<n;i++)
	{
		long long val;
		scanf("%lld",&val);
		result=result^val;
	}
	printf("%lld",result);
	return 0;
}
