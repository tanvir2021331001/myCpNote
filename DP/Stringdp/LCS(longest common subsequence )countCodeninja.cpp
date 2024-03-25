//memoizaton
//https://bit.ly/3pvkqUd
/*
NOTE: 
IF It is called for the Longest palindromic subsequence  for string str
   then 
 LCS between str and reverse str will be the Longest palindromic subsequence
*/





int f(vector<vector<int>> &dp, string &s, string &t, int n, int m) {
  if (n == 0 || m == 0)
    return 0;
  if (dp[n][m] != -1) {
    return dp[n][m];
  }
  if (s[n - 1] == t[m - 1]) {
    return dp[n][m] = 1 + f(dp, s, t, n - 1, m - 1);
  }
  return dp[n][m] = max(f(dp, s, t, n - 1, m), f(dp, s, t, n, m - 1));
}
int lcs(string s, string t) {
  int n = s.size(), m = t.size();
  vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

  return f(dp, s, t, n, m);
}
//tabulation
#include <vector>
int lcs(string s, string t) {
  int n = s.size(), m = t.size();
  vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
  for (int i = 1; i <=n; i++) {
    for (int j = 1; j <=m; j++) {
      if (s[i-1] == t[j-1])
        dp[i][j] = 1 + dp[i - 1][j - 1];
      else {
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
  }
  return dp[n][m];
}

//space optimization
#include <vector>
int lcs(string s, string t) {
  int n = s.size(), m = t.size();
  vector<int> dp(m + 1, 0);
  for (int i = 1; i <= n; i++) {
    vector<int> temp(m + 1, 0);
    for (int j = 1; j <= m; j++) {
      if (s[i - 1] == t[j - 1])
        temp[j] = 1 + dp[j - 1];
      else {
        temp[j] = max(temp[j - 1], dp[j]);
      }
    }
    dp = temp;
  }
  return dp[m];
}
