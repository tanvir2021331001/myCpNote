#include <bits/stdc++.h>
using namespace std;
#define int long long
void lcs(string a, string b)
{
  int n = a.size(), m = b.size();
  vector<vector<int> > dp(m + 1, vector<int>(n + 1, 0));
  for (int i = 1; i <= m; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      if (b[i - 1] == a[j - 1])
      {
        dp[i][j] = 1 + dp[i - 1][j - 1];
      }
      else
      {
        dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
      }
    }
  }
  // backtrack
  int i = m, j = n;
  string lc;
  while (i > 0 && j > 0)
  {
    if (a[j - 1] == b[i - 1])
    {
      lc = a[j - 1] + lc;
      i--;
      j--;
    }
    else if (dp[i][j - 1] > dp[i - 1][j])
    {
      j--;
    }
    else
    {
      i--;
    }
  }
  cout << dp[m][n] << "\n";
  cout << lc << "\n";
}
void solve()
{

  string a, b;
  cin >> a >> b;
  lcs(a, b);
}

int32_t main()
{
  // int t;cin>>t;while(t--)
  solve();
}
