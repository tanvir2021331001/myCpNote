// https://bit.ly/3rLHkqQ
//memoization
int f(vector<vector<vector<int>>> &dp, vector<int> &prices, int n, int ind,
      int buy, int cap) {
  if (ind == n || cap == 0)
    return 0;
  if (dp[ind][buy][cap] != -1)
    return dp[ind][buy][cap];
  if (buy) {
    return dp[ind][buy][cap] =
               max(-prices[ind] + f(dp, prices, n, ind + 1, 0, cap),
                   f(dp, prices, n, ind + 1, 1, cap));
  } else {
    return dp[ind][buy][cap] =
               max(prices[ind] + f(dp, prices, n, ind + 1, 1, cap - 1),
                   f(dp, prices, n, ind + 1, 0, cap));
  }
}
int maxProfit(vector<int> &prices) {
  int n = prices.size();
  vector<vector<vector<int>>> dp(n + 1,
                                 vector<vector<int>>(2, vector<int>(3, -1)));
  return f(dp, prices, n, 0, 1, 2);
}
//tabulation

int maxProfit(vector<int> &prices) {
  int n = prices.size();
  vector<vector<vector<int>>> dp(n + 1,
                                 vector<vector<int>>(2, vector<int>(3, 0)));

  for (int i = n - 1; i >= 0; i--) {
    for (int buy = 0; buy <= 1; buy++) {
      for (int cap = 1; cap <= 2; cap++) {
        if (buy) {
          dp[i][buy][cap] =
              max(-prices[i] + dp[i + 1][0][cap], dp[i + 1][1][cap]);
        } else {
          dp[i][buy][cap] =
              max(prices[i] + dp[i + 1][1][cap - 1], dp[i + 1][0][cap]);
        }
      }
    }
  }
  return dp[0][1][2];
}

//space optimization

int maxProfit(vector<int> &prices) {
  int n = prices.size();
  vector<vector<int>>dp(2,vector<int>(3,0)),temp(2,vector<int>(3,0));

  for (int i = n - 1; i >= 0; i--) {
    for (int buy = 0; buy <= 1; buy++) {
      for (int cap = 1; cap <= 2; cap++) {
        if (buy) {
          temp[buy][cap] =
              max(-prices[i] + dp[0][cap], dp[1][cap]);
        } else {
          temp[buy][cap] =
              max(prices[i] + dp[1][cap - 1], dp[0][cap]);
        }
      }
    }
    dp=temp;
  }
  return dp[1][2];
}
