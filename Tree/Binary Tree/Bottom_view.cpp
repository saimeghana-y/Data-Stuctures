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

void bottomView(Node *root)
{
    if (root == NULL)
        return;

    int hd = 0;

    map<int, int> m;

    queue<Node *> q;

    root->hd = hd;
    q.push(root);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        hd = temp->hd;

        m[hd] = temp->data;

        if (temp->left != NULL)
        {
            temp->left->hd = hd-1;
            q.push(temp->left);
        }

        if (temp->right != NULL)
        {
            temp->right->hd = hd+1;
            q.push(temp->right);
        }
    }

    for (auto i = m.begin(); i != m.end(); ++i)
        cout << i->second << " ";
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


    cout<<"Bottom view of Binary Tree\n";
    bottomView(head);
    return 0;
}
