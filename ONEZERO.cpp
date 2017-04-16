#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	ll te;
	scanf("%lld",&te);
	while(te--)
	{
		ll n;
		scanf("%lld",&n);
		queue< pair<string,ll> > q;
		q.push(pair<string,ll>("1",1));
		while(!q.empty())
		{
			string s=q.front().first;
			ll r=q.front().second;
			if(r%n==0)
			{
				cout<<s<<endl;
				break;
			}
			q.pop();
			ll t=(r*10)%n;
			if(t==0)
			{
				s=s+'0';
				cout<<s<<endl;
				break;
			}
			q.push(pair<string,ll>(s+'0',t));
			t=((r*10)+1)%n;
			if(t==0)
			{
				s=s+'1';
				cout<<s<<endl;
				break;
			}
			q.push(pair<string,ll>(s+'1',t));
		}
	}	
	return 0;
}
