#include<bits/stdc++.h>
using namespace std;
int ceil(vector<int> &a,vector<int> &t,int l,int r,int key)
{
	while(r-l>1)
	{
		int m=l+(r-l)/2;
		if(a[t[m]]>=key)
		{
			r=m;
		}
		else
			l=m;
	}
	return r;
}
vector< int > lis(vector<int> a,int n,int &res,bool add)
{
	vector< int > result;
	vector< int > tail(n,-1);
	vector< int > temp(n,0);
	int len=1;
	for(int i=1;i<n;i++)
	{
		if(a[i]<a[temp[0]])
			temp[0]=i;
		else if(a[i]>a[temp[len-1]])
		{
			tail[i]=temp[len-1];
			temp[len++]=i;	
		}
		else
		{
			int ci=ceil(a,temp,-1,len-1,a[i]);
			tail[i]=temp[ci-1];
			temp[ci]=i;
		}
	}
	res=res+len;
	if(add)
	{
		for(int i=temp[len-1];i>=0;i=tail[i])
			a[i]=-1;
		for(int i=n-1;i>=0;i--)
		{
			if(a[i]!=-1)
				result.push_back(a[i]);
		}
	}
	return result;
}
int find(vector< int > &a,int n)
{
	int t=0;
	vector< int > temp;
	temp=lis(a,n,t,true);
	temp=lis(temp,temp.size(),t,false);
	if(t==n)
		return n;
	int t1=0;
	reverse(a.begin(),a.end());
	temp=lis(a,n,t1,true);
	temp=lis(temp,temp.size(),t1,false);
	if(t1==n)
		return n;
	return max(t,t1);
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		vector< int > a(n);
		for(int i=0;i<n;i++)
			scanf("%d",&a[i]);
		printf("%d\n",find(a,n));
	}
	return 0;
}
