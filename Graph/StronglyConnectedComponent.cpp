
#include <bits/stdc++.h>
using namespace std;

void dfs(vector<int> v[], vector<int> &vis, vector<int> &component, int node, int par)
{
  if (vis[node] == 1)
    return;
  vis[node] = 1;
  for (auto ch : v[node])
  {
    if (ch != par)
    {
      dfs(v, vis, component, ch, node);
    }
  }
  component.push_back(node);
}
void solve()
{
  int n, m;
  cin >> n >> m;
  vector<int> v[n + 1], rev[n + 1];
  for (int i = 0; i < m; i++)
  {
    int l, r;
    cin >> l >> r;
    v[l].pb(r);
    rev[r].pb(l);
  }

  vector<int> vis(n + 1, 0), order;
  for (int i = 1; i <= n; i++)
  {
    if (vis[i] == 0)
    {
      dfs(v, vis, order, i, -1);
    }
  }
  reverse(order.begin(), order.end());
  int cnt = 0;
  fill(vis.begin(), vis.end(), 0);

  for (auto i : order)
  {
    vector<int> comp;
    if (vis[i] == 0)
    {
      cnt++;
      dfs(rev, vis, comp, i, -1);
    }
    for (auto x : comp)
      cout << x << " ";
    if (comp.size() > 0)
      cout << "\n";
  }
  cout << "total number of strongly connected component : " << cnt << "\n";
}

int32_t main()
{


    solve();


  return 0;
}
/*
input:
5 5
1 5
2 1
5 2
5 3
5 4

output:
5 2 1 
4 
3 
total number of strongly connected component : 3
*/
