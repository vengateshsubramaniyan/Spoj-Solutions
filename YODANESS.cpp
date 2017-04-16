#include<bits/stdc++.h>
#define ll long long
using namespace std;
void mergesort(int arr[],int temp[],int s,int m,int e,ll &result)
{
	int i=s;
	int j=m+1;
	int count=0;
	int k=s;
	while(i<=m && j<=e)
	{
		if(temp[i]<temp[j])
		{
			arr[k]=temp[i];
			k++;
			i++;
			result+=count;
		}
		else
		{
			arr[k]=temp[j];
			k++;
			j++;
			count++;
		}
	}
	while(i<=m)
	{
		arr[k++]=temp[i++];
		result+=count;
	}
	while(j<=e)
		arr[k++]=temp[j++];
	for(i=s;i<=e;i++)
		temp[i]=arr[i];
}
void merge(int arr[],int temp[],int s,int e,ll &result)
{
	if(s>=e)
		return;
	int m=s+(e-s)/2;
	merge(arr,temp,s,m,result);
	merge(arr,temp,m+1,e,result);
	mergesort(arr,temp,s,m,e,result);
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		map<string,int> m;
		int n;
		scanf("%d\n",&n);
		for(int i=1;i<=n;i++)
		{
			char arr[25];
			scanf("%s",arr);
			m.insert(pair<string,int>(arr,i));
		}
		int a[n];
		int temp[n];
		for(int i=0;i<n;i++)
		{
			char a1[20];
			scanf("%s",a1);
			map<string,int>::iterator it;
			it=m.find(a1);
			a[i]=it->second;
			temp[i]=a[i];
		}
		ll result=0;
		merge(a,temp,0,n-1,result);
		printf("%lld\n",result);
	}
	return 0;
}
