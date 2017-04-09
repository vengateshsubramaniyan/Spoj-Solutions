#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	while(n)
	{
		stack<int> s;
		int curr=1;
		vector< int > arr(n);
		for(int i=0;i<n;i++)
			scanf("%d",&arr[i]);
		for(int i=0;i<n;i++)
		{
			if(arr[i]==curr)
			{
				curr++;
				continue;
			}
			else
			{
				while(!s.empty() && s.top()==curr)
				{
					s.pop();
					curr++;
				}
				s.push(arr[i]);
			}
		}
		 while(!s.empty() && s.top()==curr)
		{
			s.pop();
			curr++;
		}
		if(curr==n+1)
			printf("yes\n");
		else
			printf("no\n");
		scanf("%d",&n);
	}
	return 0;
}
