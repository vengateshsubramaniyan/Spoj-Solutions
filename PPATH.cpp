#include<bits/stdc++.h>
using namespace std;
int main()
{
	bool prime[10000];
	memset(prime,false,10000);
	for(int i=2;i<10000;i++)
	{
		if(prime[i]==false)
		{
			for(int j=i+i;j<10000;j=j+i)
			{
				prime[j]=true;
			}
		}
	}
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int start,end,d1,d2,d3,d4;
		scanf("%d %d",&start,&end);
		queue< pair<int,int> > q;
		q.push(pair<int,int>(start,0));
		int result=-1;
		bool check[10000];
		check[start]=true;
		memset(check,false,10000);
		while(!q.empty())
		{
			int val=q.front().first;
			int cost=q.front().second;
			if(end==val)
			{
				result=cost;
				break;
			}
			q.pop();
			d1=val%10;val/=10;d2=val%10;val/=10;d3=val%10;d4=val/10;
			for(int i=0;i<10 && result==-1;i++)
			{
				val=(d4*1000)+(d3*100)+(d2*10)+i;
				if(prime[val]==false && !check[val])
				{
					q.push(pair<int,int>(val,cost+1));
					check[val]=true;
				}
				if(val==end)
					result=cost+1;
			}
			if(result!=-1)
				break;
			for(int i=0;i<10 && result==-1;i++)
			{
				val=(d4*1000)+(d3*100)+(i*10)+d1;
				if(prime[val]==false && !check[val])
				{
					q.push(pair<int,int>(val,cost+1));
					check[val]=true;
				}
				if(val==end)
					result=cost+1;
			}
			if(result!=-1)
				break;
			for(int i=0;i<10 && result==-1;i++)
			{
				val=(d4*1000)+(i*100)+(d2*10)+d1;
				if(prime[val]==false && !check[val])
				{
					q.push(pair<int,int>(val,cost+1));
					check[val]=true;
				}
				if(val==end)
					result=cost+1;
			}
			if(result!=-1)
				break;
			for(int i=1;i<10 && result==-1;i++)
			{
				val=(i*1000)+(d3*100)+(d2*10)+d1;
				if(prime[val]==false && !check[val])
				{
					q.push(pair<int,int>(val,cost+1));
					check[val]=true;
				}
					if(val==end)
						result=cost+1;
			}
			if(result!=-1)
				break;
		}
		if(result==-1)
			printf("Impossible");
		else
			printf("%d",result);
		if(t!=0)
			printf("\n");
	}
	return 0;
}
