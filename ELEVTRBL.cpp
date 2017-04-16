#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	ll f,s,g,u,d;
	scanf("%lld%lld%lld%lld%lld",&f,&s,&g,&u,&d);
	queue< pair<ll,ll> > q;
	bool arr[1000005];
	memset(arr,false,f+1);
	arr[0]=true;
	q.push(pair<ll,ll>(s,0));
	ll result=-1;
	while(!q.empty())
	{
		ll floor=q.front().first;
		ll move=q.front().second;
		if(floor==g)
		{
			result=move;
			break;
		}
		q.pop();
		if(arr[floor])
			continue;
		if(floor+u<=f)
		{
			if(floor+u==g)
			{
				result=move+1;
				break;
			}
			else
				q.push(pair<ll,ll>(floor+u,move+1));
		}
		if(floor-d>0)
		{
			if(floor-d==g)
			{
				result=move+1;
				break;
			}
			else
			{
				q.push(pair<ll,ll>(floor-d,move+1));
			}
		}
		arr[floor]=true;
	}
	if(result==-1)
		printf("use the stairs");
	else
		printf("%lld",result);
	return 0;
}
