#include<bits/stdc++.h>
using namespace std;
static bool cmpp(const pair<int,int> a,const pair<int,int> b)
{
	return a.first>=b.first;
}
int main()
{
	int n;
	scanf("%d",&n);
	vector< pair<int,int> > arr(n+9);
	for(int i=0;i<n;i++)
	{
		scanf("%d%d",&arr[i].first,&arr[i].second);
	}
	sort(arr.begin(),arr.end(),cmpp);
	bool visit[10009]={0};
	int result=0;
	for(int i=0;i<n;i++)
	{
		int temp=arr[i].second;
		while(temp)
		{
			if(!visit[temp])
			{
				visit[temp]=1;
				result+=arr[i].first;
				break;
			}
			else
				temp--;
		}
	}
	printf("%d",result);
	return 0;
}
