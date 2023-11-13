//dijkastra
#include<bits/stdc++.h>
#include<iterator>
#include<cstring>
using namespace std;
vector<pair<int,int> >v[100];

void dij(int source,int n)
{   
    int vis[n+1];
    vector<int>dis(n+1,1000000000);
    dis[source]=0;
    priority_queue<pair<int,int> ,vector<pair<int,int> >,greater<pair<int,int> > >pq;//min heap
    pq.push(make_pair(0,source));
    while(!pq.empty())
    {
        int node=pq.top().second;
        pq.pop();
        for(int i=0;i<v[node].size();i++)
        {
            int child=v[node][i].first;
            int distance=v[node][i].second;
            if(distance+dis[node]<dis[child]){
                dis[child]=distance+dis[node];
                pq.push(make_pair(dis[child],child));
            }
        }

    }

    for(int i=0;i<n;i++)cout<<dis[i]<<" ";



}
void work(){
    int n,m;
    cin>>n>>m;
    while(m--)
    {
        int x,y,d;
        cin>>x>>y>>d;
        v[x].push_back(make_pair(y,d));
        v[y].push_back(make_pair(x,d));
    }
    dij(0,n);
}
int main(){
    work();
    return 0;
}





//bellman
#include<bits/stdc++.h>
#include<iterator>
#include<cstring>
using namespace std;
vector<int>edge[100];
void bell(int source,int n,int m)
{   
    vector<int>dis(n+1,1000000000);
    dis[source]=0;
   for(int l=0;l<n-1;l++)
   {
    for(int i=0;i<m;i++)
    {
        int node=edge[i][0];
        int to=edge[i][1];
        int w=edge[i][2];

        if(dis[node]!=1000000000&&(dis[node]+w<dis[to]))
        {
            dis[to]=dis[node]+w;
        }
    }

   }
   //having negative cycle or not
   for(int i=0;i<m;i++)
   {
        int node=edge[i][0];
        int to=edge[i][1];
        int w=edge[i][2];

        if(dis[node]!=1000000000&&(dis[node]+w<dis[to]))
        {
            cout<<"-1";
            return ;
        }
   }
  

    for(int i=0;i<n;i++)cout<<dis[i]<<" ";

}
void work()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int x,y,d;
        cin>>x>>y>>d;
        edge[i].push_back(x);
        edge[i].push_back(y);
        edge[i].push_back(d);
        
    }
    bell(0,n,m);
}
int main(){
    work();
    return 0;
}



//floyed warshall (multiple source)
//floyed warshall
#include<bits/stdc++.h>
using namespace std;
#define inf 1000000000
int v[100][100];
void floyed(int n)
{
    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if((v[i][j]>v[i][k]+v[k][j])&&v[i][k]!=inf&&v[k][j]!=inf)
                {
                    v[i][j]=min(v[i][j],v[i][k]+v[k][j]);
                }
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(v[i][j]==inf)cout<<"0"<<" ";
            else cout<<v[i][j]<<" ";
        }
        cout<<"\n";

    }
}
void work(){
    int n,m;
    cin>>n>>m;
     for(int i=0;i<n;i++)
     {
        for(int j=0;j<n;j++)
        {
            if(i==j) v[i][j]=0;
           else v[i][j]=inf;
        }
     }
     while(m--)
     {
        int x,y,d;
        cin>>x>>y>>d;
        v[x][y]=d;
        //v[y][x]=d;
     }
     floyed(n);
}
int main(){
    work();
    return 0;
}
