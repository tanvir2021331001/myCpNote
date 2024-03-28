//for 10^5 optimized -by binary search
#include <bits/stdc++.h>
int longestIncreasingSubsequence(int arr[], int n) {
    vector<int>temp;
      vector<int>::iterator it;
      temp.push_back(arr[0]);
    for(int i=1;i<n;i++){
      if(temp.back()<arr[i]){
        temp.push_back(arr[i]);
      }
      else{
        int ind=lower_bound(temp.begin(),temp.end(),arr[i])-temp.begin();
        temp[ind]=arr[i];
      }
    }
    return temp.size();
}
//For 10^3 or same constrint for O(n^2) dp
//space optimization with solution


//memoization
#include<bits/stdc++.h>
int f(vector<vector<int>>&dp,int arr[],int n,int pi,int ind){
    if(ind==n||pi==n)return 0;
    if(dp[ind][pi+1]!=-1)return dp[ind][pi+1];
      int len=f(dp,arr,n,pi,ind+1);
    if(pi==-1||arr[pi]<arr[ind]){
      len=max(1+f(dp,arr,n,ind,ind+1),len);
    }
    return dp[ind][pi+1]=len;
}
int longestIncreasingSubsequence(int arr[], int n)
{
    vector<vector<int>>dp(n+1,vector<int>(n+2,-1));
   int r=f(dp,arr,n,-1,0);
   return r;
}
//tabulation
#include <bits/stdc++.h>
int f(vector<vector<int>> &dp, int arr[], int n, int pi, int ind) {
  if (ind == n || pi == n)
    return 0;
  if (dp[ind][pi + 1] != -1)
    return dp[ind][pi + 1];
  int len = f(dp, arr, n, pi, ind + 1);
  if (pi == -1 || arr[pi] < arr[ind]) {
    len = max(1 + f(dp, arr, n, ind, ind + 1), len);
  }
  return dp[ind][pi + 1] = len;
}
int longestIncreasingSubsequence(int arr[], int n) {
  vector<vector<int>> dp(n + 1, vector<int>(n + 2, 0));
  for (int i = n - 1; i >= 0; i--) {
    for (int pri = -1; pri <= i; pri++) {
      int len;
      len = dp[i + 1][pri + 1];
      if (pri == -1 || arr[pri] < arr[i])
        len = max(dp[i + 1][i + 1] + 1, len);
      dp[i][pri + 1] = len;
    }
  }
  return dp[0][0];
}
//space optimization
#include <bits/stdc++.h>
int f(vector<vector<int>> &dp, int arr[], int n, int pi, int ind) {
  if (ind == n || pi == n)
    return 0;
  if (dp[ind][pi + 1] != -1)
    return dp[ind][pi + 1];
  int len = f(dp, arr, n, pi, ind + 1);
  if (pi == -1 || arr[pi] < arr[ind]) {
    len = max(1 + f(dp, arr, n, ind, ind + 1), len);
  }
  return dp[ind][pi + 1] = len;
}
int longestIncreasingSubsequence(int arr[], int n) {
vector<int> dp(n + 1, 0),temp(n+1,0);
  for (int i = n - 1; i >= 0; i--) {
    for (int pri = -1; pri <= i; pri++) {
      int len;
      len = dp[pri + 1];
      if (pri == -1 || arr[pri] < arr[i])
        len = max(dp[i + 1] + 1, len);
      temp[pri + 1] = len;
    }
    dp=temp;
  }
  return dp[0];
}
//
