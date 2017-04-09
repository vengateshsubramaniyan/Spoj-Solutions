#include<bits/stdc++.h>
using namespace std;
int row[]={0,-1,-1,-1,0,1,1,1};
int col[]={-1,-1,0,1,1,1,0,-1};
int main()
{
	int r,c;
	int t=1;
	scanf("%d%d",&r,&c);
	while(r && c)
	{
		char arr[r][c];
		for(int i=0;i<r;i++)
		{
			scanf("\n%[^\n]s",arr[i]);
		}
		queue<pair< pair<int,int> , int > > q;
		for(int i=0;i<r;i++)
		{
			for(int j=0;j<c;j++)
			{
				if(arr[i][j]=='A')
				{
					q.push(pair< pair<int,int> ,int >(pair<int,int>(i,j),1));
				}
			}
		}
		bool found=false;
		int result=0;
		while(!q.empty() && !found)
		{
			int i=q.front().first.first;
			int j=q.front().first.second;
			char cc=arr[i][j];
			arr[i][j]='.';
			int len=q.front().second;
			q.pop();
			if(len==26)
			{
				result=26;
				found=true;
			}
			bool in=true;
			if(!found)
			{
				for(int k=0;k<8;k++)
				{
					int ci=i+row[k];
					int cj=j+col[k];
					if(ci>=0 && ci<r && cj>=0 && cj<c && arr[ci][cj]!='.' && cc+1==arr[ci][cj])
					{
						in=false;
						q.push(pair< pair<int,int> ,int >(pair<int,int>(ci,cj),len+1));
					}
				}
			}
			if(in && result<len)
				result=len;
		}
		printf("Case %d: %d\n",t,result);
		scanf("%d%d",&r,&c);
		t++;
	}
	return 0;
}
