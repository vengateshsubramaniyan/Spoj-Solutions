#include<bits/stdc++.h>
using namespace std;
struct pa
{
	int vol;
	int imp;
};
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int w,n;
		scanf("%d%d",&w,&n);
		pa a[n+1];
		vector< vector<int> > attach(n+1);
		vector< bool > con(n+1,false);
		for(int i=1;i<=n;i++)
		{
			int in;
			scanf("%d%d%d",&a[i].vol,&a[i].imp,&in);
//			cout<<a[i].vol<<" "<<a[i].imp<<endl;
			if(in==0)
				con[i]=true;
			else if(in<i)
			{
				attach[in].push_back(i);
			}
		}
		int dp[n+1][w+1];
		for(int i=0;i<=n;i++)
		{
			vector< vector<int> >dpat(n+1,vector<int>(w+1,0));
			for(int j=0;j<=w;j++)
			{
				if(i==0)
					dp[i][j]=0;
				else if(j==0)
				{
					dp[i][j]=0;
				}
				else if(!con[i])
				{
					dp[i][j]=dp[i-1][j];
				}
				else if(a[i].vol<=j)
				{
					int t=a[i].vol*a[i].imp;
					int t1=t+dp[i-1][j-a[i].vol];
					dp[i][j]=max(t1,dp[i-1][j]);
					int r=j-a[i].vol;
					if(r>0)
					{
						for(int k=0;k<pow(2,attach[i].size());k++)
						{
							int tk=k,ki=0;
							int tv=0,tr=0;
							while(tk)
							{
								if(tk&1)
								{
									tr+=a[attach[i][ki]].vol*a[attach[i][ki]].imp;
									tv+=a[attach[i][ki]].vol;
								}
								tk>>=1;
								ki++;
							}
							if(tv<=r)
							{
								int ddp=t+tr+dp[i-1][r-tv];
								dp[i][j]=max(dp[i][j],ddp);
							}
						}
					}
				}
				else
					dp[i][j]=dp[i-1][j];
			}
		}
		printf("%d\n",dp[n][w]);
	}
	return 0;
}
