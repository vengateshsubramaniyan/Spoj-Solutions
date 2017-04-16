#include<bits/stdc++.h>
#define ll long long 
using namespace std;
void find(char a[],ll lis[],ll n)
{
	lis[0]=0;
	ll len=0;
	ll i=1;
	while(i<n)
	{
		if(a[len]==a[i])
		{
			len++;
			lis[i]=len;
			i++;
		}
		else
		{
			if(len!=0)
			{
				len=lis[len-1];
			}
			else
			{
				lis[i]=0;
				i++;
			}
		}
	}
}
int main()
{
	ll n;
	while(scanf("%lld",&n)!=EOF)
	{
		char a[n];
		scanf("\n%[^\n]s",a);
		char s[1000001];
		scanf("\n%[^\n]s",s);
		ll lis[n];
		ll n1=strlen(s);
		find(a,lis,n);
		ll i=0,j=0;
		bool f=true;
		while(i<n1)
		{
			if(s[i]==a[j])
			{
				i++;
				j++;
			}
			if(j==n)
			{
				f=false;
				printf("%lld\n",i-j);
				j=lis[j-1];
			}
			else if(i<n1 && a[j]!=s[i])
			{
				if(j!=0)
				{
					j=lis[j-1];
				}
				else
				{
					i++;
				}
			}
		}
		if(f)
			printf("\n");
	}
	return 0;
}
