#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	bool reverse=false;
	ll n;
	scanf("%lld",&n);
	string s;
	deque<int> q;
	while(n--)
	{
		cin>>s;
		if(s=="toFront")
		{
			int val;
			scanf("%d",&val);
			if(!reverse)
			{
				q.push_front(val);
			}
			else
			{
				q.push_back(val);
			}
		}
		else if(s=="front")
		{
			if(!reverse)
			{
				if(q.empty())
				{
					printf("No job for Ada?\n");
				}
				else
				{
					printf("%d\n",q.front());
					q.pop_front();
				}
			}
			else
			{
				if(q.empty())
				{
					printf("No job for Ada?\n");
				}
				else
				{
					printf("%d\n",q.back());
					q.pop_back();
				}
			}
		}
		else if(s=="back")
		{
			if(reverse)
			{
				if(q.empty())
				{
					printf("No job for Ada?\n");
				}
				else
				{
					printf("%d\n",q.front());
					q.pop_front();
				}
			}
			else
			{
				if(q.empty())
				{
					printf("No job for Ada?\n");
				}
				else
				{
					printf("%d\n",q.back());
					q.pop_back();
				}
			}
		}
		else if(s=="reverse")
			reverse=!reverse;
		else if(s=="push_back")
		{
			int val;
			scanf("%d",&val);
			if(reverse)
			{
				q.push_front(val);
			}
			else
			{
				q.push_back(val);
			}
		}
	}
	return 0;
}
