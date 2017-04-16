#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long y,p,c;
//	while(1)
//	{
		c=0;
		scanf("%lld%lld",&y,&p);
		while(p!=0)
		{
			if(p&1)
				c++;
			p=p>>1;
		}
		if(y%2==0)
		{
			if(c%2==0)
				printf("red");
			else
				printf("blue");
		}
		else
		{
			if(c%2!=0)
				printf("red");
			else
				printf("blue");	
		}
//		cout<<endl;
//	}
	return 0;
}
