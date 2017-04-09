#include<bits/stdc++.h>
#include<boost/multiprecision/cpp_int.hpp>
using namespace std;
namespace mp=boost::multiprecision;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		mp::cpp_int n,m;
		cin>>n>>m;
		if(m>n)
		{
			mp::cpp_int t=n;
			n=m;
			m=t;
		}
		mp::cpp_int m1=m;
		if(m%2!=0)
			m=(m/2)+1;
		else
			m=m/2;
		mp::cpp_int n1=m*n;
		if(n%2!=0)
			n=(n/2)+1;
		else
			n=n/2;
		m1=n*m1;
		if(n1>m1)
			cout<<n1<<endl;
		else
			cout<<m1<<endl;
	}	
	return 0;
}
