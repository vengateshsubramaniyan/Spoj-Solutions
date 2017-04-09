#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	vector< int > a(n+2,0);
	while(k--)
	{
		int s,d;
		scanf("%d%d",&s,&d);
		a[s]+=1;
		a[d+1]+=-1;
	}
	vector< int > res(25001,0);
	int val=a[1];
	res[val]++;
	for(int i=2;i<=n;i++)
	{
		val+=a[i];
		res[val]++;
	}
	int k1=n/2;
	k1++;
	for(int i=0;i<=25000;i++)
	{
		if(res[i]>=k1)
		{
			printf("%d",i);
			break;
		}
		else
			k1-=res[i];
	}
	return 0;
}
