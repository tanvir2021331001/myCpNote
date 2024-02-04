#include <bits/stdc++.h>
using namespace std;
//---------
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace __gnu_cxx;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//--------
#define pb push_back
#define mk make_pair
#define F first
#define int long long
#define S second
#define test \
  int t;     \
  cin >> t;  \
  while (t--)
#define fast                        \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);                       \
  cout.tie(0);

void solve()
{
  int n;
  cin >> n;
  ordered_set<int> os;
  while (n--)
  {
    char c;
    int k;
    cin >> c >> k;
    if (c == 'I')  //insert
    {
      os.insert(k);
    }
    else if (c == 'D')//erase/delete
    {
      os.erase(os.find(k));
    }
    else if (c == 'C')//smaller all number
    {
      cout << os.order_of_key(k) << "\n";
    }
    else if (c == 'K' && k <= os.size())//kth element
    {

      cout << *(os.find_by_order(k - 1)) << "\n";
    }
    else
      cout << "invalid\n";
  }
}
int32_t main()
{
  fast
  // test
  solve();
  return 0;
}
