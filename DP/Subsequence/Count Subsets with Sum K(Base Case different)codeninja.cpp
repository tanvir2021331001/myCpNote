//memoization
long long  mod = 1e9 + 7;
// https://bit.ly/3B5JBkU
long long  f(vector<vector<int>> &dp, vector<int> &arr, int n, int tar) {
 
  if (n == 0){
     if(tar==0&&arr[n]==0)return 2;
     else if (tar == 0)  return 1;
    return tar==arr[n];
  }
  if (dp[n][tar] != -1)
    return dp[n][tar] % mod;
 long long  nottake = f(dp, arr, n - 1, tar) % mod;
long long  take = 0;
  if (tar >= arr[n])
    take = f(dp, arr, n - 1, tar - arr[n]) % mod;
  dp[n][tar] =
            (nottake % mod +take % mod) %
             mod;
    return dp[n][tar];
}
int findWays(vector<int> &arr, int k) {
  int n = arr.size();
  vector<vector<int>> dp(n, vector<int>(k + 1, -1));
  return f(dp, arr, n - 1, k) % mod;
}


//tabulation

int mod = 1e9 + 7;

int findWays(vector<int> &arr, int k) {
  int n = arr.size();
  vector<vector<int>> dp(n, vector<int>(k + 1, 0));
dp[0][0]=1;
if (arr[0] <= k) {
  dp[0][arr[0]] = 1;
  if(arr[0]==0)dp[0][arr[0]]=2;
}

  for (int i = 1; i < n; i++) {
 
    for (int j = 0; j <= k; j++) {
      int d1 = dp[i - 1][j]%mod;
      int d2 = 0;
      if (j - arr[i] >= 0)
        d2 = dp[i - 1][j - arr[i]]%mod;
      dp[i][j] = (dp[i][j]+d1 % mod + d2 % mod) % mod;
    }
  }

  return dp[n - 1][k]%mod;
}



//space optimization
int mod = 1e9 + 7;

int findWays(vector<int> &arr, int k) {
  int n = arr.size();
  vector<int> dp(k + 1, 0);
  dp[0] = 1;
  if (arr[0] <= k) {
    dp[arr[0]] = 1;
    if (arr[0] == 0)
      dp[arr[0]] = 2;
  }

  for (int i = 1; i < n; i++) {
    vector<int> temp(k + 1, 0);
    for (int j = 0; j <= k; j++) {
      int d1 = dp[j] % mod;
      int d2 = 0;
      if (j - arr[i] >= 0)
        d2 = dp[j - arr[i]] % mod;
      temp[j] = (temp[j] + d1 % mod + d2 % mod) % mod;
    }
    dp = temp;
  }

  return dp[k] % mod;
}
