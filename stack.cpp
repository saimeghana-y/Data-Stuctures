#include <bits/stdc++.h>
using std::cout;
using std::cin;
#define N 5
int stack[N];
int top = -1;
int x;
void push(){
    int x;
    cout<<"Enter integer to be pushed into stack";
    cin>>x;
    if(top==N-1)
        cout<<"overflow";
    else{
        top++;
        stack[top] = x;
    }
}
void pop(){
    if(top==-1)
        cout<<"underflow";
    else{
        x = stack[top];
        top--;
        cout<<x;
    }
}
void peek(){
    if(top == -1)
        cout<<"Stack is empty";
    else
        cout<<stack[top];
}
void print(){
    if(top == -1)
        cout<<"Stack is empty";
    int i;
    for(i=top;i>=0;i--)
        cout<<stack[i]<<" ";
}
void srchElement(){
    int i,t;
    if(top == -1)
        cout<<"Stack is empty";
    cout<<"Enter element to be searched for";
    cin>>t;
    for(i=top;i>=0;i--){
        if(stack[i]==t)
            cout<<t<<" is present at position "<<top-i<<" ";
    }

}
int main()
{
    int c;
    do{
        cout<<"\nEnter choice:\t1->Push\t2->Pop\t3->Peek\t4->Print\t5->Search\t0->Exit\n";
        cin>>c;
        switch(c){
            case 1: push();
                    break;

            case 2: pop();
                    break;

            case 3: peek();
                    break;

            case 4: print();
                    break;

            case 5: srchElement();
                    break;

            case 0: break;

            default: cout<<"Invalid Choice";
        }
    }while(c != 0);

    return 0;
}
