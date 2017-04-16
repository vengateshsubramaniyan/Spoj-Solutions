#include <bits/stdc++.h>
using namespace std;
int binsearch (int * a, int sum, int left, int right) {
  if (left > right)
    return -1; 
  if (left == right) {
    if (sum >= a[left])
      return left;
    return -1; 
  }

  int mid = (left + right) / 2;
  if (a[mid] > sum)
    return binsearch(a, sum, left, mid-1);
  else if (a[mid] <= sum) {
    if (a[mid+1] > sum)
      return mid;
    return binsearch(a, sum, mid + 1, right);
  }
}

int main () {
  int n;
  int index;
  int ans;
  int sticks[2000];
  while (true) {
    cin>>n;
    if (n == 0)
      break;
    for (int i = 0; i < n; i++)
      cin>>sticks[i];

    ans = 0;
    sort(sticks,sticks+n);
    for (int i = 0; i < n-2; i++)
      for (int j = i+1; j < n-1; j++) {
        index = binsearch (sticks, sticks[i] + sticks[j], j+1, n-1);
        if (index != -1)
          ans += (n-1-index);
        else
          ans += (n-1-j);
      }
    cout<<ans<<endl;
  }

}
