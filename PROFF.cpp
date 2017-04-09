#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	ll a,b;
	scanf("%lld%lld",&a,&b);
	while(a!=0 || b!=0)
	{
		int result=0;
		int carry=0;
		while(a!=0 || b!=0)
		{
			int a1=0,b1=0;
			if(a!=0)
			{
				a1=a%10;
				a/=10;
			}
			if(b!=0)
			{
				b1=b%10;
				b/=10;
			}
			carry=a1+b1+carry;
			if(carry>=10)
			{
				result++;
				carry/=10;
			}
			else
				carry=0;
		}
		if(result==0)
			printf("No carry operation.\n");
		else if(result==1)
			printf("1 carry operation.\n");
		else
			printf("%d carry operations.\n",result);
		scanf("%lld%lld",&a,&b);
	}
	return 0;
}
