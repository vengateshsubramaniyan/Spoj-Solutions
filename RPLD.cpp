#include<bits/stdc++.h>
using namespace std;
int main()
{
	int test;
	scanf("%d",&test);
	for(int t=1;t<=test;t++)
	{
		int n,r;
		scanf("%d%d",&n,&r);
		vector< vector<bool> >ar(n+1,vector<bool>(10000,false));
		bool result=true;
		while(r--)
		{
			int id,cor;
			scanf("%d%d",&id,&cor);
			if(ar[id][cor])
				result=false;
			ar[id][cor]=true;
		}
		if(result)
			printf("Scenario #%d: possible\n",t);
		else
			printf("Scenario #%d: impossible\n",t);
	}
	return 0;
}
