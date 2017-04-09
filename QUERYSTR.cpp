#include<bits/stdc++.h>
using namespace std;
void calculate(string &s,int z[],int n)
{
	int l=0,r=0;
	for(int i=1;i<n;i++)
	{
		if(i>r)
		{
			r=i;
			l=i;
			while(r<n && s[r-l]==s[r])
				r++;
			z[i]=r-l;
			r--;
		}
		else
		{
			int k=i-l;
			if(z[k]<r-i+1)
				z[i]=z[k];
			else
			{
				l=i;
				while(r<n && s[r-l]==s[r])
					r++;
				z[i]=r-l;
				r--;
			}
		}
	}
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		string s;
		cin>>s;
		int n=s.length();
		int z[n];
		z[0]=n;
		reverse(s.begin(),s.end());
		calculate(s,z,n);
		int q;
		scanf("%d",&q);
		while(q--)
		{
			int i;
			scanf("%d",&i);
			printf("%d\n",z[n-i]);
		}
	}
	return 0;
}
