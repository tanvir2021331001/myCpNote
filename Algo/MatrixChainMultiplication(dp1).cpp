#include <bits/stdc++.h>
using namespace std;

int dp[100][100];
int minimumNumberofMulti(int a[], int i, int j)
{
  if (i >= j)
    return 0;
  if (dp[i][j] != -1)
  {
    return dp[i][j];
  }
  int NumMulti = INT32_MAX;
  for (int k = i; k < j; k++)
  {
    NumMulti = min(NumMulti, minimumNumberofMulti(a, i, k) + minimumNumberofMulti(a, k + 1, j) + a[i - 1] * a[k] * a[j]);
  }
  dp[i][j] = NumMulti;
  return NumMulti;
}
void solve()
{
  memset(dp, -1, sizeof(dp));
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  cout << minimumNumberofMulti(a, 1, n - 1) << "\n";
}

int32_t main()
{
  {
    solve();
  }
  return 0;
}
/*
//for 3*2 2*4 4*2 2*5  matrix
5
3 2 4 2 5
ans :number of multiplication 58
*/
