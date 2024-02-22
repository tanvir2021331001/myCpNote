#include <bits/stdc++.h>
using namespace std;

// Quick sort
int takePivot(int arr[], int start, int end)
{
  int pivot = arr[end]; // pivot can be any element
  int i = start;
  for (int j = start; j < end; j++)
  {
    if (arr[j] <= pivot)
    {
      swap(arr[i], arr[j]);
      i++;
    }
  }
  if (i <= end)
  {
    swap(arr[i], arr[end]);
  }
  return i;
}
void Quicksort(int arr[], int start, int end)
{
  if (start >= end)
    return;
  int PivotIndex = takePivot(arr, start, end);
  Quicksort(arr, start, PivotIndex - 1);
  Quicksort(arr, PivotIndex + 1, end);
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
  Quicksort(a, 0, n - 1); // n-1 for 0 based indexing
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
