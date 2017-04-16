#include<bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>
#define bigint mp::cpp_int
using namespace std;
namespace mp =boost::multiprecision;
int main()
{
	long long n;
	bigint z=1,o=1;
	scanf("%lld",&n);
	n--;
	while(n)
	{
		bigint t=o;
		o+=z;
		z=t;
		n--;
	}
	bigint re=o+z;
	cout<<re<<endl;
	return 0;
}
