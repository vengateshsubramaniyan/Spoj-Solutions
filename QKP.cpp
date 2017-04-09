#include<bits/stdc++.h>
using namespace std;
int row[]={-1,-2,-2,-1,1,2,2,1};
int col[]={-2,-1,1,2,-2,-1,1,2};
bool con(vector< vector< int > > &board,int i,int j,int r,int c)
{
	if(i<0 || j<0 || i>r || j>c || board[i][j]==3 || board[i][j]==2 || board[i][j]==1)
		return false;
	return true;
}
void queen(vector< vector< int > > &board,int r,int c,int i,int j)
{
	for(int ci=i+1,cj=j+1;;ci++,cj++)
	{
		if(con(board,ci,cj,r,c))
		{
			if(board[ci][cj]==0)
				board[ci][cj]=4;
		}
		else
			break;
	}
	for(int ci=i-1,cj=j-1;;ci--,cj--)
	{
		if(con(board,ci,cj,r,c))
		{
			if(board[ci][cj]==0)
				board[ci][cj]=4;
		}
		else
			break;
	}
	for(int ci=i+1,cj=j-1;;ci++,cj--)
	{
		if(con(board,ci,cj,r,c))
		{
			if(board[ci][cj]==0)
				board[ci][cj]=4;
		}
		else
			break;
	}
	for(int ci=i-1,cj=j+1;;ci--,cj++)
	{
		if(con(board,ci,cj,r,c))
		{
			if(board[ci][cj]==0)
				board[ci][cj]=4;
		}
		else
			break;
	}
	for(int ci=i+1;;ci++)
	{
		if(con(board,ci,j,r,c))
		{
			if(board[ci][j]==0)
				board[ci][j]=4;
		}
		else
			break;
	}
	for(int ci=i-1;;ci--)
	{
		if(con(board,ci,j,r,c))
		{
			if(board[ci][j]==0)
				board[ci][j]=4;
		}
		else
			break;
	}
	for(int cj=j+1;;cj++)
	{
		if(con(board,i,cj,r,c))
		{
			if(board[i][cj]==0)
				board[i][cj]=4;
		}
		else
			break;
	}
	for(int cj=j-1;;cj--)
	{
		if(con(board,i,cj,r,c))
		{
			if(board[i][cj]==0)
				board[i][cj]=4;
		}
		else
			break;
	}
}
void knight(vector< vector<int> > &board,int r,int c,int i,int j)
{
	for(int k=0;k<8;k++)
	{
		int ci=row[k]+i;
		int cj=col[k]+j;
		if(ci>0 && cj>0 && ci<=r && cj<=c)
		{
			if(board[ci][cj]==0)
				board[ci][cj]=4;
		}
	}
}
int main()
{
	int r,c;
	scanf("%d%d",&r,&c);
	int test=1;
	while(r && c)
	{
		vector< vector< int > > board(r+1,vector<int>(c+1,0));
		int k;
		scanf("%d",&k);
		while(k--)
		{
			int p1,p2;
			scanf("%d%d",&p1,&p2);
			board[p1][p2]=1;
		}
		scanf("%d",&k);
		while(k--)
		{
			int p1,p2;
			scanf("%d%d",&p1,&p2);
			board[p1][p2]=2;
		}
		scanf("%d",&k);
		while(k--)
		{
			int p1,p2;
			scanf("%d%d",&p1,&p2);
			board[p1][p2]=3;
		}
		for(int i=1;i<=r;i++)
		{
			for(int j=1;j<=c;j++)
			{
				if(board[i][j]==1)
				{
					queen(board,r,c,i,j);
				}
				else if(board[i][j]==2)
				{
					knight(board,r,c,i,j);
				}
			}
		}
		int result=0;
		for(int i=1;i<=r;i++)
		{
			for(int j=1;j<=c;j++)
			{
//				cout<<board[i][j]<<" ";
				if(board[i][j]==0)
					result++;
			}
//			cout<<endl;
		}
		printf("Board %d has %d safe squares.",test++,result);
		scanf("%d%d",&r,&c);
		if(r==0 && c==0)
			break;
		printf("\n");
	}
	return 0;
}
