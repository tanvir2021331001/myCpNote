//prims 
#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int> >v[100];
void mstprimes(int n,int m,int r)
{
     vector<int>vis(n,0);
     vector<pair<int,int> >edg;
     int sumw=0;
     priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >pq;
     pq.push(make_pair(0,r));
     while(!pq.empty())
     {
        int pdis=pq.top().first;
        int pnode=pq.top().second;
        pq.pop();
        if(vis[pdis]==1){
            continue;
        }
        vis[pnode]=1;
        sumw+=pdis;
        edg.push_back(make_pair(pnode,pdis));
        for(int i=0;i<v[pnode].size();i++){
            if(vis[v[pnode][i].first]==0){
                pq.push(make_pair(pdis+v[pnode][i].second,v[pnode][i].first));
        }
        }
     }
     cout<<"sum : "<<sumw<<"\n";
     for(int i=0;i<edg.size();i++)
     {
        cout<<edg[i].first<<"  " <<edg[i].second<<"\n";
     }

}
void work(){
int n,m;
cin>>n>>m;
for(int i=0;i<m;i++)
{
    int x,y,d;
    cin>>x>>y>>d;
    v[x].push_back(make_pair(y,d));
    v[y].push_back(make_pair(x,d));
}
mstprimes(n,m,5);
}
int main(){
    work();
    return 0;
}




//------------------------------------------------------------
//kruskal mst
#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
vector<int> srank(10,0), sizes(10,1), parent(10,0);
void create(int n)
{
       srank.resize(n+1,0);
       sizes.resize(n+1,0);
       parent.resize(n+1,0);
       for(int i=0;i<=n;i++)parent[i]=i;   
}
int ulti_parent(int n)
{
    if(parent[n]==n)return n;
   return parent[n]=ulti_parent(parent[n]);
}
void unionbyrank(int u,int v)
{
     int up=ulti_parent(u);
     int vp=ulti_parent(v);
     if(up==vp)return;
     if(srank[up]>srank[vp])
     {
        parent[vp]=up;
     }
     else if(srank[up]<srank[vp])
     {
        parent[up]=vp;
     }
     else 
     {
        parent[vp]=up;;
        srank[up]++;
     }
}

vector<pair<int,pair<int,int> > >v;

void kruskal(int n)
{
    int tresum=0;
    create(n);
    sort(v.begin(),v.end());
    for(int i=0;i<n;i++){
        int wt=v[i].first;
        int n1=v[i].second.first;
        int n2=v[i].second.second;
        if(ulti_parent(n1)==ulti_parent(n2))continue;
         unionbyrank(n1,n2);
         tresum+=wt;
         cout<<n1<<" "<<n2<<" "<<wt<<"\n";
    }

    cout<<tresum<<"\n";
}
void mst(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x,y,d;
        cin>>x>>y>>d;
        v.push_back(mp(d,mp(x,y)));//{distence,1stnode,2nd node}--for sort by distance 
    }
    kruskal(n);
}
int main(){

    mst();

    return 0;
}

