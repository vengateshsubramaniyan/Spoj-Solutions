#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	int arr[n][m];
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			scanf("%d",&arr[i][j]);
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(j==0)
			{
				int a=(j+1)==n?arr[i-1][j]:min(arr[i-1][j],arr[i-1][j+1]);
				arr[i][j]+=a;
			}
			else if(j==n-1)
			{
				int a=(j-1)==-1?arr[i-1][j]:min(arr[i-1][j],arr[i-1][j-1]);
				arr[i][j]+=a;
			}
			else
			{
				int a=arr[i-1][j];
				a=min(a,min(arr[i-1][j-1],arr[i-1][j+1]));
				arr[i][j]+=a;
			}
		}
	}
	int result=INT_MAX;
	for(int i=0;i<n;i++)
	{
		if(result>arr[n-1][i])
			result=arr[n-1][i];
	}
	printf("%d",result);
	return 0;
}
