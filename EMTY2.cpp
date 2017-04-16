#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	for(int test=1;test<=t;test++)
	{
		char s[120001];
		scanf("%s",s);
		vector< char > v;
		int size=0;
		for(int i=0;s[i]!='\0';i++)
		{
			v.push_back(s[i]);
			size++;
			while(size>2 && v[size-1]=='0' && v[size-2]=='0' && v[size-3]=='1')
			{
				size-=3;
				v.pop_back();v.pop_back();v.pop_back();
			}
		}
		while(size>2 && v[size-1]=='0' && v[size-2]=='0' && v[size-3]=='1')
		{
			size-=3;
			v.pop_back();v.pop_back();v.pop_back();
		}
		printf("Case %d: ",test);
		if(size==0)
			printf("yes\n");
		else
			printf("no\n");
	}
	return 0;
}
