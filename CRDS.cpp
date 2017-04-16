#include <boost/multiprecision/cpp_int.hpp>
#include<bits/stdc++.h>
namespace mp=boost::multiprecision;
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long long n;
		scanf("%lld",&n);
		mp::cpp_int u=(n*(4+((n-1)*2)))/2;
		n--;
		mp::cpp_int u1=(n*(n+1))/2;
		u=(u+u1)%1000007;
		cout<<u<<endl;
	}
	return 0;
}
