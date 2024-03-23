//memoization
//https://bit.ly/3ukNmRZ

#include <bits/stdc++.h> 
bool f(vector<vector<int>> &dp,vector<int> &arr,int n,int target){
    if(target==0)return true;
    if(n==0)return (target==arr[n]);
    if(dp[n][target]!=-1)return dp[n][target];
    bool nottake=f(dp,arr,n-1,target);
    bool take=false;
    if(target>=arr[n])take=f(dp,arr,n-1,target-arr[n]);
    return dp[n][target]=(take|nottake);
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<int>>dp(n,vector<int>(k+1,-1));
    return f(dp,arr,n-1,k);
}
//tabulation 
#include <bits/stdc++.h>

bool subsetSumToK(int n, int k, vector<int> &arr) {
  vector<vector<bool>> dp(n + 1, vector<bool>(k + 1, false));
  for (int i = 0; i <= n; i++) {
    dp[i][0] = true;
  }
  for (int i = 1; i <= n; i++) {
    for (int target = 1; target <= k; target++) {
      bool nottake = dp[i - 1][target];
      bool take = false;
      if (arr[i - 1] <= target) {
        take = dp[i - 1][target - arr[i - 1]];
      }
      dp[i][target] = (take | nottake);
      if(dp[i][k])return true;
    }
  }

  return dp[n][k];
}

//space optimization
#include <bits/stdc++.h>

bool subsetSumToK(int n, int k, vector<int> &arr) {
  vector<bool> dp(k + 1, false);
  dp[0] = true;
  for (int i = 1; i <= n; i++) {
    vector<bool> temp(k + 1, false);
    temp[0] = true;
    for (int target = 1; target <= k; target++) {
      bool nottake = dp[target];
      bool take = false;
      if (arr[i - 1] <= target) {
        take = dp[target - arr[i - 1]];
      }
      temp[target] = (take | nottake);
      if (temp[k])
        return true;
    }
    dp = temp;
  }

  return dp[k];
}
