#include<bits/stdc++.h>
using namespace std;
const int n=6;
int arr[n+4],tree[4*n];
void build(int node ,int l,int r){
  if(l>=r){
    tree[node]=arr[r];
    return;
  }
  int mid=(l+r)/2;
  int left=2*node;
  int right=2*node+1;
  build(left,l,mid);
  build(right,mid+1,r);
  tree[node]=tree[left]+tree[right];
}
int query(int node,int l,int r,int i,int j){
    if(j<l||i>r){
        return 0;
    }
    if(l>=i&& r<=j){
        return tree[node];
    }
    int mid =(l+r)/2;
    int left=2*node,right=2*node+1;
    return (query(left,l,mid,i,j)+query(right,mid+1,r,i,j));
}
void update(int node,int l,int r,int idx,int x){
    if(idx>r||idx<l)return;
     if(l==idx&&r==idx){
        tree[node]=x;
        return;
     }
     int mid =(l+r)/2;
     int left=2*node;
     int right=2*node+1;
     update(left,l,mid,idx,x);
     update(right,mid+1,r,idx,x);
     tree[node]=tree[left]+tree[right];
}
void segmentt(){
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
   build(1,1,n);
   update(1,1,n,2,0);
   cout<<query(1,1,n,1,3)<<"\n";
   update(1,1,n,2,2);
   cout<<"q ans: "<<query(1,1,n,1,3)<<"\n";
   for(int i=1;i<4*n;i++){
    cout<<tree[i]<<" ";
   }
   cout<<"\n";
}
int main(){
    segmentt();
    return 0;
}
/*
build(node,l,r)
base l==r
evaluate left,right,mid
build recursion left,right
tree update
//
int query(node,l,r,i,j)
if completely outside 
if completely inside
left,root,right
return querery left+right
//
update(node,l,r,idx,x)
if(outside)
if equal
left right update call
tree update



*/
