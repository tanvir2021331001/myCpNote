#include <bits/stdc++.h>
//https://bit.ly/3vEYKce
string shortestSupersequence(string a, string b) {
  int n = a.size(), m = b.size();
  vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (a[i - 1] == b[j - 1]) {
        dp[i][j] = 1 + dp[i - 1][j - 1];
      } else {
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
  }
  int i = n, j = m;
  string ans = "";
  while (i > 0 && j > 0) {
    if (a[i - 1] == b[j - 1]) {
      ans = a[i - 1] + ans;
      i--;
      j--;
    } else if (dp[i - 1][j] == dp[i][j]) {
      ans = a[i - 1] + ans;
      i--;
    } else {
      ans = b[j - 1] + ans;
      j--;
    }
  }
  while (i > 0) {
    ans = a[i - 1] + ans;
    i--;
  }
  while (j > 0) {
    ans = b[j - 1] + ans;
    j--;
  }
  return ans;
}
