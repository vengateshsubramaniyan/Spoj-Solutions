#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	map<int,int> m;
	m[222]=0;
	m[221]=1;
	m[212]=2;
	m[211]=3;
	m[122]=4;
	m[121]=5;
	m[112]=6;
	m[111]=7;
	scanf("%d",&t);
	while(t--)
	{
		int tt;
		vector< int > result(9,0);
		scanf("%d",&tt);
		char arr[40];
		scanf("%s",arr);
		int val=0;
		for(int i=0;i<=2;i++)
		{
			val=(val*10)+(arr[i]=='H'?1:2);
		}
		result[m[val]]++;
		for(int i=3;i<40;i++)
		{
			val=val%100;
			val=(val*10)+(arr[i]=='H'?1:2); 	
			result[m[val]]++;
		}
		printf("%d ",tt);
		for(int i=0;i<8;i++)
			printf("%d ",result[i]);
		printf("\n");
		result.clear();
	}
	return 0;
}
