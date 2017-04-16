#include<bits/stdc++.h>
#define ll long long
#define pq priority_queue<ll>
#define pq1 priority_queue<ll,vector<ll>,cmpp>
using namespace std;
struct cmpp
{
	bool operator()(const ll a,const ll b)
	{
		return a>b;
	}
};
ll median(pq &left,pq1 &right,ll &mincount,ll &maxcount)
{
	if(mincount==maxcount || mincount>maxcount)
	{
		ll res=left.top();
		left.pop();
		mincount--;
		return res;
	}
	else
	{
		ll res=right.top();
		right.pop();
		maxcount--;
		return res;
	}
}
void add(pq &left,pq1 &right,ll &mincount,ll &maxcount,ll val)
{
	right.push(val);
	maxcount++;
	if((maxcount-mincount)>1 || (mincount!=0 && right.top()<left.top()))
	{
		maxcount--;
		mincount++;
		left.push(right.top());
		right.pop();
	}
	if(mincount!=0 &(mincount-maxcount)>1)
	{
		mincount--;
		maxcount++;
		right.push(left.top());
		left.pop();
	}
}
int main()
{
	ll test;
	scanf("%lld",&test);
	while(test--)
	{
		pq left;
		pq1 right;
		ll mincount=0;
		ll maxcount=0;
		while(1)
		{
			ll val;
			scanf("%lld",&val);
			if(val==0)
				break;
			if(val==-1)
			{
				printf("%lld\n",median(left,right,mincount,maxcount));
			}
			else
			{
				add(left,right,mincount,maxcount,val);
			}
		}
	}
	return 0;
}
