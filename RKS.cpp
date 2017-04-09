#include<bits/stdc++.h>
using namespace std;
static bool cmpp(pair< int ,pair<int,int> > a,pair<int ,pair<int,int> > b)
{
	if(a.second.first>b.second.first)
		return true;
	if(a.second.first<b.second.first)
		return false;
	return a.second.second<b.second.second;
}
int main()
{
	int n,c;
	scanf("%d%d",&n,&c);
	map< int ,pair<int,int> > m;
	int un=0;
	for(int i=0;i<n;i++)
	{
		int val;
		scanf("%d",&val);
		if(m.find(val)==m.end())
		{
			un++;
			m[val].first=1;
			m[val].second=i;
		}
		else
			m[val].first++;
	}
	vector< pair< int ,pair<int,int> > > a(un);
	map< int ,pair<int,int> >::iterator it;
	int i=0;
	for(it=m.begin();it!=m.end();it++)
	{
		a[i].first=(*it).first;
		a[i].second.first=(*it).second.first;
		a[i].second.second=(*it).second.second;
		i++;
	}
	sort(a.begin(),a.end(),cmpp);
	for(int i=0;i<un;i++)
	{
		int co=a[i].second.first;
		while(co--)
		{
			printf("%d ",a[i].first);
		}
	}
	return 0;
}
