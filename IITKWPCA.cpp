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
	cin>>t;
	t++;
	bool fake=true;
	while(t--)
	{
		string s;
		getline(cin,s);
		string temp="";
		int res=0;
		map<string,bool> m;
		for(int i=0;i<s.length();i++)
		{
			if(s[i]==' ')
			{
				if(temp.length()>0 && m[temp]==false)
				{
					m[temp]=true;
					res++;
				}
				temp="";
			}
			else
				temp+=s[i];
		}
		if(temp.length()>0 && m[temp]==false)
			res++;
		if(!fake)
			cout<<res<<endl;
		fake=false;
	}
	return 0;
}
