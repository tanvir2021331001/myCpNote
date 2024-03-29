//https://bit.ly/3rWLMnC
//memoization

int parts(vector<vector<int>> &dp, vector<int> &cuts, int i, int j) {
  if (i > j)
    return 0;
  if (dp[i][j] != -1)
    return dp[i][j];
  int cost = 1e9;
  for (int k = i; k <= j; k++) {
    cost = min(cost, cuts[j + 1] - cuts[i - 1] + parts(dp, cuts, i, k - 1) +
                         parts(dp, cuts, k + 1, j));
  }
  return dp[i][j] = cost;
}
int cost(int n, int c, vector<int> &cuts) {
  cuts.push_back(0);
  cuts.push_back(n);
  sort(cuts.begin(), cuts.end());

  vector<vector<int>> dp(c + 1, vector<int>(c + 1, -1));

  return parts(dp, cuts, 1, c);
}


//tabulation
int cost(int n, int c, vector<int> &cuts) {
  cuts.push_back(0);
  cuts.push_back(n);
  sort(cuts.begin(), cuts.end());
  vector<vector<int>> dp(c + 2, vector<int>(c + 2, 0));
  for (int i = c; i >= 1; i--) {
    for (int j = i; j <= c; j++) {
      int cost = 1e9;
      for (int k = i; k <= j; k++) {
        cost =
            min(cost, cuts[j + 1] - cuts[i - 1] + dp[i][k - 1] + dp[k + 1][j]);
      }
      dp[i][j] = cost;
    }
  }

  return dp[1][c];
}
