#include<bits/stdc++.h>
using namespace std;
void recur(vector< pair<int,int> > &a,int per,int n,int m,long long &result)
{
	
	if(per==n)
	{
		if(m==0)
			result++;
		return ;
	}
	for(int i=a[per].first;i<=a[per].second;i++)
	{
		recur(a,per+1,n,m-i,result);
	}
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	while(n && m)
	{
		vector< pair<int,int> > a(n);
		for(int i=0;i<n;i++)
			scanf("%d%d",&a[i].first,&a[i].second);
		long long result=0;
		for(int i=a[0].first;i<=a[0].second;i++)
		{
			recur(a,1,n,m-i,result);
		}
		printf("%lld\n",result);
		scanf("%d%d",&n,&m);
	}
	return 0;
}
