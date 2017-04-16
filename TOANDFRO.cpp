#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	while(n)
	{
		string s;
		cin>>s;
		int len=s.length();
		int start=2*n;
		start--;
		int end=1;
		int col=1;
		int k=0;
		string result="";
		while(start>0)
		{
			if(k<len)
			{
				result+=s[k];
				k+=start;
				if(k<len)
				{
					result+=s[k];
					k+=end;
				}
			}
			else
			{
				k=col;
				col++;
				start-=2;
				end+=2;
			}
		}
		cout<<result<<endl;
		scanf("%d",&n);
	}
	return 0;
}
