#include<bits/stdc++.h>
using namespace std;
int main()
{
	int test;
	scanf("%d",&test);
	for(int t=1;t<=test;t++)
	{
		int n;
		scanf("%d",&n);
		vector<string> val(n+1);
		vector<int> tree(n+1,0);
		vector<bool> dest(n+1,false);
		map<string,int> m;
		int s=1;
		for(int i=1;i<n;i++)
		{
			string src,des;
			cin>>src>>des;
			if(m.find(src)==m.end())
			{
				val[s]=src;
				m.insert(pair<string,int>(src,s));
				s++;
			}
			if(m.find(des)==m.end())
			{
				val[s]=des;
				m.insert(pair<string,int>(des,s));
				s++;
			}
//			cout<<src<<" "<<des<<endl;
//			cout<<m[src]<<" "<<m[des]<<endl;
			dest[m[des]]=true;
			tree[m[src]]=m[des];
		}
		int start=1;
		for(int i=1;i<=n;i++)
		{
			if(dest[i]==false)
			{
				start=i;
				break;
			}
		}
		printf("Scenario #%d:\n",t);
		while(start!=0)
		{
//			cout<<start<<endl;
			cout<<val[start]<<endl;
			start=tree[start];
		}
		cout<<endl;
	}
	return 0;
}
