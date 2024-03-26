//memoization
//https://bit.ly/3HcTJdy
int f(vector<vector<int>> &dp, string &s1, string &s2, int i, int j) {
  if (i <= 0)
    return j;
  if (j <= 0)
    return i;
  if (dp[i][j] != -1)
    return dp[i][j];
  if (s1[i - 1] == s2[j - 1]) {
    return dp[i][j] = f(dp, s1, s2, i - 1, j - 1);
  }
  return dp[i][j] =
             1 + min(f(dp, s1, s2, i - 1, j - 1),
                     min(f(dp, s1, s2, i, j - 1), f(dp, s1, s2, i - 1, j)));
}

int editDistance(string str1, string str2) {
  int n = str1.size(), m = str2.size();
  vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
  return f(dp, str1, str2, n, m);
}


//tabulation

int editDistance(string &str1, string &str2) {
  int n = str1.size(), m = str2.size();
  vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
  for(int i=0;i<=n;i++)dp[i][0]=i;
  for(int i=0;i<=m;i++)dp[0][i]=i;
  for(int i=1;i<=n;i++){
      for(int j=1;j<=m;j++){
          if(str1[i-1]==str2[j-1]){
              dp[i][j]=dp[i-1][j-1];
          }
          else{
              dp[i][j]=1+min(dp[i][j-1],min(dp[i-1][j],dp[i-1][j-1]));
          }
      }
  }
  return dp[n][m];
}

//space optimization

int editDistance(string &str1, string &str2) {
  int n = str1.size(), m = str2.size();
  vector<int> dp(m + 1, 0);
  for (int i = 0; i <= m; i++)
    dp[i] = i;
  for (int i = 1; i <= n; i++) {
    vector<int> temp(m + 1, 0);
    temp[0] = i;
    for (int j = 1; j <= m; j++) {
      if (str1[i - 1] == str2[j - 1]) {
        temp[j] = dp[j - 1];
      } else {
        temp[j] = 1 + min(temp[j - 1], min(dp[j], dp[j - 1]));
      }
    }
    dp=temp;
  }
  return dp[m];
}
