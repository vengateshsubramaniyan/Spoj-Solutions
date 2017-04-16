#include<bits/stdc++.h>
#define ll unsigned long long 
using namespace std;
int main()
{
	ll n1;
	cin>>n1;
	if(n1==1 || n1==0)
	{
		printf("TAK");
		return 0;
	}
	if(n1&&!(n1&(n1-1)))
		printf("TAK");
	else
		printf("NIE");
	return 0;
}
