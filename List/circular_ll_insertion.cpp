#include <iostream>

using namespace std;

struct node{
    int data;
    node * next;
    node(int d){
        data = d;
        next = NULL;
    }
}*tail;

int getLength(){
    int c = 0;
    node *temp = tail;
    if (tail != NULL)
    {
        do
        {
            c++;
            temp = temp->next;
        }
        while (temp != tail);
    }
    return c;
}

void push(){
    cout<<"\nEnter element"<<endl;
    int n;cin>>n;
    node * newnode = new node(n);

    if(tail == 0){
        tail = newnode;
        tail -> next = newnode;
    }else{
        newnode -> next = tail -> next;
        tail -> next = newnode;
    }
}
void append(){
    cout<<"\nEnter element"<<endl;
    int n;cin>>n;
    node * newnode = new node(n);

    if(tail == 0){
        tail = newnode;
        tail -> next = newnode;
    }else{
        newnode -> next = tail -> next;
        tail -> next = newnode;
        tail = newnode;
    }
}

void insertatPos(){
    cout<<"\nEnter position"<<endl;
    int pos;cin>>pos;
    int i = 1;
    int l = getLength();
    if(pos <0 || pos>l){
        cout<<"invalid position"<<endl;
        return;
    }
    else if(pos == 1){
        push();
    }else{
        cout<<"\nEnter element"<<endl;
        int n;cin>>n;
        node * newnode = new node(n);
        node *temp;
        temp = tail -> next;
        while(i < pos - 1){
            temp = temp -> next;
            i++;
        }
        newnode -> next = temp -> next;
        temp -> next = newnode;
    }
}
void printList(node *tail)
{
    node *temp = tail;
    if (tail != NULL)
    {
        do
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        while (temp != tail);
    }
}
int main()
{
    int n,t;
    do{
        cout<<"Enter \n1 -> add element at beginning\n2 -> add element at end\n3 -> add element at a position\n0 -> Exit"<<endl;
        cin>>t;
        switch(t){
            case 1:push();
                    break;
            case 2:append();
                    break;
            case 3:insertatPos();
                    break;
            case 0: break;
        }

        cout<<"Modified Linked list is: ";
        printList(tail);
        cout<<endl;

    }while(t != 0);
    return 0;
}
