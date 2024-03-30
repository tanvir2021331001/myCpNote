// https://bit.ly/3HJTeIl
//memoization


int f(vector<int> &dp, vector<int> &arr, int n, int k, int i) {
  if (n <= i)
    return 0;
  if (dp[i] != -1)
    return dp[i];
  int len = 0, mxe = 0, sum = 0;
  for (int j = i; j < min(i + k, n); j++) {
    len++;
    mxe = max(mxe, arr[j]);
    sum = max(sum, len * mxe + f(dp, arr, n, k, j + 1));
  }
  return dp[i] = sum;
}

int maximumSubarray(vector<int> &arr, int k) {
  int n = arr.size();
  vector<int> dp(n + 1, -1);
  return f(dp, arr, n, k, 0);
}


//tabulation


int maximumSubarray(vector<int> &arr, int k) {
  int n = arr.size();
  vector<int> dp(n + 1, 0);
  for (int i = n - 1; i >= 0; i--) {
    int len = 0, mxe = 0, sum = 0;
    for (int j = i; j < min(i + k, n); j++) {
      len++;
      mxe = max(mxe, arr[j]);
      sum = max(sum, len * mxe + dp[j + 1]);
    }
    dp[i] = sum;
  }
  return dp[0];
}
