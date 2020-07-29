#include <iostream>
using namespace std;

struct node{
  int data;
  node * left;
  node * right;
  node(int d){
    data = d;
    left = NULL;
    right = NULL;
  }
};


node * createNode(int x){
  node * temp = new node(x);
  return temp;
}

void inorder(node * temp){
  if(temp){
    inorder(temp -> left);
    cout<<temp -> data<<endl;
    inorder(temp -> right);
  }
}

void preorder(node * temp){
  if(temp){
    cout<<temp -> data<<endl;
    preorder(temp -> left);
    preorder(temp -> right);
  }
}

void postorder(node * temp){
  if(temp){
    postorder(temp -> left);
    postorder(temp -> right);
    cout<<temp -> data<<endl;
  }
}

node * createTree(){
  
  int n;
  node * a, * b, * c, * head = NULL;

  while(true){
    cin>>n;

    if(n == 0) break;

    a = createNode(n);

    if(head == NULL) head = a;
    else{
      b = head;
      while(b){
        c = b;
        if(b -> data == n){
          free(a);
          cout<<"duplicate";
          break;
        }else if(b -> data < n) 
              b = b -> right;
         else
              b = b -> left;
      }
      if(b == 0){
        if(c -> data < n) c -> right = a;
        else c -> left = a;
      }
    }
  }

  return head;
}

int totalNodes(node * temp){
  if(temp == 0) return 0;
  else if(temp -> left == 0 && temp -> right == 0) return 1;
  else return (1 + totalNodes(temp -> left) + totalNodes(temp -> right));
}

int leafNodes(node * temp){
  if(temp == 0) return 0;
  else if(temp -> left == 0 && temp -> right == 0) return 1;
  else return (leafNodes(temp -> left) + leafNodes(temp -> right));
}

int nonLeafNodes(node * temp){
  if(temp == 0) return 0;
  else if(temp -> left == 0 && temp -> right == 0) return 0;
  else return (1 + nonLeafNodes(temp -> left) + nonLeafNodes(temp -> right));
}

int height(node * temp){
  int l,r;
  if(temp == 0) return 0;
  else if(temp -> left == 0 && temp -> right == 0) return 1;
  else{
    l = height(temp -> left);
    r = height(temp -> right);
    return (1 + (l < r ? r : l));
  }
}

int complete(node * temp){
  int l,r;
  if(temp == 0) return 0;
  else if(temp -> left == 0 && temp -> right == 0) return 1;
  else{
    l = complete(temp -> left);
    r = complete(temp -> right);
    
    if( l == 1 || r == -1 || l != r) return -1;
    return (1 + l);
  }
}

int balance(node * temp){
    int l,r;
  if(temp == 0) return 0;
  else if(temp -> left == 0 && temp -> right == 0) return 1;
  else{
    l = balance(temp -> left);
    r = balance(temp -> right);
    
    if( l == 1 || r == -1 || l != r) return -1;
    return (1 + l<r ? r : l);
  }
}

int strict(node * temp){
  int l,r;
  if(temp == 0) return 0;
  else if(temp -> left == 0 && temp -> right == 0) return 1;
  else{
    l = strict(temp -> left);
    r = strict(temp -> right);
    
    return (l * r);
  }
}

int main(){
  node * tree;
  tree = createTree();

  cout<<"Total no.of nodes : "<<totalNodes(tree)<<endl;
  cout<<"Total no.of leaf nodes : "<<leafNodes(tree)<<endl;
  cout<<"Total no.of non-leaf nodes : "<<nonLeafNodes(tree)<<endl;
  cout<<"Height of the tree : "<<height(tree)<<endl;
  if(complete(tree))
    cout<<"Complete Binary Tree"<<endl;
  else
    cout<<"Not a Complete Binary Tree"<<endl;
  if(balance(tree))
    cout<<"Balanced Binary Tree"<<endl;
  else
    cout<<"Not a Balanced Binary Tree"<<endl;
  if(strict(tree))
    cout<<"Strict Binary Tree"<<endl;
  else
    cout<<"Not a Strict Binary Tree"<<endl;
  
  return 0;
}
