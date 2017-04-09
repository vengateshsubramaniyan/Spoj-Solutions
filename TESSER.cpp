#include<bits/stdc++.h>
#define ll long long
using namespace std;
void kmp(char s[],ll n,ll lps[])
{
	lps[0]=0;
	ll len=0;
	ll i=1;
	while(i<n)
	{
		if(s[len]==s[i])
		{
			len++;
			lps[i]=len;
			i++;
		}
		else 
		{
			if(len!=0)
				len=lps[len-1];
			else
			{
				lps[i]=0;
				i++;
			}
		}
	}
}
int main()
{
	ll t;
	scanf("%lld",&t);
	while(t--)
	{
		ll n;
		scanf("%lld",&n);
		ll a[n];
		for(ll i=0;i<n;i++)
			scanf("%lld",&a[i]);
		char s[1000001];
		scanf("%s",s);
		ll len=strlen(s);
		ll lps[len];
		memset(lps,0,sizeof(lps));
		kmp(s,len,lps);
		bool result=false;
		ll i=1;
		ll j=0;
		while(i<n && j<len)
		{
			if(s[j]=='G')
			{
				if(a[i]>a[i-1])
				{
					i++;
					j++;
				}
				else
				{
					if(j!=0)
						j=lps[j-1];
					else
						i++;
				}
			}
			else if(s[j]=='L')
			{
				if(a[i]<a[i-1])
				{
					i++;
					j++;
				}
				else
				{
					if(j!=0)
						j=lps[j-1];
					else
						i++;
				}
			}
			else
			{
				if(a[i]==a[i-1])
				{
					i++;
					j++;
				}
				else
				{
					if(j!=0)
						j=lps[j-1];
					else
						i++;
				}
			}
			if(j==len)
			{
				result=true;
				break;
			}
		}
		result?printf("YES\n"):printf("NO\n");
	}
	return 0;
}
