#include<bits/stdc++.h>
#define ll long long
#define size 100001
using namespace std;
int cbs[size];
int cu[46];
void cube()
{
	for(int i=0;i<46;i++)
		cu[i]=(i+1)*(i+1)*(i+1);
}
void pre()
{
	for(int i=1;i<size;i++)
	{
		cbs[i]=INT_MAX;
		for(int j=45;j>=0;j--)
		{
			if(cu[j]>i)
				continue;
			cbs[i]=min(cbs[i],1+cbs[i-cu[j]]);
		}
	}
}
int main()
{
	int n,t=1;
	cube();
	pre();
	while(scanf("%d",&n)!=EOF)
	{
		printf("Case #%d: %d\n",t++,cbs[n]);
	}
	return 0;
}
