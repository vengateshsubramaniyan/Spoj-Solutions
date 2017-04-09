#include<bits/stdc++.h>
using namespace std;
void find(char digits[],int n)
{
    long long unsigned int dp0 = 1;
    long long unsigned int dp1 = 1;
 
    for (int i = 2; i <= n; i++)
    {
        long long unsigned int dp2 = 0;
 
        if (digits[i-1] > '0')
            dp2 = dp1;
        if (digits[i-2] == '1' || (digits[i-2] == '2' && digits[i-1] < '7') )
            dp2 += dp0;
        dp0=dp1;
        dp1=dp2;
    }
	printf("%llu\n",dp1);
}
int main()
{
	char arr[50005];
	scanf("%[^\n]s",arr);
	int len=strlen(arr);
	bool first=false;
	while(len!=1 || arr[0]!='0')
	{
		find(arr,len);
		scanf("\n%[^\n]s",arr);
		len=strlen(arr);	
	}
	return 0;
}
