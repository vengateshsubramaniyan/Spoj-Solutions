#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		ll n;
		scanf("%lld",&n);
		ll s=100000;
		ll result=0;
		map< ll ,ll > m;
		m[s]=1;
		while(n--)
		{
			int val;
			scanf("%d",&val);
			s+=val;
			if(m.find(s)!=m.end())
			{
				result+=m[s];
			}
			m[s]++;
		}
		printf("%lld\n",result);
	}
	return 0;
}
