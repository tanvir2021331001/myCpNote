//memoization
// https://bit.ly/3nXqfce



int mcm(int i, int j, vector<vector<int>> &dp, vector<int> &arr) {
  if (i == j)
    return 0;
  if (dp[i][j] != -1)
    return dp[i][j];
  int cost = 1e9;
  for (int k = i; k < j; k++) {
    cost = min(cost, arr[i - 1] * arr[k] * arr[j] + mcm(i, k, dp, arr) +
                         mcm(k + 1, j, dp, arr));
  }
  return dp[i][j] = cost;
}
int matrixMultiplication(vector<int> &arr, int N) {
  vector<vector<int>> dp(N + 1, vector<int>(N + 1, -1));
  return mcm(1, N - 1, dp, arr);
}



//tabulation
int matrixMultiplication(vector<int> &arr, int N) {
  vector<vector<int>> dp(N + 1, vector<int>(N + 1, 0));
  for(int i=N-1;i>0;i--){
      for(int j=i+1;j<N;j++){
          int cost=1e9;
          for(int k=i;k<j;k++){
            cost=min(cost,arr[i-1]*arr[k]*arr[j]+dp[i][k]+dp[k+1][j]);
          }
          dp[i][j]=cost;
      }
  }
  return dp[1][N-1];
}



//Space Optimization with dp[n] may not posible(i can't find it) //BUT  can be optimize by dp[N*N] array

