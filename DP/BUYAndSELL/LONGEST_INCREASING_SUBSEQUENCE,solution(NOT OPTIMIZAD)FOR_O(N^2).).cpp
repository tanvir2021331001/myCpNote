//space optimization
#include <bits/stdc++.h>
//https://bit.ly/3rVoIoq
int longestIncreasingSubsequence(int arr[], int n) {
  vector<int> dp(n + 1, 1), hash(n + 1, 0);
  for (int i = 0; i <= n; i++)
    hash[i] = i;
  int maxi = 0, lstind = 0;
  for (int i = 0; i < n; i++) {
    for (int prev = 0; prev < i; prev++) {
      if (arr[i] > arr[prev]) {
        dp[i] = max(dp[prev] + 1, dp[i]);
      }
      if (dp[i] > maxi) {
        lstind = i;
        hash[lstind] = prev;
        maxi = max(dp[i], maxi);
      }
    }
  }
  vector<int> lis;
  lis.push_back(arr[lstind]);
  while (hash[lstind] != lstind&&maxi>1) {
    lstind = hash[lstind];
    lis.push_back(arr[lstind]);
  }
  reverse(lis.begin(), lis.end());
  for (int i = 0; i < lis.size(); i++)
    cout << lis[i] << " ";
  cout << "\n";
  return maxi;
}
