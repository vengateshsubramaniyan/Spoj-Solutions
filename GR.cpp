#include<bits/stdc++.h>
using namespace std;
int n;
void rotate(int mat[30][30],int r)
{
	
	while(r--)
	{
	    for (int x = 0; x < n / 2; x++)
	    {
	        for (int y = x; y < n-x-1; y++)
	        {
	            int temp = mat[x][y];
	            mat[x][y] = mat[n-1-y][x];
	            mat[n-1-y][x]=mat[n-1-x][n-1-y];
	            mat[n-1-x][n-1-y]=mat[y][n-1-x];
	            mat[y][n-1-x]=temp;
	        }
	    }
	}
}
int main()
{
	long long t;
	scanf("%d%lld",&n,&t);
	int arr[30][30];
	int c=1;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			arr[i][j]=c++;
	int top=0,bottom=0,left=0,right=0;
	for(int i=0;i<n;i++)
		top+=arr[0][i];
	for(int i=0;i<n;i++)
		bottom+=arr[n-1][i];
	for(int i=0;i<n;i++)
		left+=arr[i][0];
	for(int i=0;i<n;i++)
		right+=arr[i][n-1];
	int r=t%4;
	rotate(arr,r);
	while(r--)
	{
		int temp=right;
		right=top;
		top=left;
		left=bottom;
		bottom=temp;
	}
	if(top>left && top>right && top>bottom)
		printf("Ameen");
	else if(left>top && left>bottom && left>right)
		printf("Sameh");
	else if(right>top && right>left && right>bottom)
		printf("Shafeek");
	else
		printf("Atef");
	printf("\n");
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			printf("%d ",arr[i][j]);
		printf("\n");
	}
	return 0;
}
