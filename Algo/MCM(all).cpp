#include <bits/stdc++.h>
using namespace std;
int McmRecursive(vector<vector<int> > &dp, vector<int> &d, int i, int j)
{
    if (i == j)
        return dp[i][j] = 0;
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    int cost = 1e9;
    for (int k = i; k < j; k++)
    {
        cost = min(cost, McmRecursive(dp, d, i, k) + McmRecursive(dp, d, k + 1, j) + d[i - 1] * d[k] * d[j]);
    }
    return dp[i][j] = cost;
}
void PrintPath(vector<vector<int> > &s, int i, int j)
{
    if (i == j)
    {
        cout << "A" << i;
    }
    else
    {
        cout << '(';
        PrintPath(s, i, s[i][j]);
        PrintPath(s, s[i][j] + 1, j);
        cout << ")";
    }
}
void McmIterative(vector<vector<int> > &dp, vector<int> &d, int n)
{
    for (int i = 0; i <= n; i++)
        fill(dp[i].begin(), dp[i].end(), 1e9);
    vector<vector<int> > s(n + 1, vector<int>(n + 1, 0));
    for (int i = 0; i < n; i++)
    {
        dp[i][i] = 0;
    }
    for (int L = 2; L < n; L++)
    {
        for (int i = 0; i < n - L + 1; i++)
        {
            int j = i + L - 1;
            for (int k = i; k < j; k++)
            {
                int cost = dp[i][k] + dp[k + 1][j] + d[i - 1] * d[j] * d[k];
                if (cost < dp[i][j])
                {
                    dp[i][j] = cost;
                    s[i][j] = k;
                }
            }
        }
    }
    cout << dp[1][n - 1] << "\n";
    //
    PrintPath(s, 1, n - 1);
    cout << "\n";
}
int main()
{
    int n;
    cin >> n;
    vector<int> d(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> d[i];
    }
    vector<vector<int> > dp(n + 1, vector<int>(n + 1, -1));
    cout<< McmRecursive(dp,d,1,n-1)<<"\n";
   // McmIterative(dp, d, n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
    return 0;
}
