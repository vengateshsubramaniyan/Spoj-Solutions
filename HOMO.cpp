#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	ll n;
	scanf("%lld",&n);
	map<ll,ll> m;
	ll homo=0,hetro=0;
	while(n--)
	{
		ll val;
		char op[100];
		scanf("%s%lld",op,&val);
		if(strcmp("insert",op)==0)
		{
			m[val]++;
			if(m[val]==1)
				hetro++;
			else if(m[val]==2)
				homo++;
		}
		else
		{
			if(m.find(val)!=m.end()&&m[val]!=0)
			{
				m[val]--;
				if(m[val]==1)
					homo--;
				if(m[val]==0)
					hetro--;
			}
		}
//		cout<<homo<<" "<<hetro<<endl;
		if(homo==0 && hetro<2)
			printf("neither\n");
		else if(homo!=0 && hetro>1)
			printf("both\n");
		else if(homo!=0)
			printf("homo\n");
		else 
			printf("hetero\n");
	}
	return 0;
}
