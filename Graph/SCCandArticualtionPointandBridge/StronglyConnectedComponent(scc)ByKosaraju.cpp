#include <bits/stdc++.h>
using namespace std;
#define pb push_back
void dfs1(vector<int> v[], vector<int> &vis, stack<int> &st, int node)
{
    if (vis[node] == 1)
        return;
    vis[node] = 1;
    for (int ch : v[node])
    {
        dfs1(v, vis, st, ch);
    }
    st.push(node);
}
void dfs2(vector<int> rv[], vector<int> &vis, int node,vector<int>&component)
{
    if (vis[node] == 1)
        return;
    vis[node] = 1;
    component.pb(node);//push components
    for (int ch : rv[node])
    {
        dfs2(rv, vis, ch,component);
    }
}
void Kosaraju()
{
    int n, m;
    cin >> n >> m;//n node , m= number of edge
    vector<int> v[n + 1], rv[n + 1];
    for (int i = 0; i < m; i++)
    {
        int l, r;
        cin >> l >> r;
        v[l].pb(r);
        rv[r].pb(l);//reverse graph of v
    }
    stack<int> st;
    vector<int> vis1(n + 1, 0), vis2(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        if (vis1[i] == 0)
        {
            dfs1(v, vis1, st, i);// finding finish time stack
        }
    }
    int scc = 0;
    vector<vector<int> >connected;
    while (!st.empty())
    {
        int i = st.top();
        st.pop();
        if (vis2[i] == 0)
        {
            scc++;
            vector<int>g;/// every connected component
            dfs2(rv, vis2, i,g);
             connected.pb(g);
        }
    }
    cout << scc << "\n";//number of connected component
    for(vector<int> comps:connected){
        for(int x:comps){
            cout<<x<<" ";
        }
        cout<<"\n";
    }
}
int32_t main()
{
    Kosaraju();
}
/*
5 5
1 0
2 1
0 2
0 3
3 4
*/
