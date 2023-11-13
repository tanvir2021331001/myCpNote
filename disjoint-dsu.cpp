//disjoint set union
#include<bits/stdc++.h>
using namespace std;
vector<int> srank(10,0), sizes(10,1), parent(10,0);
void create(int n){
       srank.resize(n+1,0);
       sizes.resize(n+1,0);
       parent.resize(n+1,0);
       for(int i=0;i<=n;i++)parent[i]=i;   
}
int ulti_parent(int n){
    if(parent[n]==n)return n;
   return parent[n]=ulti_parent(parent[n]);
}
void unionbyrank(int u,int v){
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
     else {
        parent[vp]=up;;
        srank[up]++;
     }
}
void unionbysize(int u,int v)
{
     int up=ulti_parent(u);
     int vp=ulti_parent(v);
     if(up==vp)return;
     if(sizes[up]>=sizes[vp])
     {
        parent[vp]=up;
        sizes[up]=sizes[vp];
     }
     else
     {
        parent[up]=vp;
        sizes[vp]+=sizes[up];
     }
}

void disjoint(){
    int n;
    cin>>n;
    create(n);  //create disjoint set union
    for(int i=0;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        unionbyrank(x,y);
    }
    if(ulti_parent(2)==ulti_parent(3))
    {
        cout<<"same\n";
    }
    else cout<<"not same\n";

}
int main(){
    disjoint();
    return 0;
}
