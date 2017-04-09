#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		vector< int > a(n);
		for(int i=0;i<n;i++)
			scanf("%d",&a[i]);
		int m;
		scanf("%d",&m);
		vector< int > b(m);
		for(int i=0;i<m;i++)
			scanf("%d",&b[i]);
		sort(a.begin(),a.end());
		sort(b.begin(),b.end());
		int i=0,j=0,res=INT_MAX;
		while(i<n && j<m && res!=0)
		{
			if(res>abs(a[i]-b[j]))
			{
				res=abs(a[i]-b[j]);
			}
			if(i+1<n && j+1<m)
			{
				if(abs(a[i+1]-b[j])<abs(a[i]-b[j+1]))		
					i++;
				else
					j++;
			}
			else
			{
				if(i+1<n)
					i++;
				else
					j++;
			}
		}
		printf("%d\n",res);
	}
	return 0;
}
