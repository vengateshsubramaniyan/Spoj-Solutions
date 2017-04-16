#include<bits/stdc++.h>
using namespace std;
int main()
{
	char arr[3000];
	scanf("%s",arr);
	int t=1;
	while(arr[0]!='-')
	{
		int len=strlen(arr);
		int result=0;
		int open=0;
		for(int i=0;i<len;i++)
		{
			if(arr[i]=='{')
				open++;
			else
			{
				if(open!=0)
					open--;
				else
				{
					open++;
					result++;
				}
			}
		}
		result+=open/2;
		printf("%d. %d\n",t++,result);
		scanf("%s",arr);
	}
	return 0;
}
