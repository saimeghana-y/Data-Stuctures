#include<iostream>

using namespace std;

struct Node{
    int data;
    Node *next;
};

class Queue{
    public:
    Node *front,*rear;
    Queue(){
        front=rear=NULL;
    }

    void enqueue(int n);
    void dequeue();
    void display();
    ~Queue();
};

void Queue::enqueue(int n){
    Node *temp=new Node;

    temp->data=n;
    temp->next=NULL;

    if(front==NULL){
        front=rear=temp;
    }
    else{
        rear->next=temp;
        rear=temp;
    }
}

void Queue::display(){
    if(front==NULL){
        cout<<"Underflow."<<endl;
        return;
    }
    Node *temp=front;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

void Queue :: dequeue()
    {
    if (front==NULL){
        cout<<"underflow"<<endl;
        return;
    }

    if(front==rear)
        front=rear=NULL;
    else
        front=front->next;
}

Queue ::~Queue()
{
    while(front!=NULL)
    {
        Node *temp=front;
        front=front->next;
        delete temp;
    }
    rear=NULL;
}


int main(){
    Queue Q;
    int c,n;
    do{
        cout<<"\nEnter choice:  1->Enqueue  2->Dequeue  4->Print  0->Exit\n";
        cin>>c;
        switch(c){
            case 1: cout << "Enter the element to be inserted : ";
                    cin >> n;
                    Q.enqueue(n);
                    break;

            case 2: Q.dequeue();
                    break;

            case 4: Q.display();
                    break;

            case 0: break;

            default: cout<<"Invalid Choice";
        }
    }while(c != 0);
    return 0;
}
