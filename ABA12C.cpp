#include<bits/stdc++.h>
#define INF 100001
using namespace std;
int main()
{
	long long t;
	scanf("%lld",&t);
	while(t--)
	{
		int n,k;
		scanf("%d%d",&n,&k);
		int val[k+1];
		for(int i=1;i<=k;i++)
			scanf("%d",&val[i]);
		int arr[k+1][k+1];
		for(int i=0;i<=k;i++)
		{
			int pre=INF;
			for(int j=0;j<=k;j++)
			{
				if(i==0 || j==0)
					arr[i][j]=0;
				else if(i<j || val[j]==-1)
					arr[i][j]=pre;
				else
				{
					int q=i/j;
					int r=i%j;
					arr[i][j]=min((q*val[j])+arr[r][j],pre);
					pre=arr[i][j];
				}
//				cout<<arr[i][j]<<" ";
			}
//			cout<<endl;
		}
		if(arr[k][k]==INF)
			printf("-1\n");
		else
			printf("%d\n",arr[k][k]);
	}
	return 0;
}
