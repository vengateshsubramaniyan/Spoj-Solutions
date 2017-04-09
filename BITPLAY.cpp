#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int k;
		unsigned long n;
		cin>>n>>k;
		if(k==0)
		{
			printf("-1\n");
		}
		else
		{
			n=n-1;
			bitset<32>b(n);
			int c=b.count();
			if(c<=k)
			{
				printf("%d\n",n);
			}
			else
			{
				string s=b.to_string();
//				cout<<s;
				int i=30;
				while(c>k && i>=0)
				{
					if(s[i]=='1')
					{
						s[i]='0';
						c--;
					}
					i--;
				}
				bitset<32> a(s);
				cout<<a.to_ulong()<<endl;
			}
		}
	}
	return 0;
}
