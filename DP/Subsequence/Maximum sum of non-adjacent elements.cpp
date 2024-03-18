#include <bits/stdc++.h> 
//https://bit.ly/3q5rlUY
int f(vector<int>&dp,vector<int>&nums,int n){
    if(n==0)return nums[0];
    if(n<0)return 0;
    if(dp[n]!=-1)return dp[n];
    int take=nums[n]+f(dp,nums,n-2);
    int nottake=f(dp,nums,n-1);
    return dp[n]=max(take,nottake);
}
int maximumNonAdjacentSum(vector<int> &nums){
    int n=nums.size();
        vector<int>dp(n+1,-1);
        return f(dp,nums,n-1);
}
//tabulation
int maximumNonAdjacentSum(vector<int> &nums){
    int n=nums.size();
        vector<int>dp(n+1,-1);
     dp[0]=nums[0];
     dp[1]=max(nums[0],nums[1]);
     for(int i=2;i<n;i++){
         dp[i]=max(dp[i-1],dp[i-2]+nums[i]);
     }
        return dp[n-1];
}
//Space optimization
int maximumNonAdjacentSum(vector<int> &nums){
    int n=nums.size();
       int cur,l1,l2;
     l2=nums[0];
     l1=max(nums[0],nums[1]);
     cur=l1;
     for(int i=2;i<n;i++){
         cur=max(l1,l2+nums[i]);
         l2=l1;
         l1=cur;
     }
        return cur;
}
