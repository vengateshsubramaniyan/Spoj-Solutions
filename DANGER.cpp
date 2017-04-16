#include<bits/stdc++.h>
using namespace std;
int formnumber(char arr[])
{
	int x=arr[0]-'0',y=arr[1]-'0',z=arr[3]-'0';
	int n=(x*10)+y;
	n=n*(pow(10,z));
	return n;
}
int josephus(int n)
{
	int p=1;
	while(p<=n)
		p*=2;
	return 2*n-p+1;
}
int main()
{
	char arr[5];
	scanf("%s",arr);
	int n=formnumber(arr);
	while(n)
	{
		printf("%d\n",josephus(n));
		scanf("%s",arr);
		n=formnumber(arr);	
	}
	return 0;
}
