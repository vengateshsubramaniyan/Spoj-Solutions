#include<bits/stdc++.h>
using namespace std;
struct pi
{
	int i,j,re;
};
struct cmpp
{
	bool operator()(const pi &a,const pi &b)
	{
		return a.re>=b.re;
	}
};
int row[]={0,0,1,-1};
int col[]={1,-1,0,0};
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int r,c;
		scanf("%d%d",&r,&c);
		int arr[r][c];
		for(int i=0;i<r;i++)
			for(int j=0;j<c;j++)
				scanf("%d",&arr[i][j]);
		int a,b,time;
		scanf("%d%d%d",&a,&b,&time);
		a--;
		b--;
		int result;
		if(a==0 && b==0)
		{
			result=arr[0][0];
		}
		else
		{
			pi pp,p1;
			pp.i=0;
			pp.j=0;
			pp.re=arr[0][0];		
			arr[0][0]=10;
			priority_queue< struct pi,vector < struct pi> ,cmpp > pq;
			pq.push(pp);	
			while(!pq.empty())
			{
				pp=pq.top();
				pq.pop();
				bool fo=false;
				for(int i=0;i<4;i++)
				{
					p1.i=pp.i+row[i];
					p1.j=pp.j+col[i];
					if(p1.i>=0 && p1.i<r && p1.j>=0 && p1.j<c && arr[p1.i][p1.j]!=10)
					{
						p1.re=pp.re+arr[p1.i][p1.j];
						if(p1.i==a && p1.j==b)
						{
							fo=true;
							result=p1.re;
							break;
						}
						arr[p1.i][p1.j]=10;
						pq.push(p1);
					}
				}
				if(fo)
					break;
			}
		}
		if(result<=time)
			printf("YES\n%d\n",time-result);
		else
			printf("NO\n");
	}
	return 0;
}
