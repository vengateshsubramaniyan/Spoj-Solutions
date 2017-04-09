#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	int m;
	scanf("%d",&m);
	while(m)
	{
		char s[1000000];
		vector<int> ele(256,0);
		ll dc=0,i=0,st=0;
		ll result=0;
		scanf("\n%[^\n]s",s);
		while(s[i]!='\0')
		{
			if(ele[s[i]]==0)
			{
				if(dc<m)
				{
					if(ele[s[i]]==0)
						dc++;
					ele[s[i]]++;
					i++;
				}
				else
				{
					ele[s[st]]--;
					if(ele[s[st]]==0)
						dc--;
					st++;
				}
			}
			else
			{
				ele[s[i]]++;
				i++;
			}		
			if(result<(i-st))
				result=i-st;
		}
		printf("%lld\n",result);
		scanf("%d",&m);
	}
	return 0;
}
