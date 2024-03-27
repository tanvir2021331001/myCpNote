// https://bit.ly/3nYO17H
//memoization
#include <vector>
long f(vector<vector<long>> &dp, long val[], long n, long buy, int ind) {
  if (ind >= n) {
    return 0;
  }
  if (dp[ind][buy] != -1)
    return dp[ind][buy];
  if (buy) {
    return dp[ind][buy] = max(val[ind] + f(dp, val, n, 0, ind + 1),
                              f(dp, val, n, 1, ind + 1));
  } else {
    return dp[ind][buy] = max(-val[ind] + f(dp, val, n, 1, ind + 1),
                              f(dp, val, n, 0, ind + 1));
  }
}

long getMaximumProfit(long *values, int n) {
  vector<vector<long>> dp(n + 1, vector<long>(2, -1));
  return f(dp, values, n, 0, 0);
}
//tabulation
long getMaximumProfit(long *values, int n) {
  vector<vector<long>> dp(n + 1, vector<long>(2, 0));
  for(int i=n-1;i>=0;i--){
      for(int j=1;j>=0;j--){
         if(j) dp[i][j]=max(values[i]+dp[i+1][0],dp[i+1][1]);
         else dp[i][j]=max(-values[i]+dp[i+1][1],dp[i+1][0]);
      }
  }
  return dp[0][0];
}
//space optimization

long getMaximumProfit(long *values, int n) {

  vector<long> dp(2, 0);
  for (int i = n - 1; i >= 0; i--) {
    vector<long> temp(2, 0);
    for (int j = 1; j >= 0; j--) {
      if (j)
        temp[j] = max(values[i] + dp[0], dp[1]);
      else
        temp[j] = max(-values[i] + dp[1], dp[0]);
    }
    dp = temp;
  }
  return dp[0];
}
