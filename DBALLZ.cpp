#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int e,n;
		scanf("%d%d",&e,&n);
		int enr[n+1];
		int st=10000000;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&enr[i]);
			if(st>enr[i])
				st=enr[i];
		}
		int tspan[n+1];
		for(int i=1;i<=n;i++)
			scanf("%d",&tspan[i]);
		int val[e+1];
//		memset(val,0,sizeof(val));
		val[0]=0;
		int temp;
		for(int i=1;i<=e;i++)
		{
			val[i]=val[i-1];
			for(int j=1;j<=n;j++)
			{
				temp=0;
				if(i>=enr[j])
				{
					temp=tspan[j]+val[i-enr[j]];
					if(temp>val[i])
						val[i]=temp;
				}
			}
		}
		printf("%d\n",val[e]);
	}
	return 0;
}
