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
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,k;
		scanf("%d%d",&n,&k);
		vector<int> pos;
		vector<int> neg;
		bool zero=false;
		int pos_min=INT_MAX;
		for(int i=0;i<n;i++)
		{
			int val;
			scanf("%d",&val);
			if(val>0)
			{
				pos_min=min(pos_min,val);
				pos.push_back(val);
			}
			else if(val<0)
				neg.push_back(val);
			else
				zero=true;
		}
		for(int i=0;i<neg.size() && k;i++)
		{
			neg[i]=-neg[i];
			k--;
		}
		if(neg.size()==0 && pos.size()==0)
		{
			printf("0\n");
			continue;
		}
		if(zero)
			k=0;
		if(k==0)
		{
			int res=0;
			for(int i=0;i<pos.size();i++)
				res+=pos[i];
			for(int i=0;i<neg.size();i++)
				res+=neg[i];
			printf("%d\n",res);
			continue;
		}
		if(neg.size()==0)
		{
			int res=0;
			for(int i=0;i<pos.size();i++)
				res+=pos[i];
			if(k%2!=0)
				res-=(pos_min*2);
			printf("%d\n",res);
			continue;
		}
		if(pos.size()==0)
		{
			int res=0;
			for(int i=0;i<neg.size();i++)
				res+=neg[i];
			if(k%2!=0)
				res-=(neg[neg.size()-1]*2);
			printf("%d\n",res);
			continue;
		}
		int res=0;
		for(int i=0;i<pos.size();i++)
			res+=pos[i];
		for(int i=0;i<neg.size();i++)
			res+=neg[i];
		if(k%2!=0)
			res-=(min(pos_min,neg[neg.size()-1])*2);
		printf("%d\n",res);
	}
	return 0;
}


