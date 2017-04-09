#include<bits/stdc++.h>
using namespace std;
void lpsarray(char pat[],int len,int lps[])
{
	int i=1;
	int l=0;
	lps[0]=0;
	while(i<len)
	{
		if(pat[i]==pat[l])
		{
			l++;
			lps[i]=l;
			i++;
		}
		else
		{
			if(l!=0)
			{
				l=lps[l-1];
			}
			else
			{
				lps[i]=0;
				i++;
			}
		}
	}
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		char s[1000001];
		char pat[1000001];
		scanf("%s",s);
		scanf("%s",pat);
		int slen=strlen(s);
		int plen=strlen(pat);
		int lps[plen];
		lpsarray(pat,plen,lps);
		int i=0;
		int j=0;
		vector< int > result;
		while(i<slen)
		{
			if(s[i]==pat[j])
			{
				i++;
				j++;
			}
			if(j==plen)
			{
				result.push_back(i-j+1);
				j=lps[j-1];
			}
			else
			{
				if(i<slen && pat[j]!=s[i])
				{
					if(j!=0)
						j=lps[j-1];
					else
						i=i+1;
				}
			}
		}
		if(result.size()==0)
			printf("Not Found\n");
		else
		{
			printf("%d\n",result.size());
			for(int i=0;i<result.size();i++)
				printf("%d ",result[i]);
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}
