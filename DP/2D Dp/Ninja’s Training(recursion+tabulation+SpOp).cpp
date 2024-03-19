#include <bits/stdc++.h>
using namespace std;
#define int long long
//https://www.codingninjas.com/studio/problems/ninja-s-training_3621003?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTabValue=PROBLEM
//https://bit.ly/3F4yl8z
int maxpoint(vector<vector<int> > &dp, vector<vector<int> > &points, int n, int last)
{
    if (n == 0)
    {
        int temp = 0;
        for (int i = 0; i < 4; i++)
        {
            if (i != last)
            {
                temp = max(temp, points[n][i]);
            }
        }
        return dp[n][last] = temp;
    }
    if (dp[n][last] != -1)
        return dp[n][last];
        
    int temp = 0;
    for (int i = 0; i < 3; i++)
    {
        if (i != last)
            temp = max(temp, points[n][i] + maxpoint(dp, points, n - 1, i));
    }
    return dp[n][last] = temp;
}
void solve()
{
    int n;
    cin >> n;
    vector<vector<int> > points(n, vector<int>(4, 0)), dp(n + 1, vector<int>(4, -1));
    for (int i = 0; i < n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        points[i][0] = a;
        points[i][1] = b;
        points[i][2] = c;
    }
    cout << maxpoint(dp, points, n - 1, 3) << "\n";
}
int32_t main()
{
    // int t;cin >> t;while (t--)
    solve();
    return 0;
}


//tabulation

int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int> >dp(n,vector<int>(5,-1));
     for(int i=0;i<3;i++){
         for(int task=0;task<3;task++){
             if(task!=i)
             dp[0][i]=max(dp[0][i],points[0][task]);
         }
     }
     for(int i=1;i<n;i++){
         for(int j=0;j<4;j++){
             for(int task=0;task<3;task++){
                 if(task!=j)dp[i][j]=max(dp[i][j],points[i][task]+dp[i-1][task]);
             }
         }
     }
    return dp[n-1][3];
}

///space optimization

int ninjaTraining(int n, vector<vector<int>> &points) {
  vector<int> keep(4, 0);
  for (int i = 0; i < 4; i++) {

    for (int task = 0; task < 3; task++) {
      if (task != i)
        keep[i] = max(keep[i], points[0][task]);
    }
  }
  for (int i = 1; i < n; i++) {
    vector<int> temp(4, 0);
    for (int j = 0; j < 4; j++) {
      for (int task = 0; task < 3; task++) {
        if (task != j)
          temp[j] = max(temp[j], points[i][task] + keep[task]);
      }
    }
    keep = temp;
  }
  return keep[3];
}

