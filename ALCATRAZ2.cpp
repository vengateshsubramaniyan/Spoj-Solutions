#include<bits/stdc++.h>
using namespace std;
bool nonconflict(vector< int > &a,vector< vector<bool> > &con)
{
	for(int i=0;i<a.size();i++)
	{
		for(int j=i+1;j<a.size();j++)
			if(con[a[i]][a[j]])
				return false;
	}
	return true;
}
int main()
{
	vector< int > price(8);
	for(int i=0;i<8;i++)
		scanf("%d",&price[i]);
	vector< vector<bool> > con(8,vector<bool>(8,false));
	int q;
	scanf("%d",&q);
	while(q--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		a--,b--;
		con[a][b]=true;
		con[b][a]=true;
	}
	int result=0;
	for(int i=0;i<256;i++)
	{
		vector< int > sam;
		int temp=0;
		for(int j=0;j<8;j++)
		{
			if(i & (1<<j))
			{
				sam.push_back(j);
				temp+=price[j];
			}
		}
		if(temp>result && nonconflict(sam,con))
			result=temp;
	}
	printf("%d\n",result);
	return 0;
}
