#include<bits/stdc++.h>
using namespace std;
void right(vector<string> &arr,vector< vector<int> > &re,int i,int c)
{
	for(int j=0;j<c;j++)
	{
		int pre=-1,down=-1;
		if(i!=0)
			down=re[i-1][j];
		if(j!=0)
			pre=re[i][j-1];
		if(i==0 && j==0)
		{
			pre=0;
			down=0;
		}
		if(pre==-1 && down==-1)
			re[i][j]=-1;
		else if(arr[i][j]=='#')
			re[i][j]=-1;
		else
		{
			re[i][j]=(arr[i][j]=='T')?1:0;
			re[i][j]+=max(pre,down);
		}
	}
}
void left(vector<string> &arr,vector< vector<int> > &re,int i,int c)
{
	for(int j=c-1;j>=0;j--)
	{
		int pre=-1,down=-1;
		if(i!=0)
			down=re[i-1][j];
		if(j+1!=c)
			pre=re[i][j+1];
		if(pre==-1 && down==-1)
			re[i][j]=-1;
		else if(arr[i][j]=='#')
			re[i][j]=-1;
		else
		{
			re[i][j]=(arr[i][j]=='T')?1:0;
			re[i][j]+=max(pre,down);
		}
	}
}
int main()
{
	int t;  
	scanf("%d",&t);
	while(t--)
	{
		int r,c;
		scanf("%d%d",&r,&c);
		vector< string > arr(r);
		vector< vector<int> > re(r,vector<int>(c));
		for(int i=0;i<r;i++)
			cin>>arr[i];
		for(int i=0;i<r;i++)
		{
			if(i%2==0)
				right(arr,re,i,c);
			else
				left(arr,re,i,c);
		}
		int result=0;
		for(int i=0;i<r;i++)
			for(int j=0;j<c;j++)
				if(result<re[i][j])
					result=re[i][j];
		printf("%d",result);
		if(t!=0)
			printf("\n");
	}
	return 0;
}
