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

void rightView(Node* root)
{
    if (!root)
        return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty())
    {
        int n = q.size();

        for(int i = 1; i <= n; i++)
        {
            Node* temp = q.front();
            q.pop();

            if (i == n)
                cout<<temp->data<<" ";

            if (temp->left != NULL)
                q.push(temp->left);

            if (temp->right != NULL)
                q.push(temp->right);
        }
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

    rightView(head);
    return 0;
}
