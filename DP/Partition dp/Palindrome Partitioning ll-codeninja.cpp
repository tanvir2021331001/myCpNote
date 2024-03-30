//https://bit.ly/3jNRzqX
//memoization
bool ispalindrome(int i,int j,string &str){
    while(i<=j){
        if(str[i]!=str[j]){
            return false;
        }
        i++;j--;
    }
    return true;
}

int f(vector<int>&dp,string &str,int i,int n){

    if(i>=n){
        return 0;
    }
    if(dp[i]!=-1)return dp[i];
    string sp="";
    int cost=1e9;
    for(int j=i;j<n;j++){
        if(ispalindrome(i,j,str)){
            cost=min(cost,1+f(dp,str,j+1,n));
        }
    }
    return dp[i]=cost;
}
int palindromePartitioning(string str)
{
   int n=str.size();
   vector<int>dp(n+1,-1);
   return f(dp,str,0,n)-1;
}



//tabulation
bool ispalindrome(int i,int j,string &str){
    while(i<=j){
        if(str[i]!=str[j]){
            return false;
        }
        i++;j--;
    }
    return true;
}


int palindromePartitioning(string str)
{
   int n=str.size();
   vector<int>dp(n+1,0);
   for(int i=n-1;i>=0;i--){
       int cost=1e8;
       for(int j=i;j<n;j++){
           if(ispalindrome(i,j,str)){
               cost=min(cost,1+dp[j+1]);
           }
       }
       dp[i]=cost;
   }
   return dp[0]-1;
}
