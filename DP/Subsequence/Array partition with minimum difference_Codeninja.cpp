//sapce optimization
int minSubsetSumDifference(vector<int> &arr, int n) {
  int sum = 0;
  for (int i = 0; i < n; i++) {
    sum += arr[i];
  }
  int half = sum / 2 + 1;
  vector<bool> dp(half + 1, false);
  dp[0] = true;
  if (arr[0] <= half) {
    dp[arr[0]] = true;
  }

  for (int i = 1; i < n; i++) {
    vector<bool> temp(half + 1, false);
    temp[0] = true;
    for (int target = 1; target <= half; target++) {
      bool nott = dp[target], take = false;
      if (target >= arr[i] && arr[i] <= half) {
        take = dp[target - arr[i]];
      }
      temp[target] = (take | nott);
    }
    dp = temp;
  }

  int mndiff = 1e9;
  for (int i = 0; i <= half; i++) {

    if (dp[i])
      mndiff = min(mndiff, abs(i - (sum - i)));
  }
  return mndiff;
}
