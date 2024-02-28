#include <bits/stdc++.h>
using namespace std;
#define int long long
//Binary index tree with prefix sum query
void update(int BIT[], int n, int pos, int val)
{ // Sum with current
  while (pos <= n)
  {
    BIT[pos] += val;
    pos += (pos & (-pos)); // position update + pos&(2s compliment of pos)
  }
}
int getprefixSum(int BIT[], int pos)
{ // prefix sum of pos
  int sum = 0;
  while (pos > 0)
  {
    sum += BIT[pos];
    pos -= (pos & (-pos));
  }
  return sum;
}

void solve()
{
  int n, query;
  cin >> n >> query;
  int a[n], BIT[n + 1];
  memset(BIT, 0, sizeof(BIT));
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
    update(BIT, n, i + 1, a[i]);
  }
  while (query--)
  {
    int upd;
    cin >> upd;
    if (upd == 1)   
    {
      int pos, val;
      cin >> pos >> val;
      update(BIT, n, pos, val);//sum with initial value
    }
    else if (upd == 2)
    {
      int pos;
      cin >> pos;
      cout << getprefixSum(BIT, pos) << "\n";  //prefix sum
    }
    else
    {
      int l, r;
      cin >> l >> r;
      cout << getprefixSum(BIT, r) - getprefixSum(BIT, l - 1) << "\n";   //sum in a range
    }
  }
}

int32_t main()
{
  solve();
  return 0;
}
