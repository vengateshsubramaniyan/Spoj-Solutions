#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long t;
	scanf("%lld",&t);
	while(t--)
	{
		char key[1000001];
		char message[1000];
		scanf("\n%[^\n]s",key);
		scanf("\n%[^\n]s",message);
		long long ki=0;
		string result="";
		bool up=true;
		for(long long i=0;message[i]!='\0';i++)
		{
			int ke=key[ki]-'0';
			char r=message[i]-ke;
			if(r>='a' && r<='z')
				message[i]=r;
			else
			{
				int pos='a'-r;
				pos=pos-1;
				message[i]=('z'-pos);
			}
			if(up)
			{
				ki++;
				if(key[ki]=='\0')
				{
					ki--;
					up=false;
				}
			}
			else
			{
				ki--;
				if(ki==-1)
				{
					ki=0;
					up=true;
				}
			}
		}
		printf("%s\n",message);
		
	}
	return 0;
}
