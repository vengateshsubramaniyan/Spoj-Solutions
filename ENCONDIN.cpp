#include<bits/stdc++.h>
using namespace std;
int main()
{
	char s[100001];
	while(gets(s))
	{
		int len=strlen(s);
		int count=0;
		bool unique=false;
		string result="";
		for(int i=0;s[i]!='\0';i++)
		{
			if(i==len-1)
			{
				if(unique)
				{
					if(s[i]=='1')
						result=result+"111";
					else
						result=result+s[i]+'1';
				}
				else
				{
					if(count==0)
					{
						if(s[i]=='1')	
							result=result+"1111";
						else
							result=result+'1'+s[i]+'1';
					}
					else
					{
						count++;
						result=result+(char)(count+'0')+s[i];
					}
				}
			}
			else
			{
				if(s[i]!=s[i+1])
				{
					if(count==0)
					{
						if(unique)
						{
							if(s[i]=='1')
								result=result+"11";
							else
								result=result+s[i];
						}
						else if(count==0)
						{
							unique=true;
							if(s[i]=='1')
								result=result+"111";
							else
								result=result+'1'+s[i];
						}
						else
						{
							result=result+(char)(count+'0')+s[i];
						}
					}
					else
					{
						count++;
						result=result+(char)(count+'0')+s[i];
						count=0;
					}	
				}
				else
				{
					if(unique)
					{
						unique=false;
						result=result+'1';
					}
					count++;
					if(count==9)
					{
						result=result+'9'+s[i];
						count=0;
					}
				}
			}
		}
		cout<<result<<endl;
	}
	return 0;
}
