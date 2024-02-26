#include <bits/stdc++.h>
using namespace std;
//CSES - 1651 
const int sz = 1e6 + 7;
int arr[sz];
int tree[3 * sz], n, lazy[3 * sz];
void build(int node, int st, int en)
{
  if (st >= en)
  {
    tree[node] = arr[st];
    return;
  }
  int mid = (st + en) / 2;
  build(2 * node, st, mid);
  build(2 * node + 1, mid + 1, en);
  tree[node] = tree[2 * node] + tree[2 * node + 1];
}


void update(int node, int st, int en, int i, int j, int val)
{
  if (j < st || i > en)
  {
    return;
  }
  if (i <= st && en <= j)
  {
    lazy[node] += val;//if mltiple update previous+val
    return;
  }
  update(2 * node, st, (st + en) / 2, i, j, val);
  update(2 * node + 1, (st + en) / 2 + 1, en, i, j, val);
}


int query(int node, int st, int en, int i, int j, int prop)
{
  if (i > en || j < st)
  {
    return 0;
  }
  if (st >= i && en <= j)
  {
    return tree[node] + (prop + lazy[node]) * (j - i + 1);
  }
  return query(2 * node, st, (st + en) / 2, i, j, prop + lazy[node]) + query(2 * node + 1, (st + en) / 2 + 1, en, i, j, prop + lazy[node]);
}

void solve()
{
  int n, q;
  cin >> n >> q;

  for (int i = 1; i <= n; i++)
  {
    cin >> arr[i];
  }
  build(1, 1, n);
  while (q--)
  {
    int fl;
    cin >> fl;
    if (fl == 1)
    {
      int l, r, val;
      cin >> l >> r >> val;
      update(1, 1, n, l, r, val);
    }
    else
    {
      int l, r;
      cin >> l;
      r = l;//for a single index i,l=r=i
      cout << query(1, 1, n, l, r, 0) << "\n";
    }
  }
}

int32_t main()
{
    solve();
  
  return 0;
}
/*
8 3     //n q
3 2 4 5 1 1 5 3  //array
2 4    //query
1 2 5 1  //update
2 4

*/
