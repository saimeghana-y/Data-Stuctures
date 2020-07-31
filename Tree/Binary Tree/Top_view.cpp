#include <bits/stdc++.h>
using namespace std;

struct Node
{
    Node * left;
    Node* right;
    int hd;
    int data;
};

Node* newNode(int key)
{
    Node* node=new Node();
    node->left = node->right = NULL;
    node->data=key;
    return node;
}

void topview(Node* root)
{
    if(root==NULL)
       return;
     queue<Node*>q;
     map<int,int> m;
     int hd=0;
     root->hd=hd;

    q.push(root);

    while(q.size())
    {
        hd=root->hd;

        if(m.count(hd)==0)
        m[hd]=root->data;
        if(root->left)
        {
            root->left->hd=hd-1;
            q.push(root->left);
        }
        if(root->right)
        {
            root->right->hd=hd+1;
            q.push(root->right);
        }
        q.pop();
        root=q.front();

    }



     for(auto i=m.begin();i!=m.end();i++)
    {
        cout<<i->second<<" ";
    }

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
