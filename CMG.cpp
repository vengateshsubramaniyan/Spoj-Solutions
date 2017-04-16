#include<bits/stdc++.h>
using namespace std;
int main()
{
	int test;
	scanf("%d",&test);
	for(int t=1;t<=test;t++)
	{
		int q;
		scanf("%d",&q);
		vector< int > v1;
		vector< int > v2;
		printf("Case %d:\n",t);
		while(q--)
		{
			char op;
			scanf("\n%c",&op);
//			cout<<op<<endl;
			if(op=='Q')
			{
				if(v2.empty())
					printf("Empty\n");
				else
					printf("%d\n",v2.back());
			}
			else if(op=='R')
			{
				if(!v1.empty())
				{
					int val=v1.back();
					if(val==v2.back())
						v2.pop_back();
					v1.pop_back();
				}
			}
			else
			{
				int val;
				scanf("%d",&val);
				v1.push_back(val);
				if(v2.empty() || v2.back()<=val)
					v2.push_back(val);
			}
		}
	}
	return 0;
}
