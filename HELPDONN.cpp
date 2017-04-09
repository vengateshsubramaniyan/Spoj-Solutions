#include<bits/stdc++.h>
using namespace std;
bool pos(int a[],int n,int k,int m)
{
	int cap=0;
	int bg=1;
	for(int i=0;i<n;)
	{
		if(a[i]>m)
			return false;
		if(cap+a[i]<=m)
		{
			cap+=a[i];
			i++;
		}
		else
		{
			bg++;
			cap=0;	
		}
	}
	return bg<=k;
}
int binary(int a[],int n,int k,int l,int r)
{
	int result=r;
	while(l<r)
	{
		int m=l+(r-l)/2;
		if(pos(a,n,k,m))
		{
			if(result>m)
				result=m;
			r=m;
		}
		else
			l=m+1;
	}
	return result;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,k;
		scanf("%d%d",&n,&k);
		int a[n];
		int r=0;
		for(int i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			r+=a[i];
		}
		printf("%d\n",binary(a,n,k,0,r));
	}
	return 0;
}
