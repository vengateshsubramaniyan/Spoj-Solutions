#include<bits/stdc++.h>
struct plane
{
	int s;
	int d;
	int c;
};
bool cmpp(plane a,plane b)
{
	return a.d<b.d;
}
int binary(plane a[],int n,int i)
{
	int low=0,high=i-1;
	while(low<=high)
	{
		int mid=low+(high-low)/2;
		if(a[mid].d<=a[i].s)
		{
			if(mid+1<n && a[mid+1].d<=a[i].s)
				low=mid+1;
			else
				return mid;
		}
		else
			high=mid-1;
	}
	return -1;
}
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		plane a[n];
		for(int i=0;i<n;i++)
		{
			scanf("%d%d%d",&a[i].s,&a[i].d,&a[i].c);
			a[i].d+=a[i].s;
		}
		sort(a,a+n,cmpp);
		int res[n];
		res[0]=a[0].c;
		for(int i=1;i<n;i++)
		{
			int incl=a[i].c;
			int l=binary(a,n,i);
			if(l!=-1)
				incl+=res[l];
			res[i]=max(incl,res[i-1]);
		}
		printf("%d\n",res[n-1]);
	}
	return 0;
}
