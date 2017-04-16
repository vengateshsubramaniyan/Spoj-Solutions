#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int result=0;
		int plen=0;
		int r=0;
		char s[1000000];
		scanf("\n%[^\n]s",s);
		char *pch;
		pch= strtok(s," ,\t,\r");
		while(pch!=NULL)
		{
			int l=strlen(pch);
			if(plen==l)
				r++;
			else
			{
				if(r>result)
					result=r;
				plen=l;
				r=1;
			}
//			cout<<pch<<" "<<l<<" "<<plen<<endl;
			pch =strtok(NULL," ,\t,\r");
		}
		if(r>result)
			result=r;
		printf("%d\n",result);
	}
}
