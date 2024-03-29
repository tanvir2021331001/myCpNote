int longestBitonicSubsequence(vector<int>& arr, int n)
{
  // https://bit.ly/3r4o1JB
	vector<int>dp1(n+1,1),dp2(n+1,1);
	for(int i=0;i<n;i++){
		for(int prev=0;prev<i;prev++){
			if(arr[i]>arr[prev]&&dp1[prev]+1>dp1[i]){
				dp1[i]=dp1[prev]+1;
			}
		}
	}
	for(int i=n-1;i>=0;i--){
		for(int prev=n-1;prev>i;prev--){
			if(arr[i]>arr[prev]&&dp2[prev]+1>dp2[i]){
				dp2[i]=dp2[prev]+1;
			}
		}
	}
	int mxbi=0;

	for(int i=0;i<n;i++){
    mxbi=max(mxbi,dp1[i]+dp2[i]-1);
	}
	return mxbi;


}
