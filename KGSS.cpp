#include<bits/stdc++.h>
using namespace std;
void constructtree(vector<pair<int,int> > &seg,vector<int> &arr,int s,int e,int i)
{
	if(s==e)
	{
		seg[i].first=arr[s];
		seg[i].second=-1;
		return;
	}
	int m=s+(e-s)/2;
	constructtree(seg,arr,s,m,i*2+1);
	constructtree(seg,arr,m+1,e,i*2+2);
	int sf,ss;
	int e1=seg[i*2+1].first;
	int e2=seg[i*2+1].second;
	int e3=seg[i*2+2].first;
	int e4=seg[i*2+2].second;
	if(e1>=e2 && e1>=e3 && e1>=e4)
	{
		sf=e1;
		ss=max(e2,max(e3,e4));
	}
	else if(e2>=e1 && e2>=e3 && e2>=e4)
	{
		sf=e2;
		ss=max(e1,max(e3,e4));
	}
	else if(e3>=e1 && e3>=e2 && e3>=e4)
	{
		sf=e3;
		ss=max(e1,max(e2,e4));
	}
	else
	{
		sf=e4;
		ss=max(e1,max(e2,e3));
	}
	seg[i].first=sf;
	seg[i].second=ss;
}
void updateseg(vector< pair<int,int> > &seg,int s,int e,int i,int &si,int &val)
{
	if(s==e)
	{
		if(s==si)
		{
			seg[i].first=val;
		}
		return;
	}
	int m=s+(e-s)/2;
	if(si<=m)
		updateseg(seg,s,m,i*2+1,si,val);
	else
		updateseg(seg,m+1,e,i*2+2,si,val);
	int sf,ss;
	int e1=seg[i*2+1].first;
	int e2=seg[i*2+1].second;
	int e3=seg[i*2+2].first;
	int e4=seg[i*2+2].second;
	if(e1>=e2 && e1>=e3 && e1>=e4)
	{
		sf=e1;
		ss=max(e2,max(e3,e4));
	}
	else if(e2>=e1 && e2>=e3 && e2>=e4)
	{
		sf=e2;
		ss=max(e1,max(e3,e4));
	}
	else if(e3>=e1 && e3>=e2 && e3>=e4)
	{
		sf=e3;
		ss=max(e1,max(e2,e4));
	}
	else
	{
		sf=e4;
		ss=max(e1,max(e2,e3));
	}
	seg[i].first=sf;
	seg[i].second=ss;
}
void query(vector<pair<int,int> > &seg,int s,int e,int i,int &a,int &b,int &n1,int &n2)
{
	if(s>e || a>e || b<s)
		return;
	if(s==e)
	{
		if(n1<seg[i].first)
		{
			n2=n1;
			n1=seg[i].first;
		}
		else if(n2<seg[i].first)
		{
			n2=seg[i].first;
		}
		return;
	}
	if(a<=s && b>=e)
	{
		if(n1<seg[i].first)
		{
			n2=n1;
			n1=seg[i].first;
			if(n2<seg[i].second)
				n2=seg[i].second;
		}
		else if(n2<seg[i].first)
		{
			n2=seg[i].first;
		}
		return;
	}
	int m=s+(e-s)/2;
	query(seg,s,m,i*2+1,a,b,n1,n2);
	query(seg,m+1,e,i*2+2,a,b,n1,n2);
}
int main()
{
	int n;
	scanf("%d",&n);
	vector<int> arr(n);
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);
	int n1=(int)(ceil(log2(n)));
	n1=2*pow(2,n1)-1;
	vector<pair<int,int> > seg(n1,pair<int,int>(0,0));
	constructtree(seg,arr,0,n-1,0);
	int q;
	scanf("%d",&q);
	while(q--)
	{
		char op;
		cin>>op;
		int i,x;
		scanf("%d%d",&i,&x);
		if(op=='U')
		{
			i--;
			updateseg(seg,0,n-1,0,i,x);
		}
		else
		{
			i--;
			x--;
			int n1=-1,n2=-1;
			query(seg,0,n-1,0,i,x,n1,n2);
			long long sum=n1+n2;
			printf("%lld\n",sum);
		}
	}
	return 0;
}
