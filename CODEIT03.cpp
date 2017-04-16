#include<bits/stdc++.h>
using namespace std;
int findday()
{
	int d,m,y;
	scanf("%d%d%d",&d,&m,&y);
	static int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };
	y-=m<3;
	return(y+y/4-y/100+y/400+t[m-1]+d)%7;
}
int main()
{
	int t;
	char day[7][20]={"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday", "Saturday"};
	scanf("%d",&t);
	while(t--)
	{
		int d=findday();
		printf("%s\n",day[d]);
	}
	return 0;
}
