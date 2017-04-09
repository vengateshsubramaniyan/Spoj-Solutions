#include<bits/stdc++.h>
using namespace std;
bool tree(char s[],int &start,int len,bool conj)
{
	bool re=false;
	if(conj)
		re=true;
	while(start<len && s[start]!=')')
	{
//		cout<<start<<" ";
		bool r;
		if(s[start]=='(')
		{
			start++;
			r=tree(s,start,len,!conj);
		}
		else
		{
			if(s[start]=='T')
				r=true;
			else
				r=false;
			start++;
		}
		if(conj)
			re=re&r;
		else
			re=re|r;
	}
	start++;
	return re;
}
int main()
{
	char s[32001];
	scanf("%s",s);
	int len=strlen(s);
	int t=1;
	while(len!=2 || s[0]!='(' || s[1]!=')')
	{
		int level=0;
		int op=0;
		for(int i=0;s[i]!='\0';i++)
		{
			if(s[i]=='(')
				op++;
			if(s[i]==')')
				op--;
			if(op>level)
				level=op;
		}
		bool conj=false;
		if(level%2!=0)
			conj=true;
		int start=1;
		bool re=tree(s,start,len,conj);
		re?printf("%d. true\n",t++):printf("%d. false\n",t++);
		scanf("%s",s);
		len=strlen(s);
	}
	return 0;
}
