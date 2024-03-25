//tabulation and solution
//https://bit.ly/3H2M3KS
int lcs(string &str1, string &str2) {
  int n = str1.size(), m = str2.size();
  vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
  int ans = 0, subi = 0, subj = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (str1[i - 1] == str2[j - 1]) {
        dp[i][j] += dp[i - 1][j - 1] + 1;
        if (ans < dp[i][j]) {
          ans = dp[i][j];
          subi = i;
          subj = j;
        }
      }
    }
  }
  int i = subi, j = subj;
  string sub = "";
  while (i > 0 && j > 0 && dp[i][j] != 0) {
    sub = str1[i - 1] + sub;
    i--;
    j--;
  }
  cout << sub << "\n";
  return ans;
}
//space optimization not solution
int lcs(string &str1, string &str2){
    int n=str1.size(),m=str2.size();
    vector<int>dp(m+1,0);
    int ans=0;
    for(int i=1;i<=n;i++){
          vector<int>temp(m+1,0);
          for(int j=1;j<=m;j++){
               if(str1[i-1]==str2[j-1]){
                   temp[j]+=dp[j-1]+1;
                   ans=max(ans,temp[j]);
               }
          }
          dp=temp;
    }
return ans;
}
