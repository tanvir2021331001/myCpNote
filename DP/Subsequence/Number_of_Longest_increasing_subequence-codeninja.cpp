//https://bit.ly/3fTRGiz

int findNumberOfLIS(vector<int> &arr)
{
 int n=arr.size();
 vector<int>dp(n+1,1),freq(n+1,1);
 int maxi=1,mxfr=0;
 for(int i=0;i<n;i++){
     for(int pre=0;pre<i;pre++){
         if(arr[pre]<arr[i]&&dp[pre]+1>dp[i]){
             dp[i]=dp[pre]+1;
             freq[i]=freq[pre];
         }
         else if(arr[pre]<arr[i]&&dp[pre]+1==dp[i]){
              freq[i]+=freq[pre];
         }
         maxi=max(maxi,dp[i]);
     }
 }
 for(int i=0;i<n;i++){
     if(dp[i]==maxi){
         mxfr+=freq[i];
     }
 }
  return mxfr;
}
