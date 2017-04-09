#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	char arr[51][51];
	while(t--)
	{
		scanf("%s",arr[0]);
		int len=strlen(arr[0]);
		for(int i=1;i<len;i++)
			scanf("%s",arr[i]);
		int id=0,count=0;
		for(int i=0;i<len;i++)
		{
			int co=0;
			for(int j=0;j<len;j++)
			{
				if(arr[i][j]=='N' && i!=j)
				{
					bool pos=false;
					for(int k=0;k<len && !pos;k++)
					{
						if(arr[i][k]=='Y' && arr[k][j]=='Y')
							pos=true;
					}
					if(pos)
						co++;
				}
			}
			if(count<co)
			{
				count=co;
				id=i;
			}
		}
		printf("%d %d\n",id,count);
	}
	return 0;
}
