#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		map<string,int> m;
		set<string> s;
		int n;
		scanf("%d",&n);
		char arr[30];
		for(int i=0;i<n;i++)
		{
			scanf("\n%[^\n]s",arr);
			if(m.find(arr)==m.end())
			{
				s.insert(arr);
			}
			m[arr]++;
		}
		set<string>::iterator it;
		for(it=s.begin();it!=s.end();it++)
		{
			cout<<*it<<" "<<m[*it]<<endl;
		}
		if(t!=0)
			printf("\n");
	}
	return 0;
}
