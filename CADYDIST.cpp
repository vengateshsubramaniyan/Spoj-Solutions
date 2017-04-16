#include<bits/stdc++.h>
#define ll long long unsigned int
static bool cmpp(const int a,const int b)
{
	return a>b;
}
using namespace std;
int main()
{
	long long n;
	scanf("%lld",&n);
	while(n)
	{
		vector< long long > c(n);
		vector< long long > p(n);
		for(int i=0;i<n;i++)
			scanf("%lld",&c[i]);
		for(int i=0;i<n;i++)
			scanf("%lld",&p[i]);
		sort(c.begin(),c.end());
		sort(p.begin(),p.end(),cmpp);
		ll result=0;
		for(int i=0;i<n;i++)
		{
			result+=(p[i]*c[i]);
		}
		cout<<result<<endl;
		scanf("%lld",&n);
	}
	return 0;
}
