#include <bits/stdc++.h>
using namespace std;

//Forest Queries II CSES - 1739 
//https://vjudge.net/contest/612246#problem/P

#define mk make_pair
const int sz = 2e3+7;
int Bit[sz][sz], n;
void update(int px, int py, int val)
{
  for (int pos = px; pos <= n; pos += (pos & (-pos)))
  {
    for (int posy = py; posy <= n; posy += (posy & (-posy)))
    {
      Bit[pos][posy] += val;
    }
  }
}
int query(int px, int py)
{
  int sum = 0;
  for (int i = px; i > 0; i -= (i & (-i)))
  {
    for (int j = py; j > 0; j -= (j & (-j)))
    {
      sum += Bit[i][j];
    }
  }
  return sum;
}

void solve()
{
  int q;
  cin >> n >> q;
  string s[n + 1];
  for (int i = 1; i <= n; i++)
  {
    cin >> s[i];
    s[i] = "#" + s[i];
  }
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      if (s[i][j] == '*')
      {
        update(i, j, 1);
      }
    }
  }
  while (q--)
  {
    int fl;
    cin >> fl;
    if (fl == 1)
    {
      int x, y;
      cin >> x >> y;    //in this case x work as y,and y is x axis
      if ((query(x, y) - query(x, y - 1) - query(x - 1, y) + query(x - 1, y - 1)) == 1)
      {
        update(x, y, -1);
      }
      else
      {
        update(x, y, 1);
      }
      continue;
    }
    int x1, x2, y1, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    cout << query(x2, y2) - query(x2, y1 - 1) - query(x1 - 1, y2) + query(x1 - 1, y1 - 1) << "\n";
  }
}
int main()
{
  solve();
  return 0;
}
/*
4 3
.*..
*.**
**..
****
2 2 2 3 4
1 3 3
2 2 2 3 4


*/
