#include<bits/stdc++.h>
using namespace std;
bool pos(int a[],int l,int n,int val)
{
	int temp=0;
	int tl=1;
	if(a[0]>val)
		return false;
	temp=a[0];
	for(int i=1;i<n;i++)
	{
		if(a[i]>val)
			return false;
		if(temp+1+a[i]>val)
		{
			tl++;
			temp=a[i];
		}
		else
			temp+=a[i]+1;
	}
	return (tl<=l);
}
void binary(int a[],int l,int n,int high)
{
	int low=1;
	int res=high;
	while(low<high)
	{
		int mid=low+(high-low)/2;
		if(pos(a,l,n,mid))
		{
			res=mid;
			high=mid;
		}
		else
			low=mid+1;
	}
	printf("%d\n",res);
}
int main()
{
	int l,n;
	scanf("%d%d",&l,&n);
	int alen[100001];
	while(l!=-1 && n!=-1)
	{
		char s[100001];
		int tlen=0;
		for(int i=0;i<n;i++)
		{
			scanf("%s",s);
			alen[i]=strlen(s);
			tlen+=alen[i];
		}
		tlen+=(n-1);
		binary(alen,l,n,tlen);
		scanf("%d%d",&l,&n);
	}
}
