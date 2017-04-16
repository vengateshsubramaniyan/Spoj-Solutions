#include<bits/stdc++.h>
using namespace std;
int main()
{
	char s[100001];
	while(scanf("%s",s)!=EOF)
	{
		string result="";
		int c=1;
		char cc=s[0];
		for(int i=1;s[i]!='\0';i++)
		{
			if(cc==s[i])
				c++;
			else
			{
				if(c>3)
				{
					ostringstream ss;
					ss<<c;
					result=result+ss.str()+'!'+cc;
				}
				else
				{
					while(c)
					{
						result=result+cc;
						c--;
					}
				}
				cc=s[i];
				c=1;
			}
		}
		if(c!=0)
		{
			if(c>3)
			{
				ostringstream ss;
				ss<<c;
				result=result+ss.str()+'!'+cc;
			}
			else
			{
				while(c)
				{
					result=result+cc;
					c--;
				}
			}
		}
		cout<<result<<endl;
	}
	return 0;
}
