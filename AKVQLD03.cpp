#include<bits/stdc++.h>
using namespace std;
void add(vector<long long> &arr,long long start,long long end,long long pos,long long f,long long index)
{
	if(start>pos || end<pos)
		return;
	long long mid=start+(end-start)/2;
	arr[index]+=f;
	if(start!=end)
	{
		add(arr,start,mid,pos,f,index*2+1);
		add(arr,mid+1,end,pos,f,index*2+2);
	}
}
long long find(vector<long long > &arr,long long start,long long end,long long a,long long b,long long index)
{
	if(a<=start && b>=end)
		return arr[index];
	if(end<a || start>b)
		return 0;
	long long mid=start+(end-start)/2;
	return find(arr,start,mid,a,b,index*2+1)+find(arr,mid+1,end,a,b,index*2+2);
}
int main()
{
	long long n,q,n1;
	cin>>n>>q;
	n1=(int)(ceil(log2(n)));
	n1=2*(int)pow(2,n1)-1;
	vector<long long > arr(n1,0);
	for(int t=1;t<=q;t++)
	{
		string op;
		cin>>op;
		if(op=="find")
		{
			long long a,b;
			cin>>a>>b;
			a--;
			b--;
			cout<<find(arr,0,n-1,a,b,0)<<endl;
		}
		else 
		{
			long long p,f;
			cin>>p>>f;
			p--;
			add(arr,0,n-1,p,f,0);
		}
	}
	return 0;
}
