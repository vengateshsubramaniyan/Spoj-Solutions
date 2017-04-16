#include<bits/stdc++.h>
using namespace std;
struct cmpp
{
	bool operator()(pair< pair<int,int> , pair<int,int> > &a,pair< pair<int,int> , pair<int,int> > &b)
	{
		return a.first.first>b.first.first;
	}
};
int row[]={1,-1,0,0};
int col[]={0,0,1,-1};
bool pos(int a,int b)
{
	if(a==-1)
		return true;
	for(int i=0;i<4;i++)
	{
		if(!((a>>i)&1))
		{
			if((b>>i)&1)
				return true;
		}
	}
	return false;
}
int main()
{
	int r,c;
	scanf("%d%d",&r,&c);
	char s[101][101];
	int ascii[256];
	ascii['B']=0,ascii['Y']=1,ascii['G']=2,ascii['R']=3;
	ascii['b']=0,ascii['y']=1,ascii['g']=2,ascii['r']=3;
	int key[101][101];
	while(r && c)
	{
		memset(key,-1,sizeof(key));
		for(int i=0;i<r;i++)
			scanf("%s",s[i]);
		priority_queue< pair< pair<int,int> , pair<int,int> > , vector< pair< pair<int,int> , pair<int,int> > > ,cmpp > pq;
		for(int i=0;i<r;i++)
		{
			bool fo=true;
			for(int j=0;j<c;j++)
			{
				if(s[i][j]=='*')
				{
					pq.push(pair< pair<int,int> ,pair<int,int> >(pair<int,int>(0,0),pair<int,int>(i,j)));
					key[i][j]=0;
					fo=false;
					break;
				}
			}
			if(!fo)
				break;
		}
		int result=-1;
		while(!pq.empty())
		{
			int v=pq.top().first.first;
			int ak1=pq.top().first.second;
			int i=pq.top().second.first;
			int j=pq.top().second.second;
//9			cout<<i<<" "<<j<<endl;
			pq.pop();
			if(s[i][j]=='X')
			{
				result=v;
				break;
			}
			for(int k=0;k<4;k++)
			{
				int ak=ak1;
				int ci=i+row[k];
				int cj=j+col[k];
				if(ci>=0 && ci<r && cj>=0 && cj<c && s[ci][cj]!='#')
				{
					if(s[ci][cj]=='.' && pos(key[ci][cj],ak))
					{
						if(key[ci][cj]==-1)
							key[ci][cj]=ak;
						else
							key[ci][cj]|=ak;
						pq.push(pair< pair<int,int> ,pair<int,int> >(pair<int,int>(v+1,ak),pair<int,int>(ci,cj)));
					}
					if(s[ci][cj]=='X')
					{
						if(pos(key[ci][cj],ak))
						{
							if(key[ci][cj]==-1)
								key[ci][cj]=ak;
							else
								key[ci][cj]|=ak;
							pq.push(pair< pair<int,int> ,pair<int,int> >(pair<int,int>(v+1,ak),pair<int,int>(ci,cj)));
						}
					}
					if(s[ci][cj]>='a' && s[ci][cj]<='z')
					{
						ak|=1<<ascii[s[ci][cj]];
						if(pos(key[ci][cj],ak))
						{
							if(key[ci][cj]==-1)
								key[ci][cj]=ak;
							else
								key[ci][cj]|=ak;
							pq.push(pair< pair<int,int> ,pair<int,int> >(pair<int,int>(v+1,ak),pair<int,int>(ci,cj)));
						}
					}
					if(s[ci][cj]>='A' && s[ci][cj]<='Z')
					{
						if((ak>>ascii[s[ci][cj]])&1)
						{
							if(pos(key[ci][cj],ak))
							{
								if(key[ci][cj]==-1)
									key[ci][cj]=ak;
								else
									key[ci][cj]|=ak;
								pq.push(pair< pair<int,int> ,pair<int,int> >(pair<int,int>(v+1,ak),pair<int,int>(ci,cj)));	
							}
						}
					}
					if(s[ci][cj]=='*')
					{
						if(pos(key[ci][cj],ak))
						{
							if(key[ci][cj]==-1)
								key[ci][cj]=ak;
							else
								key[ci][cj]|=ak;
							pq.push(pair< pair<int,int> ,pair<int,int> >(pair<int,int>(v+1,ak),pair<int,int>(ci,cj)));
						}
					}
				}
			}
		}
/*		for(int i=0;i<r;i++)
		{
			for(int j=0;j<c;j++)
				cout<<key[i][j]<<" ";
			cout<<endl;
		}*/
		if(result==-1)
			printf("The poor student is trapped!\n");
		else
			printf("Escape possible in %d steps.\n",result);
		scanf("%d%d",&r,&c);
	}
	return 0;
}
