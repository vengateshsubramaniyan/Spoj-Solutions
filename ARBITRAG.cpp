#include<bits/stdc++.h>
#define ld long double
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	int t=1;
	while(n)
	{
		char s[100001];
		map< string , int > m;
		for(int i=1;i<=n;i++)
		{
			scanf("%s",s);
			m[s]=i;	
		}
		int m1;
		vector< vector<ld> > ed(n+1,vector<ld>(n+1,-1));
		for(int i=1;i<=n;i++)
		{
			ed[i][i]=1;
		}
		scanf("%d",&m1);
		char des[100001];
		while(m1--)
		{
			ld val;
			scanf("%s %Lf %s",s,&val,des);
			ed[m[s]][m[des]]=val;
		}
		for(int k=1;k<=n;k++)
		{
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=n;j++)
				{
					if((ed[i][k]*ed[k][j])>ed[i][j])
						ed[i][j]=ed[i][k]*ed[k][j];
				}
			}
		}
		bool res=false;
		for(int i=1;i<=n;i++)
		{
//			cout<<ed[i][i]<<endl;
			if((ed[i][i]-1)>0)
			{
				res=true;
				break;
			}
		}
		res?printf("Case %d: Yes\n",t):printf("Case %d: No\n",t);
		t++;
		scanf("%d",&n);
	}
	return 0;
}
