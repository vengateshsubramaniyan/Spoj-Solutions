#include<bits/stdc++.h>
using namespace std;
int row[]={2,1,-1,-2,-2,-1,1,2};
int col[]={-1,-2,-2,-1,1,2,2,1};
void knight(vector< pair<int,int> > &board,vector< vector<bool> > &visit,int r,int c,int reach,int &result,int nr)
{
	visit[r][c]=true;
	bool no=true;
	for(int i=0;i<8;i++)
	{
		int ci=r+row[i];
		int cj=c+col[i];
		if(ci>=0 && ci<nr)
		{
			int of=board[ci].first;
			int nc=(board[ci].second)+of;
			if(cj>=of && cj<nc && !visit[ci][cj])
			{
				no=false;
				knight(board,visit,ci,cj,reach+1,result,nr);
			}
		}
	}
	visit[r][c]=false;
	if(no)
	{
		if(reach>result)
			result=reach;
	}
}
int main()
{
	int r,t=1;
	scanf("%d",&r);
	while(r)
	{
		vector< pair<int,int> > board(r);
		int col=0;
		int tq=0;
		for(int i=0;i<r;i++)
		{
			int of,e;
			scanf("%d%d",&of,&e);
			board[i]=pair<int,int>(of,e);
			if(of+e>col)
				col=of+e;
			tq+=e;
		}
//			cout<<tq<<" "<<col<<endl;
		vector< vector<bool> > visit(r,vector<bool>(col,false));
		int sr=0;
		int sc=board[0].first;
		int result=1;
		knight(board,visit,sr,sc,1,result,r);
		result=tq-result;
		if(result==1)
		{
			printf("Case %d, 1 square can not be reached.",t);
		}
		else
		{
			printf("Case %d, %d squares can not be reached.",t,result);
		}
		board.clear();
		visit.clear();
		scanf("%d",&r);
		if(r!=0)
			printf("\n");
		t++;
	}
	return 0;
}
