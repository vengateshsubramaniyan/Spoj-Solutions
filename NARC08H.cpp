#include<bits/stdc++.h>
using namespace std;
int josephus(int n,int d)
{
	if(n==1)
		return 1;
	return (josephus(n-1,d)+d-1)%n+1;
}
int main()
{
	int n,d;
	scanf("%d%d",&n,&d);
	while(n && d)
	{
		printf("%d %d %d\n",n,d,josephus(n,d));
		scanf("%d%d",&n,&d);
	}
	return 0;
}
