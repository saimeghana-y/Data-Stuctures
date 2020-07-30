#include <iostream>

using namespace std;

class Node{
public:
    int data;
    Node * left;
    Node * right;
    int height;
};

int maximum(int a,int b){
    return (a > b) ? a : b;
}

int height(Node * n){
    if(!n) return 0;
    return n -> height;
}

Node * newNode(int n){
    Node * temp = new Node();
    temp -> data = n;
    temp -> left = NULL;
    temp -> right = NULL;
    temp -> height = 1;

    return temp;
}

int getBalance(Node * temp){
    if(temp == NULL) return 0;
    return height(temp -> left) - height(temp -> right);
}

Node * rightRotate(Node * y){
    Node * x = y -> left;
    Node * t = x -> right;
    x -> right = y;
    y -> left = t;
    y -> height = 1 + maximum(height(y -> left),height(y -> right));
    x -> height = 1 + maximum(height(x -> left),height(x -> right));

    return x;
}


Node * leftRotate(Node * x){
    Node * y =x -> right;
    Node * t = y -> left;
    y -> left = x;
    x -> right = t;
    y -> height = 1 + maximum(height(y -> left),height(y -> right));
    x -> height = 1 + maximum(height(x -> left),height(x -> right));

    return y;
}

Node* insert(Node* node, int key)
{
    if (node == NULL)
        return(newNode(key));

    if (key < node->data)
        node->left = insert(node->left, key);
    else if (key > node->data)
        node->right = insert(node->right, key);
    else
        return node;

    node->height = 1 + maximum(height(node->left),
                        height(node->right));

    int balance = getBalance(node);

    if (balance > 1 && key < node->left->data)
        return rightRotate(node);
    if (balance < -1 && key > node->right->data)
        return leftRotate(node);
    if (balance > 1 && key > node->left->data)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if (balance < -1 && key < node->right->data)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

void preOrder(Node *root)
{
    if(root != NULL)
    {
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main()
{
    Node *root = NULL;
    int n,ch = 1;

    cout<<"Enter 1 to add element and 0 to exit"<<endl;
    while(ch){
        cin>>n;
        root = insert(root,n);
        cin>>ch;
    }
    preOrder(root);

    return 0;
}
