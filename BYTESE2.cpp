#include<bits/stdc++.h>
#define ll long long
using namespace std;
static bool cmpp(const pair<int,bool> a,const pair<int,bool> b)
{
	return a.first<b.first;
}
int main()
{
	int t,n,s,e;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		vector< pair<int,bool> > arr;
		bool start=true;
		for(int i=0;i<n;i++)
		{
			scanf("%d%d",&s,&e);
			arr.push_back(pair<int,bool>(s,true));
			arr.push_back(pair<int,bool>(e,false));
		}
		int result=0,curr=0;
		sort(arr.begin(),arr.end(),cmpp);
		for(int i=0;i<2*n;i++)
		{
			if(arr[i].second)
			{
				curr++;
				if(result<curr)
					result=curr;	
			}
			else
				curr--;
		}
		printf("%d\n",result);
	}
	return 0;
}
