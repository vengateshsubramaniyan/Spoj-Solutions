#include<bits/stdc++.h>
using namespace std;
int main()
{
	int arr[4][2];
	for(int i=0;i<4;i++)
		scanf("%d",&arr[i][0]);
	for(int i=0;i<4;i++)
		scanf("%d",&arr[i][1]);
	while(arr[0][0]!=-1)
	{
		int mc=0;
		for(int i=0;i<4;i++)
		{
			int te=arr[i][0]/arr[i][1];
			if((arr[i][0]%arr[i][1])!=0)
			{
				te++;
			}
			if(te>mc)
				mc=te;
		}
		for(int i=0;i<4;i++)
		{
			printf("%d ",(mc*arr[i][1])-arr[i][0]);
		}	
		printf("\n");
		for(int i=0;i<4;i++)
			scanf("%d",&arr[i][0]);
		for(int i=0;i<4;i++)
			scanf("%d",&arr[i][1]);
	}
	return 0;
}
