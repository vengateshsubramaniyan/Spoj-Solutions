#include<bits/stdc++.h>
using namespace std;
void seive(int l,int h,int u,vector<int> &prime)
{
	bool visit[u+10];
	memset(visit,false,sizeof(visit));
	for(int i=2;i*i<=u;i++)
	{
		for(int j=2*i;j<=u;j+=i)
			visit[j]=true;
	}
	for(int i=2;i<=u;i++)
	{
		if(visit[i]==false)
		{
			prime.push_back(i);
			if(i>=l && i<=h)
				printf("%d\n",i);
		}
	}
}
void segment(int l,int u)
{
	int limit=floor(sqrt(u))+1;
	vector< int > prime;
	seive(l,u,limit,prime);
	int low=limit;
	int high=2*limit;
	while(low+limit<=l)
	{
		low+=limit;
		high=high+limit;
	}
	while(low<u)
	{
		bool visit[limit+10];
		memset(visit,false,sizeof(visit));
		for(int i=0;i<prime.size();i++)
		{
			int llim=floor(low/prime[i])*prime[i];
			if(llim<low)
				llim+=prime[i];
			for(int j=llim;j<=high;j+=prime[i])
				visit[j-low]=true;
		}
		for(int i=low;i<=high;i++)
		{
			if(visit[i-low]==false && (i>=l && i<=u))
				printf("%d\n",i);
		}
		low=low+limit;
		high=high+limit;
		if(high>u)
			high=u;
	}
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int l,u;
		scanf("%d%d",&l,&u);
		segment(l,u);
		printf("\n");
	}
	return 0;
}
