#include<bits/stdc++.h>
using namespace std;
#define sz 1000
int n,m;
int vis[sz][sz],v[sz][sz],dis[sz][sz];
bool isvalid(int x,int y){
    if(x<1||x>n||y<1||y>n)
    {
        return false;
    }
    if(vis[x][y]==1)return false;

    return true;
}

int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
int visb[1000][1000];
bool isvalidforbfs(int x,int y){
    if(x<1||x>n||y<1||y>n)return false;
    if(visb[x][y]==1)return false;
    return true;
  }
void bfsgrid(int x,int y)
{

   queue<pair<int,int> > qu;
   qu.push(make_pair(x,y));
   visb[x][y]=1;
   dis[x][y]=0;
    while(!qu.empty())
    {     
        int cx=qu.front().first;
        int cy=qu.front().second;

        qu.pop();

        if(v[cx][cy]==1)cout<<cx<<" - "<<cy<<"\n";

            for(int i=0;i<4;i++){
                if(isvalidforbfs(cx+dx[i],cy+dy[i]))
                {
                    visb[cx+dx[i]][cy+dy[i]]=1;

                    qu.push(make_pair(cx+dx[i],cy+dy[i]));

                    dis[cx+dx[i]][cy+dy[i]]=dis[cx][cy]+1;
                }
                
                
            }
    }
}
void dfsgrid(int x,int y){
    
    vis[x][y]=1;
    if(v[x][y]==1)cout<<x<<" "<<y<<"\n";
    for(int i=0;i<4;i++){
        if(isvalid(x+dx[i],y+dy[i]))
        {
        dfsgrid(x+dx[i],y+dy[i]);
        }
        
    }
    /*
    if(isvalid(x-1,y)){//up
       dfsgrid(x-1,y);
    }
    if(isvalid(x,y+1)){//right
       dfsgrid(x,y+1);
    }
    if(isvalid(x+1,y)){//down
    dfsgrid(x+1,y);
    }
    if(isvalid(x,y+1)){//left
    dfsgrid(x,y+1);
    }
    */
    
}
int main(){
    cin>>n>>m;
    while(m--){
        int x,y;
        cin>>x>>y;
        v[x][y]=1;
    }
     dfsgrid(1,1);
     cout<<"\n";
     bfsgrid(1,1);
  cout<<"\n";
     for(int i=1;i<=n;i++)
     {
        for(int j=1;j<=n;j++)
        {
            cout<<dis[i][j]<<" ";
        }
        cout<<"\n";
     }
return 0;
}
