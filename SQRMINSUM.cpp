#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int l,k;
		scanf("%d%d",&l,&k);
		vector< int > a(l+1,1);
		int ma=l;	
		while(k--)
		{
			int val=(int)(floor(sqrt(ma)));
			a[val]++;
			a[ma]--;
			while(a[ma]==0)
				ma=ma-1;
		}
		int res=0;
		for(int i=1;i<=ma;i++)
			res+=(a[i]*i);
		printf("%d\n",res);
	}
	return 0;
}
