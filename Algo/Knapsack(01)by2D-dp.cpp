#include <bits/stdc++.h>
using namespace std;
#define int long long
//0 1 knapsack
void knapsack(int wt, int prof[], int weight[], int n)
{
  int dp[n + 1][wt + 1];
  memset(dp, 0, sizeof(dp));
  for (int i = 1; i <= n; i++)
  {
    for (int w = 1; w <= wt; w++)
    {
      if (weight[i - 1] <= w)
      {
        dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - weight[i - 1]] + prof[i - 1]);
      }
      else
      {
        dp[i][w] = dp[i - 1][w];
      }
    }
  }
  cout << dp[n][wt] << "\n";
}
void solve()
{
  int n, wt;
  cin >> n >> wt;
  int prof[n], weight[n];
  for (int i = 0; i < n; i++)
    cin >> prof[i];
  for (int i = 0; i < n; i++)
    cin >> weight[i];
  knapsack(wt, prof, weight, n);
}
int32_t main()
{
  // int t;cin>>t;while(t--)
  solve();
}
/*
4 5
7 2 1 7  //profit
3 2 1 4  //weight
output:
9
*/
