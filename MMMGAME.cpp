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
		int a[n];
		for(int i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		int count=0;
		for(int i=0;i<n;i++)
		{
			if(a[i]==1)
				count++;
		}
		if(count==n)
		{
			if(n&1)
				printf("Brother\n");
			else
				printf("John\n");
		}
		else
		{
			int xsum=0;
			for(int i=0;i<n;i++)
				xsum^=a[i];
			if(xsum==0)
				printf("Brother\n");
			else
				printf("John\n");
		}
	}
	return 0;
}
