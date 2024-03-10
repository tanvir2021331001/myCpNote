#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mk make_pair
// Job scheduling

void solve()
{
  int n;
  cin >> n;
  vector<pair<int, int> > time;
  for (int i = 0; i < n; i++)
  {
    int st, en;
    cin >> st >> en;
    time.push_back(mk(en, st)); // sorting by end time
  }
  sort(time.begin(), time.end());

  int lsttime = 0, cnt = 0;
  
  for (int i = 0; i < n; i++)
  {
    int st = time[i].second, en = time[i].first;

    if (st >= lsttime)
    {
      cout << st << " " << en << "\n";
      lsttime = en;
      cnt++;
    }

  }

  cout << cnt << "\n";
}
int32_t main()
{
  solve();
}
/*
5
1 9
2 6
5 7
5 6
6 7
output:
2
*/
