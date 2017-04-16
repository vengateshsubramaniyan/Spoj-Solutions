#include<bits/stdc++.h>
#define ll long long
using namespace std;
void printKMax(ll arr[], ll n,ll k)
{
    deque<ll>  q(k);
 	ll i;
    for (i = 0; i < k; ++i)
    {
        while ( (!q.empty()) && arr[i] >= arr[q.back()])
            q.pop_back();
 		q.push_back(i);
    }
    for ( ; i < n; ++i)
    {
        cout << arr[q.front()] << " ";
        while ( (!q.empty()) && q.front() <= i - k)
            q.pop_front(); 
        while( (!q.empty()) && arr[i] >= arr[q.back()])
            q.pop_back();
        q.push_back(i);
    }
    cout << arr[q.front()];
}
int main()
{
	ll n,m;
	scanf("%lld",&n);
	ll arr[n];
	for(ll i=0;i<n;i++)
		scanf("%lld",&arr[i]);
	scanf("%lld",&m);
	printKMax(arr,n,m);
	return 0;
}
