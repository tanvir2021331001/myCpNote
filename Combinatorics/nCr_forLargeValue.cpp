const int mod=998244353;
const int mx_lim=1000000;
vector<int>f(mx_lim+1);
void precalc(){
  f[0]=1;
  for(int i=1;i<=mx_lim;i++){
    f[i]=f[i-1]*i%mod;
  }
}
long long bigMod(long long b,long long p){
  if(!p)return 1;
  if(p&1)return (b*bigMod(b,p-1))%mod;
  long long T=bigMod(b,p/2);
  return (T*T)%mod;
}
long long modInverse(long long n){
  return bigMod(n,mod-2);
}
long long nCr(long long n,long long r){
  return ((f[n]*modInverse(f[r]))%mod*modInverse(f[n-r]))%mod;
}
//
//when n is 1e9 and r <1e5 or near
long long mod =1e9+7;//prime
long long pow(int a,int b){
  if(b<=0){
    return 1LL;
  }
 long long ret=po(a,b/2)%mod;
  if(b&1){
    return (((ret*ret)%mod)*a)%mod;
  }
  else return (ret*ret)%mod;
}
//
long long ncr(int n, int r) {
    // nCr is the same as nC(n-r)
    if (r > n - r) {
        r = n - r;
    }
     long long result = 1;
    // Calculate the result using the formula:
    // nCr = n! / (r! * (n-r)!)
    long long k=1;
    for (int i = 0; i < r; ++i) {
        result = (result*(n - i))%mod;
        k = (k*po((i + 1),mod-2))%mod;
    }
    result=(result*k);

    return result%mod;
}
