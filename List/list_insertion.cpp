#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node *next;
};

void atBegin(Node** head_ref, int new_data)
{
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void insertAfter(Node* prev_node, int new_data)
{
    if (prev_node == NULL)
    {
        cout<<"the given previous node cannot be NULL";
        return;
    }

    Node* new_node = new Node();

    new_node->data = new_data;

    new_node->next = prev_node->next;

    prev_node->next = new_node;
}
void atEnd(Node** head_ref, int new_data)
{
    Node* new_node = new Node();

    Node *last = *head_ref;

    new_node->data = new_data;

    new_node->next = NULL;

    if (*head_ref == NULL)
    {
        *head_ref = new_node;
        return;
    }

    while (last->next != NULL)
        last = last->next;

    last->next = new_node;
    return;
}

void printList(Node *node)
{
    while (node != NULL)
    {
        cout<<" "<<node->data;
        node = node->next;
    }
}
int main()
{
    Node* head = NULL;
    int n,t;
    do{
        cout<<"Enter \n1 -> insert at the end\n2 -> insert at beginning\n3 -> insert after a position\n0 -> Exit"<<endl;
        cin>>t;
        switch(t){
            case 1:cout<<"Enter element"<<endl;
                    cin>>n;
                    atEnd(&head,n);
                    break;
            case 2:cout<<"Enter element"<<endl;
                    cin>>n;
                    atBegin(&head,n);
                    break;
            case 3:cout<<"Enter element"<<endl;
                    cin>>n;
                    insertAfter(head -> next,n);
                    break;
            case 0: break;
        }

        cout<<"Created Linked list is: ";
        printList(head);
        cout<<endl;

    }while(t != 0);
    return 0;
}
