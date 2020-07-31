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

void leftView(Node* root)
{
    queue<Node*> q;

    if (root == NULL)
        return;

    q.push(root);

    q.push(NULL);

    while (!q.empty()) {
        Node* temp = q.front();

        if (temp) {

            cout << temp->data << " ";

            while (q.front() != NULL) {

                if (temp->left)
                    q.push(temp->left);

                if (temp->right)
                    q.push(temp->right);

                q.pop();

                temp = q.front();
            }

            q.push(NULL);
        }

        q.pop();
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

    leftView(head);
    return 0;
}
