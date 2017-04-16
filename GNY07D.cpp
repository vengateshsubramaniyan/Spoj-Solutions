#include<bits/stdc++.h>
using namespace std;
void spiral(int m,int n,vector<vector<char> > &arr,int pos)
{
	string result;
	int count=4;
	int val=0;
	int k=0,l=0,i;
	while (k < m && l < n)
    {
        for (i = l; i < n; ++i)
        {
			val+=(arr[k][i]=='0')?0:pow(2,count);
			count--;
			if(count==-1)
			{
				if(val==0)
					result.push_back(' ');
				else
					result.push_back('A'+val-1);
				val=0;
				count=4;  
			}
        }
        k++;
 
        /* Print the last column f1rom the remaining columns */
        for (i = k; i < m; ++i)
        {
            val+=(arr[i][n-1]=='0')?0:pow(2,count);
			count--;
			if(count==-1)
			{
				if(val==0)
					result.push_back(' ');
				else
					result.push_back('A'+val-1);
				val=0;
				count=4;  
			}
        }
        n--;
 
        /* Print the last row from the remaining rows */
        if ( k < m)
        {
            for (i = n-1; i >= l; --i)
            {
                val+=(arr[m-1][i]=='0')?0:pow(2,count);
                count--;
				if(count==-1)
				{
					if(val==0)
						result.push_back(' ');
					else
						result.push_back('A'+val-1);
					val=0;
					count=4;  
				}
            }
            m--;
        }
 
        /* Print the first column from the remaining columns */
        if (l < n)
        {
            for (i = m-1; i >= k; --i)
            {
                val+=(arr[i][l]=='0')?0:pow(2,count);
                count--;
				if(count==-1)
				{
					if(val==0)
						result.push_back(' ');
					else
						result.push_back('A'+val-1);
					val=0;
					count=4;  
				}
            }
            l++;    
        }        
    }
    cout<<pos<<" "<<result<<endl;
}
int main()
{
	int t;
	scanf("%d",&t);
	for(int test=1;test<=t;test++)
	{
		int r,c;
		scanf("%d%d",&r,&c);
		char dummy;
		scanf("%c",&dummy);
		vector<vector<char> > arr(r,vector<char>(c,'0'));
		for(int i=0;i<r;i++)
		{
			for(int j=0;j<c;j++)
			{
				scanf("%c",&arr[i][j]);
			}
		}
		spiral(r,c,arr,test);
	}
}
