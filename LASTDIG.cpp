#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		char b[15];
		int a;
		scanf("%d",&a);
		scanf("%s",b);
		int len=strlen(b);
		if(len==1 && b[0]=='0')
			printf("1");
		else if(a==0)
			printf("0");
		else
		{
			int mod=0;
			for(int i=0;i<len;i++)
			{
				mod=((mod*10)+(b[i]-'0'))%4;
			}
			if(mod==0)
				mod=4;
			a=a%10;
			int res=pow(a,mod);
			printf("%d",res%10);
		}
		printf("\n");
	}
	return 0;
}
