//memoization
//https://bit.ly/3KQELfy
#include <bits/stdc++.h> 
int f(   vector<vector<vector<int>>>&dp,vector<vector<int>> &grid,int r,int c,int i,int j1,int j2){
    if(j1>=c||j2>=c||j1<0||j2<0){
        return -1e8;
    }
    if(i==r-1){
        if(j1==j2)return grid[i][j1];
        else return grid[i][j1]+grid[i][j2];
    }
    if(dp[i][j1][j2]!=-1){
        return dp[i][j1][j2];
    }
    int mx=-1e8;
    for(int k=-1;k<=1;k++){
        for(int l=-1;l<=1;l++){
          if(j1!=j2) mx=max(mx,f(dp,grid,r,c,i+1,j1+k,j2+l)+grid[i][j1]+grid[i][j2]);
          else{
              mx=max(mx,f(dp,grid,r,c,i+1,j1+k,j2+l)+grid[i][j1]);
          }
        }
    }
    return dp[i][j1][j2]=mx;
}
int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    vector<vector<vector<int>>>dp(r,vector<vector<int>>(r,vector<int>(c,-1)));
   return f(dp,grid,r,c,0,0,c-1);
}

//tabulation
#include <bits/stdc++.h>

int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
  vector<vector<vector<int>>> dp(r+1, vector<vector<int>>(c+1, vector<int>(c+1, 0)));
  for (int i = 0; i < c; i++) {
    for (int j = 0; j < c; j++) {
      if (i != j) {
        dp[r - 1][i][j] = grid[r - 1][i] + grid[r - 1][j];
       
      } else {
         dp[r - 1][i][j] = grid[r - 1][j];
      }
    }
  }

  for (int i = r - 2;i >=0; i--) {
    for (int j1 = 0; j1 < c; j1++) {
      for (int j2 = 0; j2 < c; j2++) {
        int mx = -1e8;
        for (int k = -1; k <= 1; k++) {
          for (int l = -1; l <= 1; l++) {
            if (j1 != j2){
               if(j1+k<c&&j2+l<c&&j1+k>=0&&j2+l>=0)  mx = max(mx,dp[i+1][j1+k][j2+l] +   grid[i][j1] + grid[i][j2]);
            }
            else {
              if(j1+k<c&&j2+l<c&&j1+k>=0&&j2+l>=0) mx = max(mx, dp[i+1][j1+k][j2+l] + grid[i][j1]);
            }
          }
        }
       dp[i][j1][j2]=mx;
          
      }
    }
  }

  return dp[0][0][c-1];
}


//space optimization
#include <bits/stdc++.h>

int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
  vector<vector<int>> dp(c, vector<int>(c, 0));
  for (int i = 0; i < c; i++) {
    for (int j = 0; j < c; j++) {
      if (i != j) {
        dp[i][j] = grid[r - 1][i] + grid[r - 1][j];

      } else {
        dp[i][j] = grid[r - 1][j];
      }
    }
  }

  for (int i = r - 2; i >= 0; i--) {
    vector<vector<int>> temp(c, vector<int>(c, 0));
    for (int j1 = 0; j1 < c; j1++) {
      for (int j2 = 0; j2 < c; j2++) {
        int mx = -1e8;
        for (int k = -1; k <= 1; k++) {
          for (int l = -1; l <= 1; l++) {
            if (j1 != j2) {
              if (j1 + k < c && j2 + l < c && j1 + k >= 0 && j2 + l >= 0)
                mx = max(mx, dp[j1 + k][j2 + l] + grid[i][j1] + grid[i][j2]);
            } else {
              if (j1 + k < c && j2 + l < c && j1 + k >= 0 && j2 + l >= 0)
                mx = max(mx, dp[j1 + k][j2 + l] + grid[i][j1]);
            }
          }
        }
        temp[j1][j2] = mx;
      }
    }
    dp = temp;
  }

  return dp[0][c - 1];
}
