#include<bits/stdc++.h>
using namespace std;
bool ifpali(char s[],int i,int j)
{
	while(i<j)
	{
		if(s[i]!=s[j])
			return false;
		i++;
		j--;
	}
	return true;
}
int main()
{
	int k;
	scanf("%d",&k);
	char s[30001];
	scanf("%s",s);
	int len=strlen(s);
	if(k>len)
		printf("0");
	else
	{
		int res=0;
		if(ifpali(s,0,k-1))
			res=1;
		for(int i=1;i<len;i++)
		{
			if((i+k)>len)
				break;
			if(ifpali(s,i,i+k-1))
				res++;
		}
		printf("%d",res);
	}	
	return 0;
}
