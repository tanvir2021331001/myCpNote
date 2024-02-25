#include <bits/stdc++.h>
using namespace std;

const int mx = 2000;//N
const int mxc = 100;//ceil(log(N))

int ancestor[mx][mxc], tin[mx], tout[mx], timer;
int l;

void dfs(vector<int> v[], int u, int p)
{
  tin[u] = ++timer; // indegree
  ancestor[u][0] = p;
  for (int i = 1; i <= l; i++)
  {
    ancestor[u][i] = ancestor[ancestor[u][i - 1]][i - 1];
  }
  for (int i = 0; i < v[u].size(); i++)
  {
    int child = v[u][i];
    if (child != p)
    {
      dfs(v, child, u);
    }
  }
  tout[u] = ++timer; // out degree
}

bool is_ancestor(int p, int u)
{
  if (tin[p] <= tin[u] && tout[p] >= tout[u]) // p will be a  ancestor of u ,if indegree of p is smaller and outdegree id greater then u
  {
    return true;
  }
  else
  {
    return false;
  }
}

int lca(int u, int v)
{
  if (is_ancestor(u, v))
  {
    return true;
  }
  else if (is_ancestor(v, u))
  {
    return true;
  }
  for (int i = l; i >= 0; i--)
  {
    if (!is_ancestor(ancestor[u][i], v))
    {
      u = ancestor[u][i];
    }
  }
  return ancestor[u][0];
}

void solve()
{
  int n, m;
  cin >> n >> m;
  vector<int> v[n + 1];
  for (int i = 0; i < m; i++)
  {
    int x, y;
    cin >> x >> y;
    v[x].push_back(y);
    v[y].push_back(x);
  }
  int root = 1;
  l = ceil(log2(n));
  dfs(v, root, root);
  int q; // for query
  cin >> q;
  while (q--)
  {
    int l, r;
    cin >> l >> r;
    cout << lca(l, r) << "\n";
  }
}

int32_t main()
{
  solve();
  return 0;
}
