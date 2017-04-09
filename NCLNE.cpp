#include<bits/stdc++.h>
#define ll long long
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
		int aval=1;
		bool result=true;
		for(int i=0;i<n-1;i++)
		{
			if(aval<a[i])
			{
				result=false;
				break;
			}
			aval-=a[i];
			aval*=2;
		}
		if(result)
		{
			if(aval!=a[n-1])
				result=false;
		}
		result?printf("Yes\n"):printf("No\n");
	}
	return 0;
}
