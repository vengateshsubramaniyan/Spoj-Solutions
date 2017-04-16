#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	int arr[n];
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);
	char s[100001];
	scanf("%s",s);
	int len=strlen(s);
	int in=0;
	while(len!=2 || (s[0]!='-' && s[1]!='1'))
	{
		for(int i=0;s[i]!='\0';i++)
		{
			int a=s[i]-'a';
			a+=arr[in];
			a=a%26;
			s[i]='a'+a;
			in=(in+1)%n;
		}
		printf("%s\n",s);
		scanf("%s",s);
		len=strlen(s);
	}
	return 0;
}
