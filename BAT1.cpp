#include <iostream>
using namespace std;


int main () {
  int t;
  int n, m, k;
  int ans;
  int o_cost[21];
  int cost[21][21];
  int rating[21][21];
  int dp[21][21][1001];
  cin >> t;
  while(t--) {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
      cin >> o_cost[i];
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++)
        cin >> cost[i][j];
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++)
        cin >> rating[i][j];

    for (int i = 1; i <= n; i++)
      for (int j = 0; j <= m; j++)
        for (int h = 0; h <= k; h++) {
          if (j == 0) {
            if (i == 1)
              dp[i][j][h] = 0;
            else {
              dp[i][j][h] = dp[i-1][j][h];
              if (h >= o_cost[i-1])
                dp[i][j][h] = max (dp[i][j][h], dp[i-1][m][h-o_cost[i-1]]);
            }
          }
          else {
            dp[i][j][h] = dp[i][j-1][h];
            int x = 0;
            while (true) {
              x++;
              if (h >= x * cost[i][j])
                dp[i][j][h] = max(dp[i][j][h], x * rating[i][j] + dp[i][j-1][h-x * cost[i][j]]);
              else
                break;
            }
          }
        }
    ans = 0;
    if (k >= o_cost[n])
      ans = max(ans, dp[n][m][k-o_cost[n]]);
    ans = max(ans, dp[n][0][k]);
    cout << ans << "\n";
  }
}

