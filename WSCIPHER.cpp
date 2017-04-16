#include<bits/stdc++.h>
using namespace std;
int main()
{
	int k1,k2,k3;
	scanf("%d%d%d",&k1,&k2,&k3);
	while(k1 && k2 && k3)
	{
		vector< int > a1;
		vector< int > a2;
		vector< int > a3;
		char s[100];
		scanf("%s",s);
		for(int i=0;s[i]!='\0';i++)
		{
			if(s[i]>='a' && s[i]<='i')
			{
				a1.push_back(i);
			}
			else if(s[i]>='j' && s[i]<='r')
			{
				a2.push_back(i);
			}
			else
			{
				a3.push_back(i);
			}
		}
		string r="";
		int ai=0,bi=0,ci=0;
		if(a1.size()!=0 && k1>=a1.size())
		{
			ai=k1%a1.size();
			if(ai!=0)
				ai=a1.size()-ai;	
		}
		else if(a1.size()!=0)
			ai=a1.size()-k1;
		if(a2.size()!=0 && k2>=a2.size())
		{
			bi=k2%a2.size();
			if(bi!=0)
				bi=a2.size()-bi;
		}
		else if(a2.size()!=0)
			bi=a2.size()-k2;
		if(a3.size()!=0 && k3>=a3.size())
		{
			ci=k3%a3.size();
			if(ci!=0)
				ci=a3.size()-ci;
		}
		else if(a3.size()!=0)
			ci=a3.size()-k3;
		for(int i=0;s[i]!='\0';i++)
		{
			if(s[i]>='a' && s[i]<='i')
			{
				r+=s[a1[ai]];
				ai=(ai+1)%a1.size();
			}
			else if(s[i]>='j' && s[i]<='r')
			{
				r+=s[a2[bi]];
				bi=(bi+1)%a2.size();
			}
			else
			{
				r+=s[a3[ci]];
				ci=(ci+1)%a3.size();
			}
		}
		cout<<r<<endl;
		scanf("%d%d%d",&k1,&k2,&k3);
	}
	return 0;
}
