//https://bit.ly/32tAMUW

//
  #define ll long long
 ll mod =1000000007;
 ll cnt( vector<vector<vector<ll> > >&dp,string &exp,ll i,ll j,ll v){
    if(i>j)return 0;
    if(i==j){
       if(v)return exp[i]=='T';
       else return exp[i]=='F';
    }
    if(dp[i][j][v]!=-1)return dp[i][j][v];
    ll way=0;
    for(ll ind=i+1;ind<=j-1;ind+=2){
         ll  Lt=cnt(dp,exp,i,ind-1,1)%mod;
         ll Lf=cnt(dp,exp,i,ind-1,0)%mod;
         ll Rt=cnt(dp,exp,ind+1,j,1)%mod;
         ll Rf=cnt(dp,exp,ind+1,j,0)%mod;
         if(exp[ind]=='|'){
            if(v) way=(way+(Lt*Rt)%mod+(Lf*Rt)%mod+(Lt*Rf)%mod)%mod;
            else way=(way+(Lf*Rf)%mod)%mod;
         }
         else if(exp[ind]=='&'){
            if(v) way=(way+(Lt*Rt)%mod)%mod;
            else way=(way+(Lt*Rf)%mod+(Lf*Rt)%mod+(Lf*Rf)%mod)%mod;
         }
         else{
              if(v)way=(way+(Lt*Rf)%mod+(Lf*Rt)%mod)%mod;
              else way=(way+(Lt*Rt)%mod+(Lf*Rf)%mod)%mod;
         }
         
    }
    return dp[i][j][v]=way%mod;
}

ll evaluateExp(string & exp) {
    ll n=exp.size();
    vector<vector<vector<ll> > >dp(n+1,vector<vector<ll> >(n+1,vector<ll>(2,-1)));
    return cnt(dp,exp,0,n-1,1);
}
