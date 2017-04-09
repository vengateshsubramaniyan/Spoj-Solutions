#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
void constructtree(vector<int> &zero,int s,int e,int i)
{
	if(s==e)
	{
		zero[i]=1;
		return;
	}
	int m=s+(e-s)/2;
	constructtree(zero,s,m,i*2+1);
	constructtree(zero,m+1,e,i*2+2);
	zero[i]=zero[i*2+1]+zero[i*2+2];
}
void add(vector<int> &z,vector<int> &o,vector<int> &t,vector<int> &l,int s,int e,int i,int a,int b)
{
	if(l[i]!=0)
	{
		int val=l[i];
		if(val%3==0)
		{
			//do nothing
		}
		else if(val%3==1)
		{
			int temp=z[i];
			z[i]=t[i];
			t[i]=o[i];
			o[i]=temp;
		}
		else if(val%3==2)
		{
			int temp=z[i];
			z[i]=o[i];
			o[i]=t[i];
			t[i]=temp;
		}
		if(s!=e)
		{
			l[i*2+1]+=l[i];
			l[i*2+2]+=l[i];
		}
		l[i]=0;
	}
	if(s>e || a>e || b<s)
		return ;
	if(a<=s && b>=e)
	{
		int temp=z[i];
		z[i]=t[i];
		t[i]=o[i];
		o[i]=temp;
		if(s!=e)
		{
			l[i*2+1]+=1;
			l[i*2+2]+=1;
		}
		return;
	}
	int m=s+(e-s)/2;
	add(z,o,t,l,s,m,i*2+1,a,b);
	add(z,o,t,l,m+1,e,i*2+2,a,b);
	if(s==e)
		return;
	z[i]=z[i*2+1]+z[i*2+2];
	o[i]=o[i*2+1]+o[i*2+2];
	t[i]=t[i*2+1]+t[i*2+2];
}
int find(vector<int> &z,vector<int> &o,vector<int> &t,vector<int> &l,int s,int e,int i,int a,int b)
{
	if(l[i]!=0)
	{
		int val=l[i];
		if(val%3==0)
		{
			//continue;
		}
		else if(val%3==1)
		{
			int temp=z[i];
			z[i]=t[i];
			t[i]=o[i];
			o[i]=temp;
		}
		else if(val%3==2)
		{
			int temp=z[i];
			z[i]=o[i];
			o[i]=t[i];
			t[i]=temp;
		}
		if(s!=e)
		{
			l[i*2+1]+=l[i];
			l[i*2+2]+=l[i];
		}
		l[i]=0;
	}
	if(s>e || a>e || b<s)
		return 0;
	if(a<=s && b>=e)
	{
		return z[i];
	}
	int m=s+(e-s)/2;
	int left=find(z,o,t,l,s,m,i*2+1,a,b);
	int right=find(z,o,t,l,m+1,e,i*2+2,a,b);
	if(s==e)
		return left+right;
	z[i]=z[i*2+1]+z[i*2+2];
	o[i]=o[i*2+1]+o[i*2+2];
	t[i]=t[i*2+1]+t[i*2+2];
	return left+right;
}
int main()
{
	int n,q;
	//cin>>n>>q;
	scanf("%d%d",&n,&q);
	int n1=(int)(ceil(log2(n)));
	n1=2*pow(2,n1)-1;
	vector<int> zero(n1,0);
	vector<int> one(n1,0);
	vector<int> two(n1,0);
	vector<int> lazy(n1,0);
	constructtree(zero,0,n-1,0);
//	for(int i=0;i<n1;i++)
//		cout<<zero[i]<<" ";
	int op;
	int a,b;
	while(q--)
	{
//		cin>>op>>a>>b;
		scanf("%d%d%d",&op,&a,&b);
		if(op==0)
		{
			add(zero,one,two,lazy,0,n-1,0,a,b);
		}
		else
		{
			printf("%d\n",find(zero,one,two,lazy,0,n-1,0,a,b));
		}
	//	for(int i=0;i<n1;i++)
	//		cout<<zero[i]<<" "<<one[i]<<" "<<two[i]<<" "<<lazy[i]<<endl;
	//	cout<<endl;
	}
	return 0;
}
