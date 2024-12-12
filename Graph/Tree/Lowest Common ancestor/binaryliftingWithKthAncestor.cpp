#include <bits/stdc++.h>
using namespace std;
int n, l, timer;
vector<int> in(5), out(5);
vector<vector<int>> up, adj;

void dfs(int v, int p)
{
    in[v] = timer++;
    up[v][0] = p;

    for (int i = 1; i <= l; i++)
    {
        up[v][i] = up[up[v][i - 1]][i - 1];
    }
    for (int it : adj[v])
    {
        if (it != v && it != p)
            dfs(it, v);
    }
    out[v] = timer++;
}
bool isAncestor(int u, int v)
{
    if (in[u] < in[v] && out[u] > out[v])
        return true;
    return false;
}
int kthAncestor(int u, int k)
{
    int v = u;
    while (k > 0 && v != up[v][0]) 
    {
        int r = log2(k);
        v = up[v][r];
        k -= (1 << r); 
    }
    return v; 
}
int lca(int u, int v)
{
    if (isAncestor(u, v))
        return u;
    if (isAncestor(v, u))
        return v;
    for (int i = l; i >= 0; i--)
    {
        if (!isAncestor(up[u][i], v))
        {
            u = up[u][i];
        }
    }
    return up[u][0];
}
void solve()
{
    cin >> n;
    l = ceil(log2(n));
    up.assign(n + 1, vector<int>(l + 1));
    in.resize(n + 1);
    out.resize(n + 1);
    adj.assign(n + 1, vector<int>(0));

    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 1);
    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int u, k;
        cin >> u >> k;
        cout << kthAncestor(u, k) << "\n";
    }
}
int32_t main()
{
    solve();
    return 0;
}
//
//input
/*
8
1 2
2 3
2 7
6 4
4 1
5 4
8 6

2
8 0
5 8

*/
//
