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
