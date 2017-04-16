#include<bits/stdc++.h>
#define in int
#define vi vector<in>
#define vvi vector<vi>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int r,c;
		scanf("%d%d",&r,&c);
		vvi arr(r,vi(c));
		for(int i=0;i<r;i++)
		{
			for(int j=0;j<c;j++)
			{
				scanf("%d",&arr[i][j]);
			}
		}
		for(int i=1;i<r;i++)
		{
			for(int j=0;j<c;j++)
			{
				if(j==0 && j+1!=c)
				{
					arr[i][j]+=max(arr[i-1][j],arr[i-1][j+1]);
				}
				else if(j==c-1 && j-1!=-1)
				{
					arr[i][j]+=max(arr[i-1][j],arr[i-1][j-1]);
				}
				else if(j-1!=-1 && j+1!=c)
					arr[i][j]+=max(arr[i-1][j],max(arr[i-1][j-1],arr[i-1][j+1]));
				else
					arr[i][j]+=arr[i-1][j];
			}
		}
		int result=0;
		for(int i=0;i<c;i++)
		{
			if(result<arr[r-1][i])
				result=arr[r-1][i];
		}
		printf("%d\n",result);
	}
	return 0;
}
