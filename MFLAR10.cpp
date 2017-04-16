#include<bits/stdc++.h>
using namespace std;
int main()
{
	char arr[10000];
	scanf("%[^\n]s",arr);
	int len=strlen(arr);
	while((len!=1) || (arr[0]!='*'))
	{
		if(len==1)
			printf("Y\n");
		else
		{
			char c,cp;
			bool fo=true;
			for(int i=0;i<len;i++)
			{
				if(i==0)
				{
					if(arr[i]>='a')
					{
						c=arr[i];
						cp=arr[i]-32;
					}
					else
					{
						c=arr[i];
						cp=arr[i]+32;
					}
				}
				else
				if(arr[i]==' ' && i+1!=len)
				{
					if(arr[i+1]!=c && arr[i+1]!=cp)
					{
						fo=false;
						break;		
					}
				}
			}
			fo?printf("Y\n"):printf("N\n");
		}
		scanf("\n%[^\n]s",arr);
		len=strlen(arr);
	}
	return 0;
}
