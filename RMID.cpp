#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	while(cin>>n)
	{
		queue< int > q;
		stack< int > s;
		if(n==0)
			continue;
		s.push(n);
		int ss=1,qs=0;
		scanf("%d",&n);
		while(n)
		{
			if(n==-1)
			{
				printf("%d\n",s.top());
				s.pop();
				ss--;
				if(ss<qs && qs!=0)
				{
					s.push(q.front());
					q.pop();
					ss++;
					qs--;
				}
			}
			else
			{
				if(ss==qs && ss!=0)
				{
					s.push(q.front());
					q.pop();
					ss++;
					q.push(n);
				}
				else if(ss>qs)
				{
					q.push(n);
					qs++;
				}
			}
			scanf("%d",&n);
		}
		printf("\n");
	}
	return 0;
}
