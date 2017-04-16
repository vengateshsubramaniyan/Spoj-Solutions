#include<bits/stdc++.h>
using namespace std;
void find(bool arr[],int start)
{
	int digit=0;
	int temp=start;
	while(temp)
	{
		digit+=temp%10;
		temp/=10;
	}
	start+=digit;
	if(start>=1000000)
		return;
	if(arr[start]==true)
		return;
	arr[start]=true;
	find(arr,start);
}
int main()
{
	bool *arr;
	arr=new bool[1000000];
	int start=1;
	for(;start<1000000;start++)
	{
		if(arr[start]==false)
		{
			printf("%d\n",start);
			find(arr,start);
		}
	}
}
