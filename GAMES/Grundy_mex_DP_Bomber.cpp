#include <bits/stdc++.h>
using namespace std;
//Spoj Problem
//https://www.spoj.com/problems/BOMBER/

int dp[101][101];
int f(int n, int m)
{
  if (n <= 0 || m <= 0)
    return 0;
  if (n == 1 || m == 1)
  {
    return 1;
  }
  if (dp[n][m] != -1)
  {
    return dp[n][m];
  }
  int r = 0;
  set<int> st;
  vector<int> vis(155, 0);
  for (int i = 1; i <= (n + 1) / 2; i++)
  {
    for (int j = 1; j <= (m + 1) / 2; j++)
    {
      int q1x = i - 1, q1y = j - 1;
      int q2x = n - q1x - 1, q2y = j - 1;
      int q3x = i - 1, q3y = m - q1y - 1;
      int q4x = n - i, q4y = m - j;
      r = f(q1x, q1y) ^ f(q2x, q2y) ^ f(q3x, q3y) ^ f(q4x, q4y); //XOR for every existing part that related to
      vis[r]++;
    }
  }
  int g = 0;
  for (int i = 0; i < 155; i++)     //Find mex value for different move
  {
    if (vis[i] == 0)
    {
      g = i;
      break;
    }
  }
  return dp[n][m] = dp[m][n] = g;   //return mex value
}
void solve()
{
  int n, m;
  cin >> n >> m;
  int ans = f(n, m);
  if (ans)                         //if the value is not equal to 0
  {
    cout << 1 << "\n";            //1st player
  }
  else
  {
    cout << 2 << "\n";
  }
}

int32_t main()
{
  memset(dp, -1, sizeof(dp));
  int t;
  cin >> t;
  while (t--)
  {
    solve();
  }
  return 0;
}
