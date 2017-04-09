#include<bits/stdc++.h>
using namespace std;
int main()
{
	bool arr[3012501];
	memset(arr,false,3012501);
	int val[500001];
	val[0]=0;
	arr[0]=true;
	for(int i=1;i<=500000;i++)
	{
		int t=val[i-1]-i;
		if(t>0 && arr[t]==false)
		{
			val[i]=t;
			arr[t]=true;
		}
		else
		{
			t=val[i-1]+i;
			val[i]=t;
			arr[t]=true;
		}
	}
	int k;
	scanf("%d",&k);
	while(k!=-1)
	{
		printf("%d\n",val[k]);
		scanf("%d",&k);
	}
	return 0;
}
