#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	ll t;
	scanf("%lld",&t);
	while(t--)
	{
		bool oper=false,bre=true;
		char op='^';
		ll n1,n2;
		while(bre)
		{
			if(!oper)
			{
				scanf("%lld",&n2);
				if(op=='^')
					n1=n2;
				else if(op=='+')
					n1+=n2;
				else if(op=='-')
					n1=n1-n2;
				else if(op=='*')
					n1*=n2;
				else
					n1/=n2;
				oper=true;
			}
			else
			{
				scanf(" %c",&op);
				if(op=='=')
					bre=false;
				oper=false;
			}
		}
		printf("%lld\n",n1);
	}
	return 0;
}
