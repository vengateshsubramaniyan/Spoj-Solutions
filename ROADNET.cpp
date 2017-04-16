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
		int arr[n+1][n+1];
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				scanf("%d",&arr[i][j]);
		for(int a=1;a<=n;a++)
		{
			for(int b=a+1;b<=n;b++)
			{
				bool pa=true;
				for(int c=1;c<=n;c++)
				{
					if(c!=a && c!=b)
					{
						if((arr[a][c]+arr[c][b])==arr[a][b])
						{
							pa=false;
							break;
						}
					}
				}
				if(pa)
					printf("%d %d\n",a,b);
			}
		}
		printf("\n");
	}
}
