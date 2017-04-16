#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long t;
	scanf("%lld",&t);
	while(t--)
//	for(long long i=1;i<=200;i++)
	{
		long long n;
		scanf("%lld",&n);
		string result="";
		long long q=n/4;
		if(n%4==0)
			q--;
		if(q!=0)
		{
			ostringstream con;
			con<<q;
			result+=con.str();
		}
		q=n%4;
		if(q==0)
			result=result+"9";
		else if(q==1)
			result+="1";
		else if(q==2)
			result+="4";
		else
			result+="6";
		if(n%2==0)
			result+="42";
		else 
			result+="92";
		cout<<result<<endl;
	}
	return 0;
}
