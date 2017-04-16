#include<bits/stdc++.h>
using namespace std;
int kmp(char s[])
{
	int n=strlen(s);
	int lps[n];
	lps[0]=0;
	int len=0,i=1;
	while(i<n)
	{
		if(s[i]==s[len])
		{
			len++;
			lps[i]=len;
			i++;
		}
		else
		{
			if(len!=0)
			{
				len=lps[len-1];
			}
			else
			{
				lps[i]=0;
				i++;
			}
		}
	}
	return lps[n-1];
}
int main()
{
	char s[1000001];
	int n;
	scanf("%d",&n);
	scanf("%s",s);
	while(n!=-1)
	{
		int len=strlen(s);
		if(n<len)
		{
			printf("0\n");
		}
		else
		{
			int t=kmp(s);
			int res=1+((n-len)/(len-t));
			printf("%d\n",res);
		}
		scanf("%d",&n);
		scanf("%s",s);
	}	
	return 0;
}
