#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		char arr[100001];
		scanf("%s",arr);
		int i=0,j=strlen(arr)-1;
		bool pali=true;
		while(i<=j)
		{
			if(arr[i]==arr[j])
			{
				i++;
				j--;
			}
			else
			{
				pali=false;
				break;
			}
		}
		pali?printf("YES\n"):printf("NO\n");
	}
	return 0;
}
