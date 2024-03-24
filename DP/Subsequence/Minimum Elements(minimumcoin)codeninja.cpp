//memoization
#include <bits/stdc++.h> 
//https://bit.ly/3HJTeIl
int f(vector<vector<int>>&dp,vector<int> &num,int ind,int tar){
   if(ind==0){
       if(tar==0)return 0;
       else if(tar<num[0]||tar%num[0]!=0)return 1e9;
       else   if(tar%num[0]==0){
           return tar/num[0];
       }
   }
   if(dp[ind][tar]!=-1)return dp[ind][tar];
   int ntake=f(dp,num,ind-1,tar);
   int take=1e9;
   if(tar>=num[ind]){
       take=f(dp,num,ind,tar-num[ind])+1;
   }
  return dp[ind][tar]=min(take,ntake);
}
int minimumElements(vector<int> &num, int x)
{   
    int n=num.size();
    vector<vector<int>>dp(n,vector<int>(x+1,-1));
    int ans=f(dp,num,n-1,x);
    return (ans>=1000000000)?-1:ans;
}
//tabulation
#include <bits/stdc++.h> 

int minimumElements(vector<int> &num, int x)
{   
    int n=num.size();
    vector<vector<int>>dp(n,vector<int>(x+1,0));
    for(int i=0;i<=x;i++)dp[0][i]=(i%num[0]==0)?i/num[0]:1e9;
    //dp[0][0]=0;
    for(int i=1;i<n;i++){
        for(int j=0;j<=x;j++){
            int ntake=dp[i-1][j];
            int take=1e9;
            if(num[i]<=j){
                take=dp[i][j-num[i]]+1;
            }
            dp[i][j]=min(take,ntake);
        }
    }
    int ans=dp[n-1][x];
    return (ans>=1000000000)?-1:ans;
}

//space optimization
#include <bits/stdc++.h>

int minimumElements(vector<int> &num, int x) {
  int n = num.size();
  vector<int> dp(x + 1, 0);
  for (int i = 0; i <= x; i++)
    dp[i] = (i % num[0] == 0) ? i / num[0] : 1e9;

  for (int i = 1; i < n; i++) {
    vector<int> temp(x + 1, 0);
    for (int j = 0; j <= x; j++) {
      int ntake = dp[j];
      int take = 1e9;
      if (num[i] <= j) {
        take = temp[j - num[i]] + 1;
      }
      temp[j] = min(take, ntake);
    }
    dp = temp;
  }
  int ans = dp[x];
  return (ans >= 1000000000) ? -1 : ans;
}
