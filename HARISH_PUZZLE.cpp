#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		char arr[8][8];
		for(int i=0;i<8;i++)
			scanf("%s",arr[i]);
		vector< int > r(8,0);
		vector< int > c(8,0);
		int rc=0;
		for(int i=0;i<8;i++)
		{
			for(int j=0;j<8;j++)
			{
				if(arr[i][j]=='R')
				{
					rc++;
					r[i]++;
					c[j]++;
				}
			}
		}
		if(rc< 8 || rc>8)
			printf("NO\n");
		else
		{
			bool cr=true;
			for(int i=0;i<8;i++)
			{
				for(int j=0;j<8;j++)
				{
					if(arr[i][j]=='R')
					{
						if(r[i]>1 || c[j]>1)
							cr=false;
					}
				}
			}
			cr?printf("YES\n"):printf("NO\n");
		}
	}
	return 0;
}
