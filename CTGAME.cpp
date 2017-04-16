#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll histogram(vector< ll > &a,ll n)
{
	ll result=0;
	ll i=0;
	stack< ll > s;
	while(i<n)
	{
		if(s.empty() || a[s.top()]<=a[i])
			s.push(i++);
		else
		{
			ll tt=s.top();
			s.pop();
			ll area=a[tt]*(s.empty()?i:i-s.top()-1);
			if(area>result)
				result=area;
		}
	}
	while(!s.empty())
	{
		ll tt=s.top();
		s.pop();
		ll area=a[tt]*(s.empty()?i:i-s.top()-1);
		if(area>result)
			result=area;
	}
	return result;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int r,c;
		ll result=0;
		char cc;
		scanf("%d%d",&r,&c);
		vector< ll > his(c,0);
		for(int i=0;i<r;i++)
		{
			for(int j=0;j<c;j++)
			{
				cin>>cc;
				if(cc=='F')
					his[j]++;
				else
					his[j]=0;
//				cout<<his[j]<<" ";
			}
//			cout<<endl;
			ll temp=histogram(his,c);
			if(temp>result)
				result=temp;
		}
		his.clear();
		printf("%lld\n",result*3);
	}
	return 0;
}
