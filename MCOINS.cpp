#include<bits/stdc++.h>
using namespace std;
int main()
{
	int k,l,n;
	scanf("%d%d%d",&k,&l,&n);
	int end=0;
	int arr[n];
	for(int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
		if(end<arr[i])
			end=arr[i];
	}
	bool result[end+1];
	memset(result,false,end+1);
	if(l<k)
	{
		int t=k;
		k=l;
		l=t;
	}
	for(int i=1;i<=end;i++)
	{
		if(result[i-1]==false)
			result[i]=true;
		else if(i>=l && result[i-l]==false)
		{
			result[i]=true;
		}
		else if(i>=k && result[i-k]==false)
			result[i]=true;	
	}
	for(int i=0;i<n;i++)
	{
		if(result[arr[i]])
			printf("A");
		else
			printf("B");
	}
	return 0;
}
