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
  ~treenode(){
      for(int i=0;i<children.size();i++){
             delete children[i];
      }
  }
};
void snexlarger(treenode<int>* root, treenode<int>*& first, treenode<int>*& second) {
    if (root == nullptr)
        return;

    if (first == nullptr)
        first = root;
    else if (root->data > first->data) {
        second = first;
        first = root;
    } else if (second == nullptr)
        second = root;
    else if (first->data > root->data && (second == nullptr || second->data < root->data)) {
        second = root;
    }

    for (int i = 0; i < root->children.size(); i++) {
        snexlarger(root->children[i], first, second);
    }
}

int snextlarger(treenode<int>* root) {
    treenode<int>* first = nullptr;
    treenode<int>* second = nullptr;
    snexlarger(root, first, second);

    if (second == nullptr)
        return 0;
    return second->data;
}

void nexlarger(treenode<int>* root,int val,int&ans){
      if (root == nullptr)
        return;

    if (root->data > val) {
        if (ans == 0 || root->data < ans) {
            ans = root->data;
        }
    }
 for(int i=0;i<root->children.size();i++){
        nexlarger(root->children[i], val, ans);
    }
}
int nextlarger(treenode<int>* root,int val){
    int ans=0;
    int temp;
    nexlarger(root,val,ans);
    return ans;
}
bool elefond(treenode<int>* root,int val){
    if (root==nullptr) return false;
    if(root->data==val) return true;
    bool ans;
    for(int i=0;i<root->children.size();i++){
    ans=elefond(root->children[i],val);
    if(ans)
    return ans;
    }
 return false;   
}
int countleafnodes(treenode<int>*root){
    if (root==nullptr) return 0;
    if(root->children.size()==0) return 1;int b =0 ;  
    for(int i=0;i<root->children.size();i++){
         b=countleafnodes(root->children[i])+b;
    }
    return b;
}
void printnodeatlevelk(treenode<int>* root,int k){
    if (root==nullptr) return ;
    if (k==0){ cout<<root->data<<" ";return ;}
    for (int i=0;i<root->children.size();i++){
         printnodeatlevelk(root->children[i],k-1); 
    }
    return;
}
int maxNode(treenode<int>* root){ if (root == nullptr) {
        return 0;
    }

    treenode<int>* maxNode = root;
    queue<treenode<int>*> q;
    q.push(root);

    while (!q.empty()) {
        treenode<int>* currentNode = q.front();
        q.pop();

        if (currentNode->data > maxNode->data) {
            maxNode = currentNode;
        }

        for (treenode<int>* child : currentNode->children) {
            q.push(child);
        }
    }

    return maxNode->data;
}
int heightnode(treenode<int>*root){
    if(root==nullptr) return 0;
    int height=0;
    for(int i=0;i<root->children.size();i++){
        int p=heightnode(root->children[i]);
         height=max(height,p);
    }
    return height+1;
}
int countnodes(treenode<int>* root){
    if(root->children.size()==0)
    return 1;
    int ans=0;
    for (int i=0;i<root->children.size();i++){
       ans=countnodes(root->children[i])+ans;
    }
    return ans+1;
}
int sunm(treenode<int>* root){
    if (root->children.size()==0) return root->data;
    int ans=root->data;
    for(int i=0;i<root->children.size();i++){
      ans=sunm(root->children[i])+ans;
    }
    return ans;
}
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
void preorder(treenode<int>* root){
    if(root==nullptr) return ;
    cout<<root->data;
     for(int i=0;i<root->children.size();i++){
        preorder(root->children[i]);
    }
    return ;
}
  void postorder(treenode<int>* root) {
    if (root == nullptr)
        return;

    for (int i = 0; i < root->children.size(); i++) {
        postorder(root->children[i]);
    }
    cout << root->data << " ";
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
    cout<<countnodes(op)<<endl;cout<<sunm(op);
    cout<<endl<<maxNode(op)<<endl;
    cout<<heightnode(op);
  cout<<"answer hai"<<endl;  printnodeatlevelk(op,2);
  cout<<"leafnode"<<countleafnodes(op);
 cout<<endl; preorder(op);cout<<endl;
  postorder(op);
cout<<"next larger"<<nextlarger(op,10)<<endl;
cout <<endl<<"second next larger"<<snextlarger(op);
  if(elefond(op,12)) cout<<"ofund"<<endl;
  else cout<<"no"<<endl;
  delete op;  
  return 0;
}/////////////////////////////////////////////////////////////////////////////////
