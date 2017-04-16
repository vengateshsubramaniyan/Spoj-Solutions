#include<bits/stdc++.h>
using namespace std;
int main()
{
	vector< bool > arr(10000,false);
	int n,val,m;
	int result=0;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d",&val);
		if(arr[val])
			result--;
		arr[val]=true;
		scanf("%d",&m);
		while(m--)
		{
			scanf("%d",&val);
			if(arr[val]==false)
			{
				result++;
				arr[val]=true;
			}
		}
	}
	printf("%d",result);
	return 0;
}
