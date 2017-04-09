#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		map<string , int > m;
		vector< string > v(101);
		vector< bool > fre(101,true);
		int ac=0;
		while(n--)
		{
			string s,s1="";
			cin>>s;
			int hashvalue=0;
			for(int i=4;i<s.length();i++)
			{
				hashvalue+=(int)(s[i])*(i-3);
				s1=s1+s[i];
			}
			hashvalue*=19;
			hashvalue%=101;
			if(s[0]=='A')
			{
				if(m.find(s1)==m.end() || m[s1]==-1)
				{
					int j=0;
					while(j!=20)
					{
						int temp=(hashvalue+j*j+23*j)%101;
						if(fre[temp])
						{
							fre[temp]=false;
							v[temp]=s1;
							m[s1]=temp;
							ac++;
							break;
						}
						j++;
					}
				}
			}
			else
			{
				if(m.find(s1)!=m.end())
				{
					if(m[s1]!=-1)
					{
						fre[m[s1]]=true;
						m[s1]=-1;
						ac--;
					}
				}
			}
		}
		printf("%d\n",ac);
		for(int i=0;i<101;i++)
		{
			if(!fre[i])
			{
				cout<<i<<":"<<v[i]<<endl;
			}
		}
		cout<<endl;
	}
	return 0;
}
