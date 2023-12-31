#include<bits/stdc++.h>
using namespace std;


struct node{
    int val;
    node *left,*right;
};

node* insert(node* root,int key){
    if(root==NULL)
    {
       node* newnode=new node();
       newnode->left=NULL;
       newnode->right=NULL;
       newnode->val=key;
       return newnode;
    }
    if(key>root->val)
    {
        root->right=insert(root->right,key);
    }
    else
    {
       root->left= insert(root->left,key);
    }

    return root;
}
//search
int search(node* root,int key)
{
  if(root==NULL)return 0;
  
  if(root->val==key)return 1;

  else if(key>root->val)return search(root->right,key);

  else return search(root->left,key);
}


int height(node* root)
{
    if(root==NULL)return 0;

    int h1=height(root->left);
    int h2=height(root->right);

    if(h1>h2)return h1+1;

    else return h2+1;

}


node* minvalue(node* root){
    node* temp=root;
    while(temp->left!=NULL){
        temp=temp->left;
    }
    return temp;
}


node* deletenode(node* root,int key){
     if(root==NULL)return root;
     if(key<root->val){
        root->left=deletenode(root->left,key);
     }
     else if(key>root->val){
        root->right=deletenode(root->right,key);
     }
     else {
          
          if(root->left==NULL){
            node* temp=root->right;
            free(root);
           return temp;
          }
          else if(root->right==NULL){
            node* temp=root->left;
            free(root);
            return temp;
          }
          else {
            node* temp= minvalue(root);
            root->val=temp->val;
            deletenode(temp->right,temp->val);
            
          }

     }
     return root;
}



void printlevel(node* root,int level){
    if(root==NULL)return;
    if(level==1){
        cout<<root->val<<" ";
        return;
    }
    printlevel(root->left,level-1);
    printlevel(root->right,level-1);
}


void inorder(node* root){
    if(root==NULL)return;
    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
}


void postorder(node* root){
    if(root==NULL)return ;
    postorder(root->left);
    postorder(root->right);
    cout<<root->val<<" ";
}


void preorder(node* root){
    if(root==NULL)return;
    cout<<root->val<<" ";
    preorder(root->left);
    preorder(root->right);
}


int main(){
      int n;
      cin>>n;

      int a[n];
      node *root=NULL;
      for(int i=0;i<n;i++)
      {
        cin>>a[i];
        root=insert(root,a[i]);
      }
      int k =height(root);
      root = deletenode(root,3);
      cout<<"height= "<<k<<"\n";
      for(int i=1;i<=k;i++){
         cout<<"level "<<i<<"\n";
         printlevel(root,i);
         cout<<"\n";
      }

    return 0;
}
