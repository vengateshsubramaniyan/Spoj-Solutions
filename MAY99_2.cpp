#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	char a[]={'m', 'a', 'n', 'k', 'u'};
	scanf("%d",&t);
	while(t--)
	{
		string res="";
		long long n;
		scanf("%lld",&n);
		while(n>0)
		{
			long long rem=n%5;
			if(rem==0)
			{
				res='u'+res;
				n=(n/5)-1;
			}
			else
			{
				res=a[rem-1]+res;
				n/=5;
			}
		}
		cout<<res<<endl;
	}
	return 0;
}
