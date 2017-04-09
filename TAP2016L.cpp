#include<bits/stdc++.h>
using namespace std;
bool lefti(int s[],int i)
{
	if(i<=0)
		return true;
	while(i>0)
	{
		if(s[i]!=2 && s[i]!=1 && s[i]-1==s[i-1] || s[i]-2==s[i-1])
			i--;
		else
			return false;
	}
	return true;
}
bool right(int s[],int i,int n)
{
	if(i>=n-1)
		return true;
	while(i<n-1)
	{
		if(s[i]!=2 && s[i]!=1 && s[i]-1==s[i+1] || s[i]-2==s[i+1])
			i++;
		else
			return false;
	}
	return true;
}
int main()
{
	int n;
	while(cin>>n)
	{
		int k;
		scanf("%d",&k);
		int s[k];
		int m=0;
		for(int i=0;i<k;i++)
		{
			scanf("%d",&s[i]);
			if(s[m]<s[i])
				m=i;
		}
		bool re=true,left=true;
		bool enter=false;
		if(m-1!=-1)
		{
			enter=true;
			if(s[m]!=2 && s[m]!=1 && s[m]-1==s[m-1])
			{
				if(!lefti(s,m-1))
					re=false;
			}
			else if(s[m]!=2 && s[m]!=1 && s[m]-2==s[m-1])
			{
				left=false;
				if(!lefti(s,m-1))
					re=false;
			}
			else
				re=false;
		}
		if(re && m+1<k)
		{
			if(left && enter)
			{
				if(s[m]!=2 && s[m]!=1 && s[m]-2==s[m+1])
				{
					if(!right(s,m+1,k))
						re=false;
				}
				else
					re=false;
			}
			else if(!left && enter)
			{
				if(s[m]!=2 && s[m]!=1 && s[m]-1==s[m+1])
				{
					if(!right(s,m+1,k))
						re=false;
				}
				else		
					re=false;
			}
			else if(!enter)
			{
				if(s[m]!=2 && s[m]!=1 && (s[m]-1==s[m+1]|| s[m]-2==s[m+1]))
				{
					if(!right(s,m+1,k))
						re=false;
				}
				else
					re=false;
			}
		}
		re?printf("S\n"):printf("N\n");
	}
	return 0;
}
