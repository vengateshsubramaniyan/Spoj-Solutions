#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	long long index=1;
	unordered_multimap<int,long long> arr;
	pair<unordered_multimap<int,long long>::iterator,unordered_multimap<int,long long>::iterator> paa;
	unordered_multimap<int,long long>::iterator it,temp;
	for(int i=0;i<n;i++)
	{
		int val;
		scanf("%d",&val);
		arr.insert(pair<int,long long>(val,index++));
	}
	while(m--)
	{
		char op;
		int val;
		scanf("\n%c %d",&op,&val);
		if(op=='S')
		{
			paa=arr.equal_range(val);
			it=paa.first;
			if(it==arr.end())
				printf("NONE\n");
			else
			{
			    temp=it;
			    it++;
			    while(it!=paa.second)
			    {
			        temp=it;
			        it++;
			    }
				printf("%d\n",temp->second);
			}
		}
		else if(op=='I')
		{
			arr.insert(pair<int,long long>(val,index));
			printf("%d\n",index++);
		}
		else
		{
			paa=arr.equal_range(val);
			it=paa.first;
			
			if(it==arr.end())
				printf("NONE\n");
			else
			{
			    
			    temp=it;
			    it++;
			    while(it!=paa.second)
			    {
			        temp=it;
			        it++;
			    }
				printf("%d\n",temp->second);
				arr.erase(temp);
			}
		}
	}
	return 0;
}
