#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		char s[10001];
		scanf("%s",s);
		string res="";
		for(int i=0;s[i]!='\0';i++)
		{
			if(s[i]=='0')
				res="";
			else if(s[i]>'0' && s[i]<='9')
			{
				string temp=res;
				int d=s[i]-'0';
				for(int i=1;i<d;i++)
				{
					res+=temp;
				}
			}
			else
				res+=s[i];
		}
		int q;
		scanf("%d",&q);
		while(q--)
		{
			int pos;
			scanf("%d",&pos);
			if(pos>res.length())
				printf("-1\n");
			else
				printf("%c\n",res[pos-1]);
		}
	}
	return 0;
}
