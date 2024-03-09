#include <bits/stdc++.h>
using namespace std;
#define int long long
int dp[100][100];
string lc;
void retrivelc(string a, string b, int n, int m)
{
  if (n == -1 || m == -1)
    return;
  if (dp[n - 1][m - 1] + 1 == dp[n][m] && dp[n - 1][m] != dp[n][m] && dp[n][m - 1] != dp[n][m])
  {
    lc = a[n] + lc;
    retrivelc(a, b, n - 1, m - 1);
  }
  else
  {
    if (dp[n - 1][m] == dp[n][m])
    {
      retrivelc(a, b, n - 1, m);
    }
    else
    {
      retrivelc(a, b, n, m - 1);
    }
  }
}
int lcs(string a, string b, int posa, int posb)
{
  if (posa == -1 || posb == -1)
  {
    return 0;
  }
  if (a[posa] == b[posb])
  {
    return dp[posa][posb] = dp[posa][posb] == -1 ? (1 + lcs(a, b, posa - 1, posb - 1)) : dp[posa][posb];
  }
  else
  {
    int left = dp[posa][posb - 1] = dp[posa][posb - 1] == -1 ? lcs(a, b, posa, posb - 1) : dp[posa][posb - 1];
    int up = dp[posa - 1][posb] = dp[posa - 1][posb] == -1 ? lcs(a, b, posa - 1, posb) : dp[posa - 1][posb];
    dp[posa][posb] = max(left, up);
    return dp[posa][posb];
  }
}
void solve()
{
  memset(dp, -1, sizeof(dp));
  lc = "";
  string a, b;
  cin >> a >> b;
  cout << lcs(a, b, a.size() - 1, b.size() - 1) << "\n";
  retrivelc(a, b, a.size() - 1, b.size() - 1);
  cout << lc << "\n";
}

int32_t main()
{
  solve();
}
/*
abab
bb
output:
2
bb
*/
