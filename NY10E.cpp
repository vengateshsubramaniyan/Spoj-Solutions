#include<bits/stdc++.h>
#include<boost/multiprecision/cpp_int.hpp>
#define bigint mp::cpp_int
using namespace std;
namespace mp= boost::multiprecision;
int main()
{
	int p;
	scanf("%d",&p);
	while(p--)
	{
		int t,d;
		scanf("%d%d",&t,&d);
		vector< bigint > dp(10,1);
		for(int i=1;i<d;i++)
		{
			bigint val=0;
			for(int j=0;j<10;j++)
			{
				val+=dp[j];
				dp[j]=val;
			}
		}
		bigint result=0;
		for(int i=0;i<10;i++)	
			result+=dp[i];
		cout<<t<<" "<<result<<endl;
	}	
}
