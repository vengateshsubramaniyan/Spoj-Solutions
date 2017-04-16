#include<bits/stdc++.h>
using namespace std;
void BIT(vector< int > &arr,int index,int n,int val)
{
	index=index+1;
	while(index<=n)
	{
		arr[index]+=val;
		index+=index&(-index);
	}
}
void update(vector< int > &arr,int s,int e,int n,int val)
{
	BIT(arr,s,n,val);
	BIT(arr,e+1,n,-val);
}
int find(vector< int > &arr,int in)
{
	in=in+1;
	int result=0;
	while(in>0)
	{
		result+=arr[in];
		in-=in&(-in);
	}
	return result;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,u;
		scanf("%d%d",&n,&u);
		vector< int > arr(n+1,0);
		while(u--)
		{
			int s,e,val;
			scanf("%d%d%d",&s,&e,&val);
			update(arr,s,e,n,val);
		}
		int q;
		scanf("%d",&q);
		while(q--)
		{
			int in;
			scanf("%d",&in);
			printf("%d\n",find(arr,in));
		}
		arr.clear();
	}
	
	return 0;
}
