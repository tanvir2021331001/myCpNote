#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mk make_pair
// Job scheduling

void solve()
{
  int n;
  cin >> n;
  int profit[n], dedline[n], mx = 0;
  for (int i = 0; i < n; i++)
  {
    cin >> profit[i];
  }
  for (int i = 0; i < n; i++)
  {
    cin >> dedline[i];
    mx = max(mx, dedline[i]);
  }
  vector<pair<int, int> > J;

  for (int i = 0; i < n; i++)
  {
    J.push_back(mk(profit[i], dedline[i]));
  }
  sort(J.begin(), J.end(), greater<pair<int, int> >());
  int schedule[mx + 1], profitsum = 0;
  memset(schedule, 0, sizeof(schedule));
  for (int i = 0; i < n; i++)
  {
    int p = J[i].first, d = J[i].second;
    while (d >= 1 && schedule[d] != 0)
    {
      d--;
    }
    if (d >= 1)
    {
      schedule[d] = 1;
      profitsum += p;
      cout << p << " ";
    }
  }

  cout << profitsum << "\n";
}
int32_t main()
{
  solve();
}
