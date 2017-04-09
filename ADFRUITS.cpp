#include<bits/stdc++.h>
using namespace std;
void lcs(char s[],char s1[],int n,int m)
{
	int l[n+1][m+1];
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=m;j++)
		{
			if(i==0)
				l[i][j]=j;
			else if(j==0)
				l[i][j]=i;
			else if(s[i-1]==s1[j-1])
			{
				l[i][j]=1+l[i-1][j-1];
			}
			else
				l[i][j]=1+min(l[i-1][j],l[i][j-1]);
		}
	}
	string res;
	int i=n,j=m;
	while(i>0 && j>0)
	{
		if(s[i-1]==s1[j-1])
		{
			res.push_back(s[i-1]);
			i--,j--;
		}
		else if(l[i-1][j]>l[i][j-1])
		{
			res.push_back(s1[j-1]);
			j--;
		}
		else
		{
			res.push_back(s[i-1]);
			i--;
		}
	}
	while(i>0)
	{
		res.push_back(s[i-1]);
		i--;
	}
	while(j>0)
	{
		res.push_back(s1[j-1]);
		j--;
	}
	reverse(res.begin(),res.end());
	cout<<res<<endl;
}
int main()
{
	char s[1000];
	while(scanf("%s",s)!=EOF)
	{
		char s1[1000];
		scanf("%s",s1);
		lcs(s,s1,strlen(s),strlen(s1));
	}
	return 0;
}
