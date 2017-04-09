#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t,n,m,d,val;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&n,&m,&d);
		for(int i=0;i<n;i++)
		{
			scanf("%d",&val);
			if(val>d && m>0)
			{
				int r=val%d;
				m-=(val/d);
				if(r==0)
				{
					m++;
				}
			}
		}
		if(m>0)
			printf("NO");
		else
			printf("YES");
		if(t!=0)
			printf("\n");
	}
	return 0;
}
