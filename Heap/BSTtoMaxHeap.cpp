#include <iostream>
#include <vector>

using namespace std;

struct Node { 
    int data; 
    Node *left, *right; 
    Node(int d){
        data = d;
        left = NULL;
        right = NULL;
      }
}; 

Node * createNode(int x){
  Node * temp = new Node(x);
  return temp;
} 

void inorder(Node* root, vector<int>& arr) 
{ 
    if (root == NULL) 
        return; 
        
    inorder(root->left, arr);
    
    arr.push_back(root->data); 
    
    inorder(root->right, arr); 
} 

void postorder(Node* root) 
{ 
    if (!root) 
        return; 
  
    postorder(root->left); 
  
    postorder(root->right); 
  
    cout << root->data << " "; 
} 

void MaxHeap(Node* root, vector<int> arr, int* i) 
{ 
    if (root == NULL) 
        return; 
  
    MaxHeap(root->left, arr, i); 
    MaxHeap(root->right, arr, i); 
  
    root->data = arr[++*i]; 
}  


int main()
{
  int n;
  Node * a, * b, * c, * head = NULL;

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

  vector<int> arr; 
    int i = -1; 
  
    inorder(head, arr);
    MaxHeap(head, arr, &i);
    postorder(head);
  
  return 0;
}
