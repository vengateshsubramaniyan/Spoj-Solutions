#include<bits/stdc++.h>
using namespace std;
int main()
{
	int pos[1000001];
	memset(pos,0,sizeof(pos));
	for(int i=2;i<=100;i++)
	{
		for(int j=i*i*i;j<1000001;j=j+(i*i*i))
			pos[j]=-1;
	}
	int c=1;
	for(int i=1;i<1000001;i++)
	{
		if(pos[i]!=-1)
			pos[i]=c++;
	}
	int test;
	scanf("%d",&test);
	for(int t=1;t<=test;t++)
	{
		int n;
		scanf("%d",&n);
		if(pos[n]==-1)
			printf("Case %d: Not Cube Free\n",t);
		else
			printf("Case %d: %d\n",t,pos[n]);
	}
	return 0;
}
