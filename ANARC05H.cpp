#include<bits/stdc++.h>
using namespace std;
int possible(char s[],int i,int psum)
{
	if(i<0)
		return 1;
	int sum=0;
	int res=0;
	for(;i>=0;i--)
	{
		sum+=(s[i]-'0');
		if(sum<=psum)
			res+=possible(s,i-1,sum);
		else
			break;
	}
	return res;
}
int main()
{
	char s[25];
	scanf("%s",s);
	int t=1;
	while(strcmp(s,"bye")!=0)
	{
		int res=0;
		int sum=0;
		int len=strlen(s);
		for(int i=len-1;i>=0;i--)
		{
			sum+=(s[i]-'0');
			res+=possible(s,i-1,sum);
		}
		printf("%d. %d\n",t,res);
		scanf("%s",s);
		t++;
	}
	return 0;
}
