#include<bits/stdc++.h>
#include<boost/multiprecision/cpp_int.hpp>
using namespace std;
namespace mp=boost::multiprecision;
void gcd(mp::cpp_int &a,mp::cpp_int &b)
{
	mp::cpp_int t;
	while(b)
	{
		t=a%b;
		a=b;
		b=t;
	}
}
int main()
{
	int t;
	scanf("%d",&t);
	mp::cpp_int n,a,b;
	while(t--)
	{
		cin>>n>>a>>b;
		if(a==b)
		{
			while(a--)
			{
				cout<<n;
			}
		}
		else
		{
			gcd(a,b);
			while(a--)
			{
				cout<<n;
			}
		}
		cout<<endl;
	}
}
