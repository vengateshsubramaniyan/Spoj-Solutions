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
		int arr[n];
		int curr,count=0,val;
		for(int i=0;i<n;i++)
		{
			if(i==0)
			{
				scanf("%d",&arr[i]);
				curr=arr[i];
				count=1;
			}
			else
			{
				scanf("%d",&arr[i]);
				if(curr==arr[i])
					count++;
				else
					count--;
				if(count==0)
				{
					curr=arr[i];
					count=1;
				}
			}
		}
		count=0;
		for(int i=0;i<n;i++)
			if(arr[i]==curr)
				count++;
		if(count>n/2)
			printf("YES %d\n",curr);
		else
			printf("NO\n");
	}
}
