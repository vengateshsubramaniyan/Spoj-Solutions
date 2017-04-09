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
		int in=0,pos=0;
		int arr[n];
		for(int i=0;i<n;i++)
		{
			int val;
			scanf("%d%d",&val,&arr[i]);
			if(val>in)
			{
				in=val;
				pos=i;
			}
		}
		bool p=true;
		for(int i=0;i<n;i++)
		{
			if(i!=pos && arr[i]>=in)
			{
				p=false;
				break;
			}
		}
		if(p)
			printf("%d\n",pos+1);
		else
			printf("-1\n");
	}
	return 0;
}
