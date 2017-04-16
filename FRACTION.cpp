#include<bits/stdc++.h>
using namespace std;
struct fra
{
	double a;
	double b;
};
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,m;
		vector<struct fra> arr;
		scanf("%d%d",&n,&m);	
		double x1=0,x2=1,y1=1,y2=n,x=0,y=0;
		fra c;
		c.a=x1,c.b=y1;
		arr.push_back(c);
		c.a=x2,c.b=y2;
		arr.push_back(c);
		while(y!=1.0)
		{
			x=(floor((y1+n)/y2))*x2-x1;
			y=(floor((y1+n)/y2))*y2-y1;
			struct fra f;
			f.a=x;
			f.b=y;
			arr.push_back(f);
			x1=x2,x2=x,y1=y2,y2=y;
		}
		while(m--)
		{
			int pos;
			scanf("%d",&pos);
			printf("%.0f/%.0f\n",arr[pos-1].a,arr[pos-1].b);
		}
	}
	return 0;
}
