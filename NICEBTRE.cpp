#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		char arr[10001];
		scanf("%s",arr);
		stack< int > s;
		int result=0;
		for(int i=0;arr[i]!='\0';i++)
		{
			if(arr[i]=='l')
			{
				if(result<s.size())
					result=s.size();
				if(!s.empty())
				{
					int val=s.top();
					s.pop();
					s.push(val+1);
				}
				while(!s.empty() && s.top()==3)
				{
					s.pop();
				}
			}
			else
			{
				if(!s.empty())
				{
					int val=s.top();
					s.pop();
					s.push(val+1);
				}
				s.push(1);
			}
		}
		printf("%d\n",result);
	}
	return 0;
}
