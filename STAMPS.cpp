#include<bits/stdc++.h>
using namespace std;
int main()
{
	int test;
	scanf("%d",&test);
	for(int t=1;t<=test;t++)
	{
		int re,n;
		scanf("%d%d",&re,&n);
		vector< int > arr(n);
		for(int i=0;i<n;i++)
			scanf("%d",&arr[i]);
		printf("Scenario #%d:\n",t);
		if(re==0)
		{
			printf("0\n");	
		}
		else
		{
			sort(arr.begin(),arr.end());
			int result=0;
			int cal=0;
			for(int i=n-1;i>=0;i--)
			{
				cal+=arr[i];
				result++;
				if(cal>=re)
					break;
			}
			if(cal<re)
			{
				printf("impossible\n");
			}
			else
				printf("%d\n",result);
		}
		if(t!=test)
			printf("\n");
	}
	return 0;
}
