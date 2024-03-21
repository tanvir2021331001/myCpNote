#include <bits/stdc++.h> 
// https://bit.ly/3K1cvqv
int f(vector<vector<int> >&dp,vector<vector<int> >&t,int n,int i,int j){
	if(i==n-1)return t[i][j];
	if(dp[i][j]!=-1)return dp[i][j];
	int d=t[i][j]+f(dp,t,n,i+1,j);
	int dg=t[i][j]+f(dp,t,n,i+1,j+1);
	return dp[i][j]=min(d,dg);
}
int minimumPathSum(vector<vector<int>>& triangle, int n){
 vector<vector<int> >dp(n,vector<int>(n,-1));
 for(int i=0;i<n;i++)dp[n-1][i]=triangle[n-1][i];
 return f(dp,triangle,n,0,0);
}
//tabulation
#include <bits/stdc++.h> 

int minimumPathSum(vector<vector<int>>& triangle, int n){
 vector<vector<int> >dp(n,vector<int>(n,0));
 for(int i=0;i<n;i++)dp[n-1][i]=triangle[n-1][i];
 for(int i=n-2;i>=0;i--){
	 for(int j=i;j>=0;j--){
			 dp[i][j]=min(dp[i+1][j]+triangle[i][j],dp[i+1][j+1]+triangle[i][j]);
	 }
 }
return dp[0][0];
}
//space optimization
#include <bits/stdc++.h> 

int minimumPathSum(vector<vector<int>>& triangle, int n){
 vector<int>k(n,0);
 for(int i=0;i<n;i++)k[i]=triangle[n-1][i];
 for(int i=n-2;i>=0;i--){
	  vector<int>temp(n,0);
	 for(int j=i;j>=0;j--){
			 temp[j]=min(k[j]+triangle[i][j],k[j+1]+triangle[i][j]);
	 }
	 k=temp;
 }
return k[0];
}
