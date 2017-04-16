#include<bits/stdc++.h>
#define ll long long unsigned 
#define ld long double
#define pi pair<int,int>
#define pll pair<ll,ll>
#define vl vector< ll >
#define bug(a) cout<<a<<endl;
#define bug2(a,b) cout<<a<<" "<<b<<endl;
#define bug3(a,b,c) cout<<a<<" "<<b<<" "<<c<<endl;
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		if(6%n==0)
		{
			printf("6\n");
			continue;
		}
		if(8%n==0)
		{
			printf("8\n");
			continue;
		}
		queue< pair< string ,pi > > q;
		q.push(pair< string , pi >("6",pi(1,6)));
		q.push(pair< string , pi >("8",pi(1,8)));
		bool res=true;
		while(!q.empty())
		{
			string s=q.front().first;
			int len=q.front().second.first;
			int rem=q.front().second.second;
			q.pop();
			if(len==200)
			{
				printf("-1\n");
				break;	
			}
			int temp;
			temp=((rem*10)+6)%n;
			if(temp==0)
			{
				s=s+'6';
				cout<<s<<endl;
				break;
			}
			q.push(pair<string,pi>(s+'6',pi(len+1,temp)));
			if(s[len-1]=='8')
			{
				temp=((rem*10)+8)%n;
				if(temp==0)
				{
					s=s+'8';
					cout<<s<<endl;
					break;
				}
				q.push(pair<string,pi>(s+'8',pi(len+1,temp)));
			}
		}
	}
	return 0;
}
