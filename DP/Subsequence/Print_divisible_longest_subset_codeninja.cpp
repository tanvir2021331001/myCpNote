vector<int> divisibleSet(vector<int> &arr) {
  //https://bit.ly/3rON1Ef
  int n = arr.size();
  sort(arr.begin(), arr.end());
  vector<int> dp(n + 1, 1), hash(n + 1, 0), ans;
  for (int i = 0; i < n; i++)
    hash[i] = i;
  int maxi = -1, ind = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < i; j++) {
      if (arr[i] % arr[j] == 0 && 1 + dp[j] > dp[i]) {
        dp[i] = max(dp[j] + 1, dp[i]);
        hash[i] = j;
      }
      if (maxi < dp[i]) {
        ind = i;
        maxi = max(dp[i], maxi);
      }
    }
  }
  ans.push_back(arr[ind]);
  while (hash[ind] != ind) {
    ind = hash[ind];
    ans.push_back(arr[ind]);
  }
  reverse(ans.begin(), ans.end());

  return ans;
}
