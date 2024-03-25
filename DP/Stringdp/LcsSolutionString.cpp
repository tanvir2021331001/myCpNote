
/*
NOTE: 
IF It is called for the Longest palindromic subsequence  for string str
   then 
 LCS between str and reverse str will be the Longest palindromic subsequence
*/



#include <vector>
int lcs(string s, string t) {
  int n = s.size(), m = t.size();
  vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (s[i - 1] == t[j - 1])
        dp[i][j] = 1 + dp[i - 1][j - 1];
      else {
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
  }
  int i = n, j = m;
  string cs = "";
  while (i > 0 && j > 0) {
    if (s[i - 1] == t[j - 1]) {
      cs = s[i - 1] + cs;
      i--;
      j--;
    } else if (dp[i][j] == dp[i - 1][j]) {
      i--;
    } else
      j--;
  }
  cout << cs << "\n";
  return dp[n][m];
}
