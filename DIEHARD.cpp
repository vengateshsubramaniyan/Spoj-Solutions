#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int ans=1;
		int h,a;
		scanf("%d%d",&h,&a);
		h+=3;
		a+=2;
		while(1)
		{
			if(h>20 && a<=10)
			{
				h-=17;
				a+=7;
				ans+=2;
			} 
			else if(h>5 && a>10)
			{
				h-=2;
				a-=8;
				ans+=2;
			}
			else
			{
				printf("%d\n",ans);
				break;
			}
		}
	}
	return 0;
}
