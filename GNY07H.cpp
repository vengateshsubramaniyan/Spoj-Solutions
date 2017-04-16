#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

long long int memo[100000];

long long int  solve(int a)
{   if(a<0) return 0;
    if(memo[a] != -1) return memo[a];
    else
        return memo[a]= solve(a-1)+ 5*solve(a-2) + solve(a-3) - solve(a-4);
}
int main()
{
    int x;
    scanf("%d",&x);

    memset(memo,-1,sizeof memo);
    memo[0]=1,memo[1]=5,memo[2]=11,memo[3]=36,memo[4]=95;
    int d=1;
    while(x--)
    {
        int n; scanf("%d",&n);
        printf("%d %lld\n",d++,solve(n-1));
    }
    return 0;
}
