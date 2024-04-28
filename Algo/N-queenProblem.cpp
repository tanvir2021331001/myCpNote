
#include <bits/stdc++.h>
using namespace std;

const int n=4;
int bord[n][n];
bool issafe(int row,int col)
{
    for(int i=col;i>=0;i--)
    {
        if(bord[row][i]==1)
        {
          return false;
        }
    }
    for(int i=row,j=col;i>=0&&j>=0;i--,j--)
    {
        if(bord[i][j]==1)
        {
            return false;
        }
    }
    for(int i=row,j=col;i>=0&&j<n;i--,j++)
    {
         if(bord[i][j]==1)
         {
            return false;
         } 
    }
    return true;
    }
bool fill(int col)
{
    if(col>=n)
    {
        return true;
    }
    for(int i=0;i<n;i++)
    {
      if(issafe(i,col))
      {
        bord[i][col]=1;
        if(fill(col+1))return true;
        bord[i][col]=0;
      }
    }
    return false;
}
void solve()
{
 fill(0);
 for(int i=0;i<n;i++)
 {
    for(int j=0;j<n;j++)
    {
        cout<<bord[i][j]<<" ";
    }
    cout<<"\n";
 }
  

}
int32_t main()
{
  solve();
  return 0;
}

//Optimized
#include <bits/stdc++.h>
using namespace std;
const int n=8;
int bord[n][n];
int fd[2*n+1],sd[2*n+1],ro[n+1];

bool fill(int col)
{
   if(col>=n)
   {
    return true;
   }
   for(int i=0;i<n;i++)
   {
    if(ro[i]==0&&fd[i+col]==0&&sd[i-col+n-1]==0)
    {
      ro[i]=1;
      bord[i][col]=fd[i+col]=sd[i-col+n-1]=1;
      if(fill(col+1))
      {
        return true;
      }
      ro[i]=0;
       bord[i][col]=fd[i+col]=sd[i-col+n-1]=0;
    }

   }
   return false;
}
void solve()
{
 fill(0);
 for(int i=0;i<n;i++)
 {
    for(int j=0;j<n;j++)
    {
        cout<<bord[i][j]<<" ";
    }
    cout<<"\n";
 }
  

}
int32_t main()
{
  solve();
  return 0;
}
