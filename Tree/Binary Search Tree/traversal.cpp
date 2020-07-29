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

//recursive insertion

/*

void insertBST(node ** head,node * temp){
  if(*head == 0) *head = temp;
  else if((*head) -> data < temp -> data) insertBST(&(*head) -> right,temp);
  else insertBST(&(*head) -> left, temp);
}

*/

int main(){

  int n;
  node * a, * b, * c, * head = NULL;

  while(true){
    cin>>n;

    if(n == 0) break;
    
    //insertBST(&head,createNode(n));
    
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

  cout<<endl<<"Inorder traversal"<<endl;
  inorder(head);

  cout<<endl<<"PreOrder traversal"<<endl;
  preorder(head);
  
  cout<<endl<<"PostOrder traversal"<<endl;
  postorder(head);

  return 0;
}
