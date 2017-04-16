#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	while(cin>>s)
	{
		string s1=s;
		reverse(s1.begin(),s1.end());
		s1=s1+'#'+s;
		int lps[s1.length()+1];
		lps[0]=0;
		int i=1;
		int len=0;
		while(i<s1.length())
		{
			if(s1[i]==s1[len])
			{
				len++;
				lps[i]=len;
				i++;
			}
			else
			{
				if(len!=0)
					len=lps[len-1];
				else
				{
					lps[i]=0;
					i++;
				}
			}
		}
		s1=s.substr(0,s.length()-lps[s1.length()-1]);
		reverse(s1.begin(),s1.end());
		cout<<s+s1<<endl;
	}
	return 0;
}
