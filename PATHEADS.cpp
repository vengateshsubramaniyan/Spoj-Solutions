#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	int a[n];
	int one=0;
	int maxe=2;
	int seive[1000001];
	memset(seive,0,sizeof(seive));
	bool visit[1000001];
	memset(visit,false,sizeof(visit));
	int val[1000001];
	memset(val,0,sizeof(val));
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		maxe=max(maxe,a[i]);
		val[a[i]]++;
		visit[a[i]]=true;
	}
	for(int i=2;i<=maxe;i++)
	{
		if(visit[i])
		{
			int temp=val[i];
			for(int j=i+i;j<=maxe;j+=i)
			{
				seive[j]+=temp;
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		if(a[i]!=1)
			printf("%d\n",seive[a[i]]+val[1]+val[a[i]]-1);
		else
			printf("%d\n",val[1]-1);
	}
	return 0;
}
