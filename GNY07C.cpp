#include<bits/stdc++.h>
using namespace std;
string ascii[]={
	"00000",
	"00001",
	"00010",
	"00011",
	"00100",
	"00101",
	"00110",
	"00111",
	"01000",
	"01001",
	"01010",
	"01011",
	"01100",
	"01101",
	"01110",
	"01111",
	"10000",
	"10001",
	"10010",
	"10011",
	"10100",
	"10101",
	"10110",
	"10111",
	"11000",
	"11001",
	"11010",
};
void spiral(int m,int n,int &len,vector<vector<char> > &arr,string pass)
{
	int k=0;
	int l=0;
	int ll=0;
	int i;
	while (k < m && l < n)
    {
        for (i = l; i < n; ++i)
        {
		  	arr[k][i]=(ll<len)?pass[ll++]:'0';
        }
        k++;
 
        /* Print the last column f1rom the remaining columns */
        for (i = k; i < m; ++i)
        {
            arr[i][n-1]=(ll<len)?pass[ll++]:'0';
        }
        n--;
 
        /* Print the last row from the remaining rows */
        if ( k < m)
        {
            for (i = n-1; i >= l; --i)
            {
                arr[m-1][i]=(ll<len)?pass[ll++]:'0';
            }
            m--;
        }
 
        /* Print the first column from the remaining columns */
        if (l < n)
        {
            for (i = m-1; i >= k; --i)
            {
                arr[i][l]=(ll<len)?pass[ll++]:'0';
            }
            l++;    
        }        
    }
}
int main()
{
	int t;
	scanf("%d",&t);
	for(int test=1;test<=t;test++)
	{
		int r,c;
		scanf("%d%d",&r,&c);
		char str[1000000];
		scanf("%[^\n]s",str);   
		vector<vector<char> > arr(r,vector<char>(c,'0'));
		string pass="";
		int i=1;
		while(str[i]!='\0')
		{
			if(str[i]==' ')
				pass+=ascii[0];
			else
				pass+=ascii[str[i]-'A'+1];
			i++;
		}
		int len=pass.length();
		spiral(r,c,len,arr,pass);
		string result;
		for(int i=0;i<r;i++)
		{
			for(int j=0;j<c;j++)
			{
				result.push_back(arr[i][j]);
			}
		}
		cout<<test<<" "<<result<<endl;
	}
	return 0;
}
