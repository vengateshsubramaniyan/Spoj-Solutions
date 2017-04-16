#include<bits/stdc++.h>
using namespace std;
bool gt(vector< int > &val,int a)
{
	if(a==9)
		return false;
	for(int i=a+1;i<10;i++)
	{
		if(val[i]!=0)
			return true;
	}
	return false;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		vector< int > val(10,0);
		queue< pair<int,int> > q;
		for(int i=0;i<n;i++)
		{	
			int temp;
			scanf("%d",&temp);
			val[temp]++;
			q.push(pair<int,int>(temp,i));
		}
		int result=0;
		while(1)
		{
			int v=q.front().first;
			int i=q.front().second;
			q.pop();
			if(gt(val,v))
			{
				q.push(pair<int,int>(v,i));
			}
			else
			{
				result++;
				if(i==m)
				{
					printf("%d\n",result);
					break;
				}
				val[v]--;
			}
		}
	}
	return 0;
}
