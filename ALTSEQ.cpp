#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	int a[n];
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	int lis[n];
	for(int i=0;i<n;i++)
		lis[i]=1;
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<i;j++)
		{
			if(a[i]<0)
			{
				if(a[j]>0 && abs(a[i])>a[j])
					lis[i]=max(lis[i],lis[j]+1);
			}
			else
			{
				if(a[j]<0 && abs(a[j])<a[i])
					lis[i]=max(lis[i],lis[j]+1);
			}
		}
	}
	int result=1;
	for(int i=0;i<n;i++)
		result=max(result,lis[i]);
	printf("%d",result);
	return 0;
}
