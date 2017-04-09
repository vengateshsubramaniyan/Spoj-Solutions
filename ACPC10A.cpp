#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	while(a!=0 || b!=0 ||  c!=0)
	{
		if((b-a)==(c-b))
		{
			printf("AP %d\n",c+(c-b));
		}
		else
		{
			printf("GP %d\n",c*(b/a));
		}
		scanf("%d%d%d",&a,&b,&c);
	}
	return 0;
}
