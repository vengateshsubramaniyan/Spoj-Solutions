#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int k,m;
		scanf("%d%d",&k,&m);
		vector< int > weight(m);
		vector< int > value(m);
		for(int i=0;i<m;i++)
		{
			scanf("%d%d",&weight[i],&value[i]);
		} 
		vector< vector<int> > k1(m+1,vector<int>(k+1,0));
		for(int i=0;i<=m;i++)
		{
			for(int j=0;j<=k;j++)
			{
				if(i==0 || j==0)
					k1[i][j]=0;
				else if(weight[i-1]<=j)
					k1[i][j]=max(value[i-1]+k1[i-1][j-weight[i-1]],k1[i-1][j]);
				else
					k1[i][j]=k1[i-1][j];
			}
		}
		printf("Hey stupid robber, you can get %d.\n",k1[m][k]);
		weight.clear();
		value.clear();
		k1.clear();
	}
	return 0;
}
