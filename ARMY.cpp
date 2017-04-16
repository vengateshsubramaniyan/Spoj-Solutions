#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t,ng,nm,n1=-1,n2=-1,val,val1;
	scanf("%d",&t);
	while(t--)
	{
		n1=-1,n2=-1;
		scanf("%d%d",&ng,&nm);
		for(int i=0;i<ng;i++)
		{
			scanf("%d",&val);
			if(n1<val)
				n1=val;
		}
		for(int i=0;i<nm;i++)
		{
			scanf("%d",&val);
			if(n2<val)
				n2=val;
		}
		if(n1==-1 && n2==-1)
			printf("uncertain");
	    else if(n2>n1)
			printf("MechaGodzilla");
		else
			printf("Godzilla");
		if(t!=0)
			printf("\n");
	}
	return 0;
}
