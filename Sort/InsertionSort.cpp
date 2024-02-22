#include <bits/stdc++.h>
using namespace std;
// O(n^2)
void insertionSort(int a[], int n)
{
  for (int i = 0; i < n; i++)
  {
    int key = a[i], j = i - 1;
    while (j >= 0 && a[j] > key)
    {
      a[j + 1] = a[j];
      j--;
    }
    a[j + 1] = key;
  }
}

void solve()
{
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  insertionSort(a, n);
  for (int i = 0; i < n; i++)
  {
    cout << a[i] << " ";
  }
  cout << "\n";
}

int32_t main()
{

  solve();

  return 0;
}
