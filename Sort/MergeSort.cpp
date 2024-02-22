#include <bits/stdc++.h>
using namespace std;

// Merge Sort
void merge(int arr[], int low, int mid, int high)
{
  vector<int> v;
  int left = low;
  int right = mid + 1;
  while (left <= mid && right <= high)
  {
    if (arr[left] <= arr[right])
    {
      v.push_back(arr[left]);
      left++;
    }
    else
    {
      v.push_back(arr[right]);
      right++;
    }
  }
  while (left <= mid)
  {
    v.push_back(arr[left]);
    left++;
  }
  while (right <= high)
  {
    v.push_back(arr[right]);
    right++;
  }
  for (int i = 0; i < v.size(); i++)
  {
    arr[low + i] = v[i];
  }
}
void mergesort(int arr[], int start, int end)
{
  if (start >= end)
  {
    return;
  }
  int mid = (start + end) / 2;
  mergesort(arr, start, mid);
  mergesort(arr, mid + 1, end);
  merge(arr, start, mid, end);
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
  mergesort(a, 0, n - 1); // n-1 for 0 based indexing
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
