#include<bits/stdc++.h>
using namespace std;
int inceil(int tail[],int l,int r,int k)
{
	while(r-l>1)
	{
		int m=l+(r-l)/2;
		if(tail[m]>=k)
			r=m;
		else
			l=m;
	}
	return r;
}
void increasing(vector<int> &arr,int lis[],int n)
{
	int tail[n];
	memset(tail,0,sizeof(tail));
	tail[0]=arr[0];
	lis[0]=1;
	int len=1;
	for(int i=1;i<n;i++)
	{
		if(arr[i]<tail[0])
			tail[0]=arr[i];
		else if(arr[i]>tail[len-1])
			tail[len++]=arr[i];
		else
			tail[inceil(tail,-1,len-1,arr[i])]=arr[i];
		lis[i]=len;
	}
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		vector< int > arr(n);
		for(int i=0;i<n;i++)
			scanf("%d",&arr[i]);
		int lis[n];
		increasing(arr,lis,n);
//		for(int i=0;i<n;i++)
//			cout<<lis[i]<<" ";
//		cout<<endl;
		int dis[n];
		reverse(arr.begin(),arr.end());
		increasing(arr,dis,n);
//		for(int i=0;i<n;i++)
//			cout<<dis[i]<<" ";
//		cout<<endl;
		int j=n-2;
		int result=lis[0]+dis[n-1]-1;
		for(int i=1;i<n && j>=0;i++,j--)
		{
			if(result<(lis[i]+dis[j]-1))
				result=lis[i]+dis[j]-1;
		}
		printf("%d\n",result);
	}
	return 0;
}
