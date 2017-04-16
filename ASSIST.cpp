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
	bool seive[100001];
	memset(seive,false,sizeof(seive));
	int nc=0;
	vector<int> result;
	for(int i=2;i<=35000;i++)
	{
		int k=0;
		if(seive[i]==false)
		{
			result.push_back(i);
			nc++;
			for(int j=i+1;j<=35000;j++)
			{
				if(seive[j]==false)
					k++;
				if(k==i)
				{
					seive[j]=true;
					k=0;
				}
			}
		}
	}
	int n;
	scanf("%d",&n);
	while(n)
	{
		printf("%d\n",result[n-1]);
		scanf("%d",&n);
	}
	return 0;
}


