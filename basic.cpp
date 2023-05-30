#include <bits/stdc++.h>
using namespace std;
template<typename T>

class treenode{
  public:
  T data;
  vector<treenode<T>*> children ;
  
  treenode(T data){
      this->data=data;
  }
};

treenode<int>* inputree(){
    int data;
    cout<<"enter the data"<<endl;
    cin>>data;
    treenode<int>* newnode=new treenode<int>(data);
    int n;
    cout<<"enter the no of children nodes"<<endl;
    cin>>n;
    for(int i=0;i<n;i++){
       treenode<int>*g= inputree();
       newnode->children.push_back(g);
    }
    return newnode;
}
void printnode(treenode<int>* root){
    if (root==NULL){
        return;
    }
    cout<<root->data<<":";
    for(int u=0;u<root->children.size();u++){
        cout<<root->children[u]->data<<",";
    }
    cout<<endl;
    for(int i=0;i<root->children.size();i++){
        printnode(root->children[i]);
    }
}
int main(){
    // treenode<int> * root=new treenode<int>(10);
    // treenode<int> * ch1=new treenode<int>(23);
    // treenode<int> * ch2=new treenode<int>(78);
    // root->children.push_back(ch1);
    // root->children.push_back(ch2);
    treenode<int>*op=inputree();
    printnode(op);
    return 0;
}
