#include<bits/stdc++.h>
using namespace std;
int row[]={1,2,2,1,-1,-2,-2,-1};
int col[]={-2,-1,1,2,2,1,-1,-2};
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		char a1,a2,b1,b2;
		vector<vector<char> > arr(8,vector<char>(8,'0'));
		scanf("\n%c%c %c%c",&a1,&a2,&b1,&b2);
		queue<pair< pair<int,int> , int> > q;
		q.push(pair< pair<int,int> ,int >(pair<int,int>(a1-'a',a2-'1'),0));
		arr[b1-'a'][b2-'1']='e';
		bool found=false;
		int result;
		while(!q.empty() && !found)
		{
			int i=q.front().first.first;
			int j=q.front().first.second;
			int dist=q.front().second;
			if(arr[i][j]=='e')
			{
				result=dist;
				found=true;
			}
			q.pop();
			arr[i][j]='1';
			for(int k=0;k<8;k++)
			{
				int ci=i+row[k];
				int cj=j+col[k];
				if(ci>=0 && cj>=0 && ci<8 && cj<8 && arr[ci][cj]!='1')
				{
					q.push(pair< pair<int,int> ,int >(pair<int,int>(ci,cj),dist+1));
				}
			}
		}
		printf("%d\n",result);
	}
	return 0;
}
