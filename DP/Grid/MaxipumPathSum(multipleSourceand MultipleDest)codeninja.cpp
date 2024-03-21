//memoization 
#include <bits/stdc++.h> 
//https://bit.ly/3F436dK
int f(vector<vector<int>>&dp,vector<vector<int>>&matrix,int i,int j){
    if(i<0||j<0||j>=matrix[0].size()){
        return -1e9;
    }
    if(i==0){
      return matrix[i][j];
    }
    if(dp[i][j]!=-1)return dp[i][j];
    int up=matrix[i][j]+f(dp,matrix,i-1,j);
    int lup=matrix[i][j]+f(dp,matrix,i-1,j-1);
    int rup=matrix[i][j]+f(dp,matrix,i-1,j+1);
    return dp[i][j]=max(up,max(lup,rup));
}
int getMaxPathSum(vector<vector<int>> &matrix)
{
    int n=matrix.size();
    int m=matrix[0].size();
    vector<vector<int>>dp(n,vector<int>(m,-1));
    int mx=-1e9;
    for(int i=0;i<m;i++){
       mx=max(mx,f(dp,matrix,n-1,i));
    }
    return mx;
}
//tabulation
#include <bits/stdc++.h>
int getMaxPathSum(vector<vector<int>> &matrix) {
  int n = matrix.size();
  int m = matrix[0].size();
  vector<vector<int>> dp(n, vector<int>(m, -1));
  int mx = -1e9;
   for(int i=0;i<n;i++){
       for(int j=0;j<m;j++){
           if(i==0){
               dp[i][j]=matrix[i][j];
           }
           else{
               int down=matrix[i][j]+dp[i-1][j];
               int ld=-1e9;
               if(j-1>=0)ld =matrix[i][j]+dp[i-1][j-1];
               int rd=-1e9;
               if(j+1<m)rd=matrix[i][j]+dp[i-1][j+1];
               dp[i][j]=max(down,max(ld,rd));
           }
       }
   }
   for(int i=0;i<m;i++){
       mx=max(mx,dp[n-1][i]);
   }
  return mx;
}

//space optimization
#include <bits/stdc++.h>
int getMaxPathSum(vector<vector<int>> &matrix) {
  int n = matrix.size();
  int m = matrix[0].size();
  vector<int> k(m + 1, 0);
  int mx = -1e9;
  for (int i = 0; i < n; i++) {
    vector<int> temp(m + 1, 0);
    for (int j = 0; j < m; j++) {
      if (i == 0) {
        temp[j] = matrix[i][j];
      } else {
        int down = matrix[i][j] + k[j];
        int ld = -1e9;
        if (j - 1 >= 0)
          ld = matrix[i][j] + k[j - 1];
        int rd = -1e9;
        if (j + 1 < m)
          rd = matrix[i][j] + k[j + 1];
        temp[j] = max(down, max(ld, rd));
      }
    }
    k = temp;
  }
  for (int i = 0; i < m; i++) {
    mx = max(mx, k[i]);
  }
  return mx;
}
