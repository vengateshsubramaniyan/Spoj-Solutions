#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		int a[n];
		for(int i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
//			cout<<i<<" "<<a[i]<<endl;
		}
		vector< int >lis(n,1);
		int res=1;
		for(int i=1;i<n;i++)
		{
			for(int j=0;j<i;j++)
			{
				if(a[i]<a[j] && lis[i]<lis[j]+1)
				{
					lis[i]=lis[j]+1;
				}
				if(a[i]>a[j] && j==m)
				{
					lis[i]=lis[j]+1;
				}
			}
			if(res<lis[i])
				res=lis[i];
		}
//		for(int i=0;i<n;i++)
//			cout<<lis[i]<<" ";
		printf("%d\n",res);
	}
	return 0;
}
