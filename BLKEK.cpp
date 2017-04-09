#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define pi pair<int,int>
#define pll pair<ll,ll>
#define vl vector< ll >
#define bug(a) cout<<a<<endl;
#define bug2(a,b) cout<<a<<" "<<b<<endl;
#define bug3(a,b,c) cout<<a<<" "<<b<<" "<<c<<endl;
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		char s[3000];
		scanf("%s",s);
		int res=0;
		int k=0;
		int e=0;
		int len=strlen(s);
		for(int i=len-1;i>=0;i--)
		{
			if(s[i]=='E')
			{
				e+=k;
			}
			else if(s[i]=='K')
			{
				res+=e;
				k++;
			}
		}
		printf("%d\n",res);
	}
	return 0;
}


