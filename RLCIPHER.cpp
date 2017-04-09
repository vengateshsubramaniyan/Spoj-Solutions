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
		for(int i=0;i<n;i++)
		{
			int val;
			scanf("%d",&val);
			if(val<0)
				printf("%d ",val);
			else if(val<3)
				printf("%d ",val-4);
			else if(val==5)
				printf("-3 ");
			else
				printf("-4 ");
		}
		printf("\n");
	}
	return 0;
}
