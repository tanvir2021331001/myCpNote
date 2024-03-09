#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mk make_pair
//fractional knapsack (greedy)
bool comp(pair<int, int> a, pair<int, int> b)
{
  double perwa = (double)a.second / a.first, perwb = (double)b.second / b.first;
  return perwa > perwb;
}
void solve()
{
  int n, wt;
  cin >> n >> wt;
  int weight[n + 1], profit[n];
  for (int i = 0; i < n; i++)
  {
    cin >> weight[i];
  }
  for (int i = 0; i < n; i++)
  {
    cin >> profit[i];
  }
  vector<pair<int, int> > knap(n);
  for (int i = 0; i < n; i++)
  {
    knap[i] = mk(weight[i], profit[i]);
  }
  sort(knap.begin(), knap.end(), comp);//sort


  int rem = wt;
  double p = 0;

  for (int i = 0; i < n; i++)
  {
    if (rem >= knap[i].first)
    {
      rem -= knap[i].first;
      p += knap[i].second;
    }
    else    //for fraction
    {
      p += ((double)knap[i].second * rem) / knap[i].first;
      rem -= rem;
      break;
    }
  }
  cout << p << "\n";
}

int32_t main()
{
  solve();
}
/*
4 5    //n  wt (maximum weight)
3 2 1 4    //wetght
7 2 1 11    //profit
output:
13.3333
*/
