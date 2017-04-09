#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,k;
		scanf("%d%d",&n,&k);
		if(n%2!=0)
		{
			n=n/2;
			n+=1;
			double t=(double)n;
			printf("%.6f\n",t);
		}
		else
		{
			double t=n;
			t=t/2+(t/2+1);
			t/=2;
			printf("%.6f\n",t);
		}
	}
	return 0;
}
