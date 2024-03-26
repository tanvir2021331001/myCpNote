//memoization
//https://bit.ly/3qXtORt
#include <vector>
bool f(vector<vector<int>> &dp, string &p, string &t, int i, int j) {
  if (i == 0 && j == 0)
    return true;
  if (i <= 0 && j > 0)
    return false;
  if (j == 0) {
    for (int ind = 0; ind < i; ind++) {
      if (p[ind] != '*')
        return false;
    }
    return dp[i][j] = true;
  }
  if (dp[i][j] != -1)
    return dp[i][j];
  if (p[i - 1] == t[j - 1] || p[i - 1] == '?')
    return dp[i][j] = f(dp, p, t, i - 1, j - 1);
  else if (p[i - 1] == '*')
    return dp[i][j] = (f(dp, p, t, i, j - 1) | f(dp, p, t, i - 1, j));
  else
    return dp[i][j] = false;
}
bool wildcardMatching(string pattern, string text) {
  int n = pattern.size(), m = text.size();
  vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
  return f(dp, pattern, text, n, m);
}


//tabulation
bool wildcardMatching(string pattern, string text) {
  int n = pattern.size(), m = text.size();
  vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
  dp[0][0] = true;
  bool flag = true;
  for (int i = 1; i <= n; i++) {
    if (flag && pattern[i - 1] == '*') {
      dp[i][0] = flag;
    } else {
      flag = false;
      dp[i][0] = flag;
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (pattern[i - 1] == text[j - 1] || pattern[i - 1] == '?') {
        dp[i][j] = dp[i - 1][j - 1];
      } else if (pattern[i - 1] == '*') {
        dp[i][j] = dp[i - 1][j] | dp[i][j - 1];
      } else {
        dp[i][j] = false;
      }
    }
  }
  return dp[n][m];
}


//space optimization

bool wildcardMatching(string pattern, string text) {
  int n = pattern.size(), m = text.size();
  vector<bool> dp(m + 1, false);
  dp[0] = true;
  for (int i = 1; i <= n; i++) {
    vector<bool> temp(m + 1, false);
    bool flag = true;
    for (int ind = 0; ind < i; ind++) {
      if (pattern[ind] != '*') {
        flag = false;
        break;
      }
    }
    temp[0] = flag;

    for (int j = 1; j <= m; j++) {
      if (pattern[i - 1] == text[j - 1] || pattern[i - 1] == '?') {
        temp[j] = dp[j - 1];
      } else if (pattern[i - 1] == '*') {
        temp[j] = dp[j] | temp[j - 1];
      } else {
        temp[j] = false;
      }
    }
    dp = temp;
  }
  return dp[m];
}
