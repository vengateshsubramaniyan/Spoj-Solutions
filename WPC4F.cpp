#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		vector< vector<int> > arr(n,vector<int>(3));
		for(int i=0;i<n;i++)
			scanf("%d%d%d",&arr[i][0],&arr[i][1],&arr[i][2]);
		for(int i=1;i<n;i++)
		{
			arr[i][0]+=min(arr[i-1][1],arr[i-1][2]);
			arr[i][1]+=min(arr[i-1][0],arr[i-1][2]);
			arr[i][2]+=min(arr[i-1][0],arr[i-1][1]);
		}
		int result=min(arr[n-1][0],min(arr[n-1][1],arr[n-1][2]));
		printf("%d\n",result);
	}
}
