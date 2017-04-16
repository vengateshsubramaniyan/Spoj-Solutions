#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	while(cin>>s)
	{
		long long len=s.length();
		bool sub=false;
		if(len==1 && (s=="0" || s=="1"))
		{
			cout<<s;
		}
		else
		{
			if(s[len-1]=='0')
			{
				s[len-1]='9';
				sub=true;	
			}
			else
			{
				--s[len-1];
			}
			for(int i=len-2;i>=0 && sub;i--)
			{
					if(s[i]=='0')
					{
						s[i]='9';
					}
					else
					{
						--s[i];
						sub=false;
					}
			}
			int carry=0;
			for(int i=len-1;i>=0;i--)
			{
				int val=s[i]-'0';
				val=(val*2)+carry;
				carry=0;
				if(val>9)
				{
					carry=1;
					val%=10;
				}
				s[i]=val+'0';
			}
			if(carry!=0)
			{
				char ar=carry+'0';
				s=ar+s;
			}
			cout<<s;
		}
		printf("\n");
	}
	return 0;
}
