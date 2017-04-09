#include<bits/stdc++.h>
#define ll long long unsigned int
#define mx 18446744073709551615
using namespace std;
bool result(vector< vector<ll> > &arr,int n,int size)
{
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(arr[j][i]!=mx)
				return false;
		}
	}
	int r=n%32;
	ll re=0;
	for(int i=0;i<r;i++)
		re=re|(1<<i);
	for(int i=0;i<n;i++)
	{
		if(arr[i][size]!=re)
			return false;
	}
	return true;
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	while(n && m)
	{
		int size =n/32;
		map<string, int> mp;
		char name[100001];
		vector< vector<ll> >arr(n,vector<ll>(size+1));
		for(int i=0;i<n;i++)
		{
			scanf("%s",name);
			mp[name]=i;
//			cout<<name<<" "<<i<<endl;
			int j=i/32;
			arr[i][j]=(1<<(i-(j*32)));
		}
		while(m--)
		{
			char cad1[100001],cad2[100001];
			scanf("%s%s",cad1,cad2);
			int i=mp[cad1];
			int j=mp[cad2];
//			cout<<cad1<<" "<<i<<endl;
//			cout<<cad2<<" "<<j<<endl;
			for(int k=0;k<=size;k++)
			{
				ll temp=arr[i][k]|arr[j][k];
				arr[i][k]=temp;
				arr[j][k]=temp;
			}
//			cout<<arr[i][0]<<" "<<arr[j][0]<<endl;
		}
		if(result(arr,n,size))
			printf("YES\n");
		else
			printf("NO\n");
		scanf("%d%d",&n,&m);
	}
	return 0;
}
