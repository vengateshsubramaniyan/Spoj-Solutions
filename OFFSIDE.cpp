#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	while(a && b)
	{
		int a1=INT_MAX,b1=INT_MAX,b2=INT_MAX,temp;
		for(int i=0;i<a;i++)
		{
			scanf("%d",&temp);
			if(temp<a1)
				a1=temp;
		}
		for(int i=0;i<b;i++)
		{
			scanf("%d",&temp);
			if(temp<=b1)
			{
				b2=b1;
				b1=temp;
			}
			else if(temp<b2)
			{
				b2=temp;
			}
		}
		if(a1<b2)
			printf("Y");
		else
			printf("N");
		printf("\n");
		scanf("%d%d",&a,&b);
	}
	return 0;
}
