#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define pi pair<int,int>
#define pll pair<ll,ll>
#define vl vector< ll >
#define bug(a) cout<<a<<endl;
#define bug2(a,b) cout<<a<<" "<<b<<endl;
#define bug3(a,b,c) cout<<a<<" "<<b<<" "<<c<<endl;
int row[]={1,-1,0,0};
int col[]={0,0,1,-1};
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	char a[200][200];
	int re[200][200];
	while(t--)
	{
		int r,c;
		scanf("%d%d",&r,&c);
		for(int i=0;i<r;i++)
			scanf("%s",a[i]);
		queue< pair< int, pi> > q;
		for(int i=0;i<r;i++)
		{
			for(int j=0;j<c;j++)
			{
				if(a[i][j]=='1')
				{
					re[i][j]=0;
					q.push(pair< int ,pi>(0,pi(i,j)));
				}
			}
		}
		while(!q.empty())
		{
			int di=q.front().first;
			int i=q.front().second.first;
			int j=q.front().second.second;
			q.pop();
			for(int k=0;k<4;k++)
			{
				int ci=i+row[k];
				int cj=j+col[k];
				if(ci>=0 && ci<r && cj>=0 && cj<c && a[ci][cj]=='0')
				{
					a[ci][cj]='1';
					re[ci][cj]=di+1;
					q.push(pair<int,pi>(di+1,pi(ci,cj)));
				}
			}
		}
		for(int i=0;i<r;i++)
		{
			for(int j=0;j<c;j++)
				printf("%d ",re[i][j]);
			cout<<endl;
		}
	}
	return 0;
}


