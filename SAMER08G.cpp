#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	while(n)
	{
		int arr[n];
		memset(arr,-1,sizeof(arr));
		bool res=true;
		for(int i=0;i<n;i++)
		{
			int c,pos;
			scanf("%d%d",&c,&pos);
			if(res)
			{
				int rel=i+pos;
				if(rel<0 || rel>=n || arr[rel]!=-1)
					res=false;
				else
					arr[rel]=c;
			}
		}
		if(res)
		{
			for(int i=0;i<n-1;i++)
				printf("%d ",arr[i]);
			printf("%d\n",arr[n-1]);
		}
		else
			printf("-1\n");
		scanf("%d",&n);
	}
	return 0;
}
