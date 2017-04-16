#include<bits/stdc++.h>
using namespace std;
int main()
{
	bool arr[20005];
	memset(arr,false,sizeof(arr));
	int q;
	scanf("%d",&q);
	int re=0;
	while(q--)
	{
		int pos;
		scanf("%d",&pos);
		if(arr[pos-1]==false && arr[pos+1]==false)
			re++;
		else if(arr[pos-1]==true && arr[pos+1]==true)
			re--;
		arr[pos]=true;
		printf("%d\n",re);
	}
	printf("Justice\n");
	return 0;
}
