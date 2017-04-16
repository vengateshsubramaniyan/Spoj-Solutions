#include<bits/stdc++.h>
using namespace std;
struct cmpp
{
	bool operator()(pair< int ,pair<int,int> > a,pair<int,pair<int,int> > b)
	{
		return a.first>b.first;
	}
};
int row[]={1,0,-1,0};
int col[]={0,1,0,-1};
int main()
{
	int r,c;
	scanf("%d%d",&r,&c);
	char arr[r][c];
	for(int i=0;i<r;i++)
		scanf("%s",arr[i]);
	priority_queue< pair< int ,pair<int,int> > ,vector< pair<int, pair<int,int> > > ,cmpp > pq;
	pq.push(pair< int ,pair<int,int> >(0,pair<int,int>(0,0)));
	vector< vector<bool> > visit(r,vector<bool>(c,false));
	int result=-1;
	while(!pq.empty())
	{
		int i=pq.top().second.first;
		int j=pq.top().second.second;
		int jump=pq.top().first;
		pq.pop();
		if(i==r-1 && j==c-1)
		{
			result=jump;
			break;
		}
		visit[i][j]=true;
		for(int k=0;k<4;k++)
		{
			int ci=i+((arr[i][j]-'0')*row[k]);
			int cj=j+((arr[i][j]-'0')*col[k]);
			if(ci>=0 && ci<r && cj>=0 && cj<c && !visit[ci][cj])
			{
				pq.push(pair< int ,pair<int,int> >(jump+1,pair<int,int>(ci,cj)));
			}
		}
	}
	printf("%d\n",result);
	return 0;
}
