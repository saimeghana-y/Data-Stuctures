#include <bits/stdc++.h>
using namespace std;

struct Node
{
    Node * left;
    Node* right;
    int data;
};

Node* newNode(int key)
{
    Node* node=new Node();
    node->left = node->right = NULL;
    node->data=key;
    return node;
}

void topview(Node * root) {
    
        queue<pair<int,Node*>> q; 
        q.push(make_pair(0,root));
        
        map<int,Node*> ans;
        
        for(auto i=q.front();!q.empty();q.pop(),i=q.front()){
            
            if(!i.second) continue;
            
            ans.insert(i);
            
            q.push(make_pair(i.first+1,i.second->right));
            q.push(make_pair(i.first-1,i.second->left));
        }
        
        for(auto i:ans) cout<<i.second->data<<" ";
}

void insert(Node* temp, int key)
{
    queue<Node*> q;
    q.push(temp);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if (!temp->left) {
            temp->left = newNode(key);
            break;
        } else
            q.push(temp->left);

        if (!temp->right) {
            temp->right = newNode(key);
            break;
        } else
            q.push(temp->right);
    }
}

int main()
{
        int n;
  Node * head = 0;

  while(true){
    cin>>n;

    if(n == 0) break;
    if(head == 0) head = newNode(n);
    else
    insert(head,n);
  }

    cout<<"Top view of Binary Tree\n";
    topview(head);
    return 0;
    
}
