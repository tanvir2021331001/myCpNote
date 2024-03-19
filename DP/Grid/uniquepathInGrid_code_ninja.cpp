#include <bits/stdc++.h>
using namespace std;
// https://bit.ly/34uoYCG
#define int long long
int uniquepath(vector<vector<int> > &dp, int n, int m)
{
    if (n == 0 && m == 0)
    {
        return 1;
    }
    if (n < 0 || m < 0)
        return 0;
    if (dp[n][m] != -1)
        return dp[n][m];
    int up = uniquepath(dp, n - 1, m);
    int left = uniquepath(dp, n, m - 1);
    return dp[n][m] = up + left;
}
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int> > dp(n, vector<int>(m, -1));
    cout << uniquepath(dp, n - 1, m - 1) << "\n";
}
int32_t main()
{
    // int t;cin >> t;while (t--)
    solve();
    return 0;
}
//tabulation
int uniquePaths(int m, int n) {
  vector<vector<int>> dp(m, vector<int>(n, -1));
  for (int i = 0; i < m; i++) {

    for (int j = 0; j < n; j++) {
      if (i == 0 && j == 0)
        dp[i][j] = 1;
      else if (i == 0) {
        dp[i][j] = dp[i][j - 1];
      } else if (j == 0) {
        dp[i][j] = dp[i - 1][j];
      } else {
        dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
      }
    }
  }
  return dp[m - 1][n - 1];
}
//Space Optimization
int uniquePaths(int m, int n) {
  vector<int> keep(n + 1, 0);
  for (int i = 0; i < m; i++) {
    vector<int> temp(n + 1, 0);
    for (int j = 0; j < n; j++) {
      if (i == 0 && j == 0)
        temp[j] = 1;
      else if (i == 0) {
        temp[j] = temp[j - 1];
      } else if (j == 0) {
        temp[j] = keep[j];
      } else {
        temp[j] = keep[j] + temp[j - 1];
      }
    }
    keep = temp;
  }
  return keep[n - 1];
}
