#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	char s[n];
	scanf("%s",s);
	char s1[n];
	strcpy(s1,s);
//	cout<<s<<" "<<s1<<endl;
	int lcs[2][n+1];
	int bi;
	for(int i=0;i<=n;i++)
	{
		bi=i&1;
		for(int j=n;j>=0;j--)
		{
			if(i==0 || j==n)
			{
				lcs[bi][j]=0;
			}
			else if(s[i-1]==s1[j])
				lcs[bi][j]=lcs[1-bi][j+1]+1;
			else
				lcs[bi][j]=max(lcs[1-bi][j],lcs[bi][j+1]);
		}
	}
	printf("%d",n-lcs[bi][0]);
	return 0;
}
