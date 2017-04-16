#include<bits/stdc++.h>
using namespace std;
int ceil(int a[],int l,int r,int val)
{
	while(r-l>1)
	{
		int m=l+(r-l)/2;
		(a[m]>=val?r:l)=m;
	}
	return r;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		int a[n],temp;
		for(int i=0;i<n;i++)
		{
			scanf("%d",&temp);
			a[temp]=i;
		}
		int b[n];
		for(int i=0;i<n;i++)
		{
			scanf("%d",&temp);
			b[i]=a[temp];
		}
		int len=1;
		a[0]=b[0];
		for(int i=1;i<n;i++)
		{
			if(b[i]<a[0])
				a[0]=b[i];
			else if(b[i]>a[len-1])
				a[len++]=b[i];
			else
				a[ceil(a,-1,len-1,b[i])]=b[i];
		}
		printf("%d\n",len);
	}
	return 0;
}
