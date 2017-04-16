#include<bits/stdc++.h>
using namespace std;
void f(vector< vector<bool> > &time,vector< int > &veg,int s,int &n,int &total,int &wei,int &temp,int &result)
{
	if(s>=n)
		return;
	if(time[s][temp]==true)
		return;
	time[s][temp]=true;
	f(time,veg,s+1,n,total,wei,temp,result);
	temp=temp+veg[s];
	if(total-temp>=wei && result<temp)
		result=temp;
	f(time,veg,s+1,n,total,wei,temp,result);
	temp-=veg[s];
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,w;
		scanf("%d%d",&n,&w);
		vector <int > veg(n);
		int total=0;
		for(int i=0;i<n;i++)
		{
			scanf("%d",&veg[i]);
			total+=veg[i];
		}
		int extra=total-w;
		int result;
		if(extra==0)
			result=0;
		else
		{
			vector< vector<bool> > ma(extra+1,vector<bool>(n+1));
			for(int i=0;i<=n;i++)
				ma[0][i]=true;
			for(int i=1;i<=extra;i++)
				ma[i][0]=false;
			for (int i = 1; i <= extra; i++)  
			{
				for (int j = 1; j <= n; j++)  
       			{
         			ma[i][j] = ma[i][j-1];
         			if (i >= veg[j-1])
           				ma[i][j] = ma[i][j] || ma[i - veg[j-1]][j-1];
       			}        
     		}
			for(int i=extra;i>=0;i--)
			{
				if(ma[i][n])
				{
					result=i;
					break;
				}
			}		   
		}
		printf("%d\n",total-w-result);
	}
	return 0;
}
