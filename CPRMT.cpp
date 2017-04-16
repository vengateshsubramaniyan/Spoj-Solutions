#include<bits/stdc++.h>
using namespace std;
int main()
{
	char a[1005],b[1005];
	while(scanf("%s",a)!=EOF)
	{
		scanf("%s",b);
		vector< int > acount(26,0);
		vector< int > bcount(26,0);
		for(int i=0;a[i]!='\0';i++)
			acount[a[i]-'a']++;
		for(int j=0;b[j]!='\0';j++)
			bcount[b[j]-'a']++;
		string result="";
		for(int i=0;i<26;i++)
		{
			int co=min(acount[i],bcount[i]);
			while(co--)
			{
				result+='a'+i;
			}
		}
		cout<<result<<endl;
	}
	return 0;
}
