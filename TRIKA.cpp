#include<bits/stdc++.h>
using namespace std;
int main()
{
	int r,c,x,y,result;
	scanf("%d%d",&r,&c);
	scanf("%d%d",&x,&y);
	x--,y--;
	int arr[r][c];
	for(int i=0;i<r;i++)
		for(int j=0;j<c;j++)
			scanf("%d",&arr[i][j]);
	for(int i=x;i<r;i++)
	{
		for(int j=y;j<c;j++)
		{
			if(i==x && j==y)
				continue;
			else if(i==x)
				arr[i][j]=arr[i][j-1]-arr[i][j];
			else if(j==y)
				arr[i][j]=arr[i-1][j]-arr[i][j];
			else 
				arr[i][j]=max(arr[i-1][j],arr[i][j-1])-arr[i][j];
			
		}
	}
	if(arr[r-1][c-1]<0)
		printf("N");
	else
		printf("Y %d",arr[r-1][c-1]);
}
