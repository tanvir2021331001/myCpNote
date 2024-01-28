#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mk make_pair

#define ll long long
pair<vector<ll>, vector<ll> > dijkstra(vector<pair<ll, ll> > v[], ll source, ll dest, ll n)   //return parent and distance 
{
    vector<ll> dis(n + 1, 1e18);
    vector<ll> parent(n + 1, -1);
    priority_queue<pair<ll, ll>, vector<pair<ll, ll> >, greater<pair<ll, ll> > > pq;
    dis[source] = 0;
    pq.push(mk(0, source));
    while (!pq.empty())
    {
        ll ds = pq.top().first;
        ll pnode = pq.top().second;

        pq.pop();
        if (dis[pnode] != ds)  //may for sure that no negative loop (not mandatory)
            continue;
        for (ll i = 0; i < v[pnode].size(); i++)
        {
            ll child = v[pnode][i].first;
            ll chw = v[pnode][i].second;

            if (dis[pnode] + chw < dis[child])
            {
                parent[child] = pnode;
                dis[child] = dis[pnode] + chw;
                pq.push(mk(dis[child], child));
            }
        }
    }
    return mk(dis, parent);
}
void SecondSortestPath(vector<pair<ll, ll> > v[], ll source, ll dest, ll n)
{
    vector<ll> dis;
    vector<ll> par;
    ll sortest, sesortest = 1e18;
    pair<vector<ll>, vector<ll> > pr = dijkstra(v, source, dest, n);
    dis = pr.first;
    par = pr.second;
    sortest = dis[dest];
    for (ll ch = dest; ch != source; ch = par[ch])
    {
        ll node = par[ch];
        for (ll i = 0; i < v[node].size(); i++)
        {
            if (v[node][i].first == ch)
            {     //ll weight = v[node][i].second;
                 //  sesortest = min(sesortest, sortest + weight * 2);   if backtrack travarse allows
                  
                ll weight = v[node][i].second;
                v[node][i].second = 1e18;   //delete or set hiest value of the edge weight
                vector<ll> nwdis;
                vector<ll> nwpar;
                pair<vector<ll>, vector<ll> > npr = dijkstra(v, source, dest, n);
                nwdis = npr.first;
                nwpar = npr.second;
                if (nwdis[dest] > sortest) // second sortest must be small---
                    sesortest = min(sesortest, nwdis[dest]);
                v[node][i].second = weight;    //reset the weight
            }
        }
    }
    if (sesortest < 1e18)
    {
        cout << sesortest << "\n";
    }
}
void ru()
{
    ll n = 0, edge = 0;
    cin >> n >> edge;
    vector<pair<ll, ll> > v[n + 1];
    for (ll i = 0; i < edge; i++)
    {
        ll x, y, w;
        cin >> x >> y >> w;
        v[x].pb(mk(y, w));
        v[y].pb(mk(x, w));
    }

    SecondSortestPath(v, 1, n, n);
}
int main()
{
    ru();
    return 0;
}
