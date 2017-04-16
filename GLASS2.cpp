#include<bits/stdc++.h>
using namespace std;
bool findres(vector< vector<int> > &res,int sum,vector< bool > &add,int pos,int n)
{
	if(sum==0)
		return true;
	if(sum<0)
		return false;
	int i=floor((int)(sqrt(sum)));
	i=min(i,n);
	for(;i>0;i--)
	{
		int temp=sum;
		if(!add[i])
		{
			add[i]=true;
			temp-=(i*i);
			res[pos].push_back(i);
			if(findres(res,temp,add,pos,n))
			{
//				cout<<i<<" ";
				return true;
			}
			res[pos].pop_back();
			add[i]=false;
		}
	}
	return false;
}
int main()
{
	int n;
	scanf("%d",&n);
	int sum=1;
	for(int i=2;i<=n;i++)
		sum+=(i*i);
//	cout<<sum<<endl;
//	cout<<sum<<endl;
	vector< bool > add(n+1,false);
	vector< vector<int> > res(4);
	int pos=0;
	if(sum%4==0)
	{
		sum/=4;
		for(int i=n;i>0;i--)
		{
			if(!add[i])
			{
				int temp=sum;
				temp-=(i*i);
				add[i]=true;
				res[pos].push_back(i);
				if(findres(res,temp,add,pos,n))
				{
					pos++;
//					cout<<endl;
				}
				else
				{
					add[i]=false;
					res[pos].pop_back();
				}
			}
		}
		for(int i=3;i>0;i--)
			printf("%d ",res[i].size());
		printf("%d\n",res[0].size());
		for(int i=3;i>=0;i--)
		{
			for(int j=res[i].size()-1;j>0;j--)
				printf("%d ",res[i][j]);
			printf("%d\n",res[i][0]);
		}
	}
	return 0;
}
