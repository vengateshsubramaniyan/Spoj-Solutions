#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	while(n)
	{
		int discoverd;
		bool reach;
		vector<int> arr(n);
		for(int i=0;i<n;i++)
		{
			scanf("%d",&arr[i]);
		}
		sort(arr.begin(),arr.end());
		if(arr[0]!=0)
		{
			printf("IMPOSSIBLE\n");
		}
		else
		{
			reach=true;
			discoverd=200;
			for(int i=1;i<n && reach;i++)
			{
				if(discoverd>=arr[i])
				{
					discoverd=arr[i]+200;
				}
				else
				{
					reach=false;
				}
			}
			if(reach)
			{
				int rem;
				if(discoverd>=1422)
				{
					rem=discoverd-1422;
					if(1422-rem<=arr[n-1])
					{
						rem=arr[n-1];
					}
					else
					{
						reach=false;
					}
					for(int i=n-2;i>0 && reach;i--)
					{
						if(rem-200<=arr[i])
							rem=arr[i];
						else
							reach=false;
					}
					reach?printf("POSSIBLE\n"):printf("IMPOSSIBLE\n");	
				}
				else
				{
					printf("IMPOSSIBLE\n");	
				}
			}
			else
			{
				int rem;
				if(discoverd>=1422)
				{
					
				}
				printf("IMPOSSIBLE\n");
			}
		}
		scanf("%d",&n);
	}
	return 0;
}
