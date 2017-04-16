#include<bits/stdc++.h>
using namespace std;
int main()
{
	int g,b;
	scanf("%d%d",&g,&b);
	while(g!=-1 && b!=-1)
	{
		if(g==0 || b==0)
			printf("%d",max(g,b));
		else
		{
			if(g==b)
				printf("1");
			else if(g>b)
			{
				b++;
				int result=g/b;
				if(g%b!=0)
					result++;
				printf("%d",result);
			}
			else
			{
				g++;
				int result=b/g;
				if(b%g!=0)
					result++;
				printf("%d",result);
			}
		}
		scanf("%d%d",&g,&b);
		if(g!=-1 && b!=-1)
			printf("\n");
	}
	return 0;
}
