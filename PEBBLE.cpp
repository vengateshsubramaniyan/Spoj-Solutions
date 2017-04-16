#include<bits/stdc++.h>
using namespace std;
int main()
{
	char arr[1001];
	int t=1;
	while(scanf("%s",arr)!=EOF)
	{
		int fc=0;
		for(int i=0;arr[i]!='\0';i++)
		{
			if(arr[i]=='1' && fc%2==0)
				fc++;
			else if(arr[i]=='0' && fc%2!=0)
				fc++;
		}
		printf("Game #%d: %d\n",t++,fc);
	}
}
