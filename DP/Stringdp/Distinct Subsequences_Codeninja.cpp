//memoization
//https://bit.ly/3nZNxy7
#define ll long long
const int mod = 1e9 + 7;
ll f(vector<vector<ll>> &dp, string &str, string &sub, ll i, ll j) {
  if (j < 0)
    return 1;
  if (i < 0) {
    return 0;
  }
  if (dp[i][j] != -1)
    return dp[i][j];

  if (str[i] == sub[j]) {
    return dp[i][j] = (f(dp, str, sub, i - 1, j - 1) % mod +
                       f(dp, str, sub, i - 1, j) % mod) %
                      mod;
  } else {
    return dp[i][j] = f(dp, str, sub, i - 1, j) % mod;
  }
}

ll distinctSubsequences(string &str, string &sub) {
  ll n = str.size(), m = sub.size();
  vector<vector<ll>> dp(n + 1, vector<ll>(m + 1, -1));
  return f(dp, str, sub, n - 1, m - 1);
}


//tabulation
    a b c ->sub
  1 0 0 0   
a 1 1 0 0
b 1 1 1 0
c 1 1 1 1
b 1 1 2 1
c 1 1 2 3
str
ANS =3
//
ll distinctSubsequences(string &str, string &sub) {
  ll n = str.size(), m = sub.size();
  vector<vector<ll>> dp(n + 1, vector<ll>(m + 1, 0));
  for (int i = 0; i <= n; i++) {
    dp[i][0] = 1;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (str[i - 1] == sub[j - 1]) {
        dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % mod;
      } else {
        dp[i][j] = dp[i - 1][j] % mod;
      }
    }
  }
  return dp[n][m];
}


//space optimization
//https://bit.ly/3nZNxy7
ll distinctSubsequences(string &str, string &sub) {
  ll n = str.size(), m = sub.size();
  vector<ll> dp(m + 1, 0);
  dp[0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = m; j > 0; j--) {
      if (str[i - 1] == sub[j - 1]) {
        dp[j] = (dp[j - 1] + dp[j]) % mod;
      } else {
        dp[j] = dp[j] % mod;
      }
    }
  }
  return dp[m];
}
