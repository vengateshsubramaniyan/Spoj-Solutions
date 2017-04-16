#include<bits/stdc++.h>
#define mod 1000000000
#define ll long long 
using namespace std;
vector< vector<ll> > matrix(vector< vector<ll> > &a1,vector< vector<ll> > &a2)
{
	int n=a1.size();
	vector< vector<ll> > re(n,vector<ll>(n,0));
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			for(int k=0;k<n;k++)
				re[i][j]=(re[i][j]+(a1[i][k]*a2[k][j]))%mod;
		}
	}
	return re;
}
vector< vector<ll> > multiply(vector< vector<ll> > &arr,ll k)
{
	if(k==0 || k==1)
		return arr;
	vector< vector<ll> > re;
	re=multiply(arr,k/2);
	re=matrix(re,re);
	if(k%2!=0)
		re=matrix(re,arr);
	return re;
}
int main()
{
	ll t;
	scanf("%lld",&t);
	while(t--)
	{
		int k;
		scanf("%d",&k);
		vector< ll > b(k),c(k);
		for(int i=0;i<k;i++)
			scanf("%lld",&b[i]);
		for(int i=0;i<k;i++)
			scanf("%lld",&c[i]);
		ll n;
		scanf("%lld",&n);
		if(n<=k)
			printf("%lld\n",b[n-1]);
		else
		{
			vector< vector<ll> > arr(k,vector<ll>(k));
			for(int i=0;i<k;i++)
			{
				for(int j=0;j<k;j++)
				{
					if(i!=0 && j==i-1)
						arr[i][j]=1;
					else if(j==k-1)
						arr[i][j]=c[k-i-1];
					else
						arr[i][j]=0;
				}
			}
			vector< vector<ll> > re=multiply(arr,n-k);
/*			for(int i=0;i<k;i++)
			{
				for(int j=0;j<k;j++)
					cout<<arr[i][j]<<" ";
				cout<<endl;
			}
			for(int i=0;i<k;i++)
			{
				for(int j=0;j<k;j++)
					cout<<re[i][j]<<" ";
				cout<<endl;
			}*/
			ll result=0;
			for(int i=0;i<k;i++)
			{
				result=(result+(b[i]*re[i][k-1]))%mod;
			}
			cout<<result<<endl;
		}
	}
	return 0;
}
