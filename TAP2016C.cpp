#include<bits/stdc++.h>
#define ll long long unsigned int
#define vl vector<ll>
#define vll vector< vl >
#define scan(var) scanf("%lld",&var);
using namespace std;
void findres(ll p,vll &arr,vector<bool> &add,vl &count,ll &result)
{
	result++;
	for(ll i=0;i<arr[p].size();i++)
	{
		ll pp=arr[p][i];
		count[pp]--;
		if(count[pp]==0 && add[pp])
			findres(pp,arr,add,count,result);
	}
}
int main()
{
	ll n=-1,m=-1;
	while(cin>>n)
	{
		scanf("%lld",&m);
		vector<bool > add(n+1,false);
		vll arr(n+1);
		vl count(n+1,0);
		while(m--)
		{
			ll a,b;
			scanf("%lld%lld",&a,&b);
			arr[a].push_back(b);
			count[b]++;
		}
		ll result=0;
		for(ll i=0;i<n;i++)
		{
			ll sub;
			scanf("%lld",&sub);
			add[sub]=true;
			if(count[sub]==0 && add[sub])
			{
				result++;
				for(ll j=0;j<arr[sub].size();j++)
				{
					ll p=arr[sub][j];
					count[p]--;
					if(count[p]==0 && add[p])
						findres(p,arr,add,count,result);
				}
			}
			printf("%lld\n",result);
		}
	}
	return 0;
}
