#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

void push(Node** head_ref, int new_data)
{
    struct Node* new_node = new Node;
    new_node->data  = new_data;
    new_node->next = (*head_ref);
    (*head_ref)    = new_node;
}

void deleteNode(Node **head_ref, int key)
{
    Node* temp = *head_ref, *prev;

    if (temp != NULL && temp->data == key)
    {
        *head_ref = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) return;

    prev->next = temp->next;

    free(temp);
}

void printList(Node *node)
{
    while (node != NULL)
    {
        printf(" %d ", node->data);
        node = node->next;
    }
}

int main()
{
    struct Node* head = NULL;
    int n,t;
    do{
        cout<<"Enter \n1 -> add element\n2 -> delete node\n0 -> Exit"<<endl;
        cin>>t;
        switch(t){
            case 1:cout<<"Enter element :"<<endl;
                    cin>>n;
                    push(&head,n);
                    break;
            case 2:cout<<"Enter node to be deleted :"<<endl;
                    cin>>n;
                    deleteNode(&head,n);
                    break;
            case 0: break;
        }

        cout<<"Linked list is: ";
        printList(head);
        cout<<endl;

    }while(t != 0);
    return 0;
}
