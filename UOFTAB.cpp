#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		vector< bool >curr(n,false);
		vector< pair<int,int> >pa(n);
		vector< int > start(n);
		for(int i=0;i<n;i++)
		{
			scanf("%d%d",&pa[i].first,&pa[i].second);
			scanf("%d",&start[i]);
			if(start[i]<pa[i].first)
				curr[i]=true;
		}
		int result=-1;
		int i=0;
		int pc=0;
		int prepre=0;
		int pre=0;
		while(i<(365*24*60))
		{
			bool sleep=true;
//			cout<<i<<" ";
			int val=0;
			for(int j=0;j<n;j++)
			{
//				cout<<curr[j]<<" ";
				if(curr[j]==true)
					sleep=false;
				val<<=1;
				val|=curr[j]?1:0;
				int val=(start[j]+i+1)%(pa[j].first+pa[j].second);
				if(val<pa[j].first)
					curr[j]=true;
				else
					curr[j]=false;
			}
			if(sleep)
			{
				result=i;
				break;
			}
			i++;
		}
		if(result==-1)
			printf("Foxen are too powerful");
		else
			printf("%d",result);
		if(t!=0)
			printf("\n");
	}
	return 0;
}
