#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;
    Node* prev;
};

void deleteNode(Node ** head_ref,int pos)
{
    Node *del;
    int i;

    del = *head_ref;
    for(i=1; i<pos && del!=NULL; i++)
    {
        del = del->next;
    }
    if (*head_ref == del)
        *head_ref = del->next;

    /* Change next only if node to be
    deleted is NOT the last node */
    if (del->next != NULL)
        del->next->prev = del->prev;

    /* Change prev only if node to be
    deleted is NOT the first node */
    if (del->prev != NULL)
        del->prev->next = del->next;

    /* Finally, free the memory occupied by del*/
    free(del);
    return;
}

void push(Node** head_ref, int new_data)
{
    Node* new_node = new Node();
    new_node->data = new_data;

    new_node->prev = NULL;

    new_node->next = (*head_ref);

    if ((*head_ref) != NULL)
        (*head_ref)->prev = new_node;

    (*head_ref) = new_node;
}

void printList(Node* node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
}

int main()
{
    Node* head = NULL;
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

        cout<<"Modified Linked list is: ";
        printList(head);
        cout<<endl;

    }while(t != 0);

    return 0;
}
