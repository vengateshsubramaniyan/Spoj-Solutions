#include<bits/stdc++.h>
#define ll long long unsigned
using namespace std;
ll find(ll p,ll q,vector<string> &result)
{
	ll que=p/q;
	ll rem=p%q;
	if(rem==0)
	{
		string r="1";
		result.push_back(r);
		string temp="";
		for(int i=0;i<1;i++)
			temp=temp+"-";
		ostringstream out;
		que--;
		out<<que;
		temp=out.str()+".+."+temp;
		result.push_back(temp);
		int len=temp.length();
		temp="1";
		result.push_back(temp);
		return len;
	}
	else if(q==1)
	{
		string r="1";
		result.push_back(r);
		string temp="";
		for(int i=0;i<1;i++)
			temp=temp+"-";
		ostringstream out;
		p--;
		out<<p;
		temp=out.str()+".+."+temp;
		result.push_back(temp);
		ll len=temp.length();
		temp="1";
		result.push_back(temp);
		return len;
	}
	ll rlen=find(q,p%q,result);
	string temp="";
	for(ll i=0;i<rlen;i++)
		temp+="-";
	ostringstream out;
	out<<que;
	temp=out.str()+".+."+temp;
	result.push_back(temp);
	ll len=temp.length();
	temp="1";
	rlen--;
	while(rlen)
	{
		temp+=".";
		rlen--;
		if(rlen)
		{
			temp="."+temp;
			rlen--;
		}
	}
	result.push_back(temp);
	return len;
}
int main()
{
	ll p,q;
	scanf("%lld%lld",&p,&q);
	ll ca=1;
	bool first=true;
	while(p && q)
	{
		if(!first)
		{
			printf("\n");
		}
		else
			first=false;
		printf("Case %lld:\n",ca);
		printf("%lld / %lld\n",p,q);
		ca++;
		vector<string> result;
		ll rlen=find(p,q,result);
		ll len=result.size();
		for(len=len-1;len>=0;)
		{
			ll r=result[len].length();
			while(r<rlen)
			{
				cout<<".";
				r++;
			}
			cout<<result[len];
			len--;
			if(len==-1)
				break;
			cout<<endl;
		}
		scanf("%lld%lld",&p,&q);
	}
	return 0;
}
