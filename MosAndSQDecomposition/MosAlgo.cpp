#include <bits/stdc++.h>
using namespace std;
//https://vjudge.net/contest/612246#problem/A
#define int long long
int block;
struct Q
{
    int ind;
    int l, r;
};
bool comp(Q a, Q b)
{
    if (a.l / block != b.l / block)
        return a.l / block < b.l / block;
    return a.r < b.r;
}
void solve()
{
    int n, q;
    cin >> n >> q;
    block = sqrt(n);
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    Q query[q];
    for (int i = 0; i < q; i++)
    {
        cin >> query[i].l >> query[i].r;
        query[i].l--;
        query[i].r--;
        query[i].ind = i;
    }
    sort(query, query + q, comp);
    int ans[q];
    int l = 0, r = -1, sum = 0;
    for (int i = 0; i < q; i++)
    {
        while (query[i].l < l)
        {
            l--;
            sum += a[l];
        }
        while (query[i].l > l)
        {
            sum -= a[l];
            l++;
        }
        while (query[i].r > r)
        {
            r++;
            sum += a[r];
        }
        while (query[i].r < r)
        {
            sum -= a[r];
            r--;
        }
        ans[query[i].ind] = sum;
    }
    for (int i = 0; i < q; i++)
        cout << ans[i] << "\n";
}

int32_t main()
{
    solve();

    return 0;
}
