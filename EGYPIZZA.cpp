#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	int q1=0,h=0,q3=0,result=1,q;
	for(int i=0;i<n;i++)
	{
		int a,c;
		char b;
		scanf("%d%c%d",&a,&b,&c);
		if(a==1)
		{
			if(c==2)
				h++;
			else	
				q1++;
		}
		else 
			q3++;
	}
	q=h/2;
	result+=q;
	h-=(q*2);
	q=min(q1,q3);
	result+=q;
	q1=q1>q?q1-q:0;
	q3=q3>q?q3-q:0;
	q=min(q1/2,h);
	result+=q;
	q1=q1>(q*2)?(q1-(q*2)):0;
	h=h>q?h-q:0;
	result+=q3;
	if(q1 && h)
	{
		result+=1;
		q1=0 ;
		h=0;
	}
	result+=h;
	result+=(q1/4);
	if(q1%4!=0)
		result++;
	printf("%d",result);
	return 0;
}
