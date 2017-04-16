#include<bits/stdc++.h>
using namespace std;
struct cmpp
{
	bool operator()(const int &a,const int &b)
	{
		return a>b;
	}
};
int main()
{
	int n,m,src,des,k;
	scanf("%d%d",&n,&m);
	vector< set<int> > arr(n+1);
	vector< int > count(n+1,0);
	while(m--)
	{
		scanf("%d%d",&src,&k);
		while(k--)
		{
			scanf("%d",&des);
			arr[des].insert(src);
			count[src]++;
		}
	}
	priority_queue< int ,vector<int> , cmpp> zero;
	for(int i=1;i<=n;i++)
		if(count[i]==0)
			zero.push(i);
	set<int>::iterator it;
	while(!zero.empty())
	{
		int u=zero.top();
		printf("%d ",u);
		zero.pop();
		for(it=arr[u].begin();it!=arr[u].end();it++)
		{
			count[*it]--;
			if(count[*it]==0)
			{
				zero.push(*it);
			}
		}
	}
	return 0;
}
