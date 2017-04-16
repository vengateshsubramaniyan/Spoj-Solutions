#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	char s[1000001];
	scanf("%s",s);
	vector< vector<int> > pos(26);
	for(ll i=0;s[i]!='\0';i++)
		pos[s[i]-'A'].push_back(i);
	ll n;
	char st,des;
	scanf("%lld",&n);
	while(n--)
	{
		char temp[4];
		scanf("\n%[^\n]",temp);
		st=temp[0];
		des=temp[2];
		int si=st-'A';
		int di=des-'A';
		ll j=pos[di].size();
		ll i=pos[si].size();
		bool result=false;
		if(st==des)
		{
			if(pos[st-'A'].size()>=2)
				result=true;
		}
		else if(i!=0 && j!=0)
		{
			if(pos[si][0]<pos[di][j-1])
				result=true;
		}
		if(result)
			printf("YA\n");
		else
			printf("TIDAK\n");
	}
	return 0;
}
