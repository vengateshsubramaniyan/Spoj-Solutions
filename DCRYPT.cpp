#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int k;
		scanf("%d",&k);
		char s[100001];
		scanf("%s",s);
		for(int i=0;s[i]!='\0';i++)
		{
			if(s[i]=='.')
			{
				s[i]=' ';
			}
			else
			{
				if(k<26)
				{
					if(s[i]>='a' && s[i]<='z')
					{
						int t1=s[i]-'a';
						t1+=k;
						t1=t1%26;
						s[i]=(char)'a'+t1;
					}
					else
					{
						int t1=s[i]-'A';
						t1+=k;
						t1=t1%26;
						s[i]=(char)'A'+t1;
					}
				}
				else
				{
					if(s[i]>='a' && s[i]<='z')
					{
						int t1=s[i]-'a';
						t1+=k;
						t1=t1%26;
						s[i]=(char)'a'+t1;
						s[i]-=32;
					}
					else
					{
						int t1=s[i]-'A';
						t1+=k;
						t1=t1%26;
						s[i]=(char)'A'+t1;
						s[i]+=32;
					}
				}
			}
		}
		printf("%s\n",s);
	}
	return 0;
}
