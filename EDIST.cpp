#include<bits/stdc++.h>
#define ll long long
#define vll vector<vector<ll> > 
using namespace std;
int main()
{
	ll t;
	scanf("%lld",&t);
	while(t--)
	{
		string s1,s2;
		cin>>s1>>s2;
		int l1=s1.length();
		int l2=s2.length();
		vll arr(l1+1,vector<ll>(l2+1));
		for(int i=0;i<=l1;i++)
		{
			for(int j=0;j<=l2;j++)
			{
				if(i==0)
				{
					arr[i][j]=j;
				}
				else if(j==0)
					arr[i][j]=i;
				else if(s1[i-1]==s2[j-1])
					arr[i][j]=arr[i-1][j-1];
				else
					arr[i][j]=1+min(arr[i-1][j-1],min(arr[i-1][j],arr[i][j-1]));
			}
		}
		printf("%lld\n",arr[l1][l2]);
	}
	return 0;
}
