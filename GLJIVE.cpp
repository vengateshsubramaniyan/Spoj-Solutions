#include<bits/stdc++.h>
using namespace std;
int main()
{
	int result;
	int total=0;
	int dif=101;
	for(int i=0;i<10;i++)
	{
		int val;
		scanf("%d",&val);
		total+=val;
		if(dif>=(abs(100-total)))
		{
			dif=abs(100-total);
			result=total;
		}
	}
	printf("%d",result);
	return 0;
}
