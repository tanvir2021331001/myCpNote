#include <bits/stdc++.h>
using namespace std;
//https://vjudge.net/contest/612246#problem/K
//CSES - 2166 
const int sz = 1e6 + 7;
struct Node
{
  int sum;
  int prefix;
};

Node tree[3 * sz];
int arr[sz];
void margeres(int node)
{
  tree[node].sum = tree[2 * node].sum + tree[2 * node + 1].sum;
  tree[node].prefix = max(tree[node * 2].prefix, tree[node * 2].sum + tree[node * 2 + 1].prefix);
}

void build(int node, int st, int en)
{
  if (st >= en)
  {
    tree[node].sum = tree[node].prefix = arr[st];
    return;
  }
  int mid = (st + en) / 2;
  int left = 2 * node, right = 2 * node + 1;
  build(left, st, mid);
  build(right, mid + 1, en);
  margeres(node);
}

void update(int node, int st, int en, int ind, int val)
{
  if (st > ind || en < ind)
    return;
  if (st == en && st == ind)
  {
    arr[st] = val;
    tree[node].sum = tree[node].prefix = val;
    return;
  }
  int mid = (st + en) / 2;
  int left = 2 * node, right = 2 * node + 1;
  update(left, st, mid, ind, val);
  update(right, mid + 1, en, ind, val);
  margeres(node);
}

Node query(int node, int st, int en, int i, int j)
{
  Node temp;
  temp.sum = temp.prefix = 0;
  if (j < st || i > en)
  {
    return temp;
  }
  if (st >= i && en <= j)
  {
    return tree[node];
  }
  int mid = (st + en) / 2;
  int left = 2 * node, right = 2 * node + 1;
  Node k1 = query(left, st, mid, i, j), k2 = query(right, mid + 1, en, i, j);
  temp.sum = k1.sum + k2.sum;
  temp.prefix = max(k1.prefix, k1.sum + k2.prefix);
  return temp;
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
      int pos, val;
      cin >> pos >> val;
      update(1, 1, n, pos, val);
    }
    else
    {
      int l, r;
      cin >> l >> r;
      cout << max(0, query(1, 1, n, l, r).prefix) << "\n";
    }
  }
}

int32_t main()
{

  solve();

  return 0;
}
/*
8 4 //n  q
1 2 -1 3 1 -5 1 4
2 2 6    //2 l r
1 4 -2   //1 pos value
2 2 6
2 3 4

*/
