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
void printlevelwise(treenode<int>* root){
       queue<treenode<int>*> printmadi;
       printmadi.push(root);
       while(!printmadi.empty()){
           treenode<int>*p=printmadi.front();
           printmadi.pop();
           cout<<p->data<<":";
           for(int i=0;i < p->children.size();i++){
               treenode<int>* temp=p->children[i];
               cout<<temp->data<<",";
               printmadi.push(temp);
           }
           cout<<endl;
       }
}
treenode<int >* inputsahi(){
    int rootdata;
    cout<<"enter the data"<<endl;
    cin>>rootdata;
    treenode<int>* rootnode=new treenode<int>(rootdata);
    queue<treenode<int>*> dalo;
    dalo.push(rootnode);
    while(!dalo.empty()){
        treenode<int>* front=dalo.front();
    cout<<"enter the number of childnodes of "<<front->data<<endl;
    int l;
    cin>>l;
  
    dalo.pop();
    for (int i=0;i<l;i++){
      int data;
      cout<<"data"<<endl;
      cin>>data;
      treenode<int>* childnode=new treenode<int>(data);
      front->children.push_back(childnode);
      dalo.push(childnode);
    }
  }
    return rootnode;
}

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
    treenode<int>*op=inputsahi();
    printnode(op);
    printlevelwise(op);
    return 0;
}
