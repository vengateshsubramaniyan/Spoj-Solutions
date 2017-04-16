#include<bits/stdc++.h>
using namespace std;
int pri(char ck)
{
	if(ck=='+')
		return 1;
	if(ck=='-')
		return 2;
	if(ck=='*')
		return 3;
	if(ck=='/')
		return 4;
	if(ck=='^')
		return 5;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		char result[500];
		int r=0;
		char s[500];
		scanf("%s",s);
		stack<char> st;
		for(int i=0;s[i]!='\0';)
		{
			if(s[i]>='a' && s[i]<='z')
				result[r++]=s[i++];
			else if(s[i]=='(')
				st.push(s[i++]);
			else if(s[i]==')')
			{
				while(!st.empty() && st.top()!='(')
				{
					result[r++]=st.top();
					st.pop();
				}
				if(!st.empty())
					st.pop();
				i++;
			}
			else 
			{
				if(st.empty())
					st.push(s[i++]);
				else 
				{
					while(!st.empty() && st.top()!='(' && pri(st.top())>pri(s[i]))
					{
						result[r++]=st.top();
						st.pop();
					}
					st.push(s[i++]);
				}
			}
		}
		result[r]='\0';
		printf("%s\n",result);
	}
	return 0;
}
