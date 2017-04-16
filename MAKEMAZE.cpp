#include<bits/stdc++.h>
using namespace std;
bool findopening(vector<vector<char> > &maze,int &mr,int &mc,int r,int c)
{
	int opcount=0;
	if(r==1)
	{
		for(int i=0;i<c;i++)
		{
			if(maze[0][i]=='.')
			{
				opcount++;
				mr=0;
				mc=i;
			}
		}
		if(opcount!=2)
			return false;
		else 
			return true;
	}
	if(c==1)
	{
		for(int i=0;i<r;i++)
		{
			if(maze[i][0]=='.')
			{
				opcount++;
				mr=i;
				mc=0;
			}
		}
		if(opcount!=2)
			return false;
		else 
			return true;
	}
	if(maze[0][0]=='.')
	{
		opcount++;
		mr=0;
		mc=0;
	}
	if(maze[r-1][c-1]=='.')
	{
		opcount++;
		mr=r-1;
		mc=c-1;
	}
	if(maze[0][c-1]=='.')
	{
		opcount++;
		mr=0;
		mc=c-1;
	}
	if(maze[r-1][0]=='.')
	{
		opcount++;
		mr=r-1;
		mc=0;
	}
	if(opcount>2)
		return false;
	for(int i=1;i<c-1;i++)
	{
		if(maze[0][i]=='.')
		{
			opcount++;
			mr=0;
			mc=i;
		}
	}
	if(opcount>2)
		return false;
	for(int i=1;i<c-1;i++)
	{
		if(maze[r-1][i]=='.')
		{
			opcount++;
			mr=r-1;
			mc=i;
		}
	}
	if(opcount>2)
		return false;
	for(int i=1;i<r-1;i++)
	{
		if(maze[i][0]=='.')
		{
			opcount++;
			mr=i;
			mc=0;
		}
	}
	if(opcount>2)
		return false;
	for(int i=1;i<r-1;i++)
	{
		if(maze[i][c-1]=='.')
		{
			opcount++;
			mr=i;
			mc=c-1;
		}
	}
	if(opcount!=2)
		return false;
	return true;
}
int main()
{
	int test;
	cin>>test;
	//ofstream out("maze.txt");
	for(int t=1;t<=test;t++)
	{
		int r,c;
		cin>>r>>c;
		vector<vector<char> > maze(r,vector<char>(c));
		for(int i=0;i<r;i++)
		{
			for(int j=0;j<c;j++)
			{
				cin>>maze[i][j];
			}
		}
		int mr,mc;
		if(!findopening(maze,mr,mc,r,c))
		{
			cout<<"invalid";	
			//cout<<"here";
		}
		else
		{
			queue<pair<int,int> > q;
			q.push(pair<int,int>(mr,mc));
			bool first=false;
			while(!q.empty())
			{
				//cout<<"here";
				mr=q.front().first;
				mc=q.front().second;
				if(first)
				{
					if(mr==0 || mr==r-1 || mc==0 || mc==c-1)
					{
						cout<<"valid";
						break;
					}
				}
				else
				{
					first=true;
				}
				maze[mr][mc]='#';
				//cout<<mr<<" "<<mc;
				q.pop();
				if(mr-1>=0 && maze[mr-1][mc]=='.')
				{
					q.push(pair<int,int>(mr-1,mc));
				}
				if(mr+1<r && maze[mr+1][mc]=='.')
				{
					q.push(pair<int,int>(mr+1,mc));
				}
				if(mc-1>=0 && maze[mr][mc-1]=='.')
				{
					q.push(pair<int,int>(mr,mc-1));
				}
				if(mc+1<c && maze[mr][mc+1]=='.')
				{
					q.push(pair<int,int>(mr,mc+1));
				}
			}
			if(q.empty())
				cout<<"invalid";	
		}
		cout<<endl;
	}
	//out.close();
	//system("maze.txt");
	return 0;
}
