#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	while(n!=-1)
	{
		int total=0;
		int a[n];
		for(int i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			total+=a[i];
		}
		if(total%n!=0)
			printf("-1\n");
		else
		{
			total/=n;
			int result=0;
			for(int i=0;i<n;i++)
			{
				if(a[i]<total)
					result+=(total-a[i]);
			}
			printf("%d\n",result);
		}
		scanf("%d",&n);
	}
	return 0;
}
