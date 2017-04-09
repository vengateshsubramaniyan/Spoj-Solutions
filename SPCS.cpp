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
		int len=strlen(arr);
		bool pali=true;
		int i=0,j=len-1;
		while(i<j)
		{
			if(arr[i]==arr[j])
			{
				i++;
				j--;
			}
			else 
			{
				int pi=i,pj=j;
				while(i!=0 && arr[i]==arr[i-1] && i+1<=j)
					i++;
				if(arr[i]==arr[j])
				{
					i++,j--;
				}
				else
				{
					while(j+1!=len && arr[j]==arr[j+1] && j-1>=i)
					j--;
					if(arr[pi]==arr[j])
					{
						i=pi+1;
						j--;
					}
					else
					{
						if(arr[i]==arr[j])
						{
							i++;
							j--;
						}
					}
				}
				if(pi==i && pj==j)
				{
					pali=false;
					break;
				}
			}
		}
		pali?printf("YES\n"):printf("NO\n");
	}
	return 0;
}
