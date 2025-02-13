#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mk make_pair
int timer = 0;
void dfs(vector<int> v[], vector<int> &vis, vector<int> &in, vector<int> &low, int node, int par, vector<pair<int, int>> &bridges)
{
    if (vis[node] == 1)
        return;
    vis[node] = 1;
    in[node] = low[node] = timer++;
    for (int ch : v[node])
    {
        if (ch == par)
        {
            continue;
        }
        dfs(v, vis, in, low, ch, node, bridges);
        low[node] = min(low[node], low[ch]);
        if (low[node] < low[ch])
        {
            bridges.pb(mk(node, ch));
        }
    }
}

void Tarjans()
{
    int n, m;
    cin >> n >> m; // n node , m= number of edge
    vector<int> v[n + 1];
    for (int i = 0; i < m; i++)
    {
        int l, r;
        cin >> l >> r;
        v[l].pb(r);
        v[r].pb(l);
    }

    vector<int> vis(n + 1, 0), in(n + 1, 0), low(n + 1, 0);
    vector<pair<int, int>> bridges;
    for (int i = 0; i < n; i++)
    {
        if (vis[i] == 0)
        {
            dfs(v, vis, in, low, i, -1, bridges);
        }
    }
    cout << bridges.size() << "\n";
    for (auto x : bridges)
    {
        cout << x.first << " " << x.second << "\n";
    }
}
int32_t main()
{
    Tarjans();
}
/*
5 5
1 0
2 1
0 2
0 3
3 4
*/
