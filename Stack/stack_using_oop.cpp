#include <bits/stdc++.h>

using namespace std;

template <typename T>
struct Node
{
    T n;
    Node* next;
};

template <class T>
class Stack
{
private:
    Node<T>* top;
public:
    Stack();
    void push(T);
    T pop();
    void print();
};

template <class T> Stack<T>::Stack()
{
    top =0;
}

template <class T> void Stack<T>::push(T n)
{
    Node<T>* ptr = new Node<T>;
    ptr->n = n;
    ptr->next = top;
    top = ptr;
}

template <class T>
T Stack<T>::pop()
{
    if (top ==0)
        cout<<"Underflow";
    else{
        Node<T>* ptr = top;
        T n = ptr->n;
        top = top->next;
        free(ptr);
        return n;
    }
}

template <class T>
void Stack<T>::print()
{
    Node<T>* ptr = top;
    while (ptr != 0)
    {
        cout << ptr->n << "  ";
        ptr = ptr->next;
    }
}

int main()
{
    Stack<int> S;
    int c,n;
    do{
        cout<<"\nEnter choice:  1->Push  2->Pop  4->Print  0->Exit\n";
        cin>>c;
        switch(c){
            case 1: cout << "Enter the element to be entered. ";
                    cin >> n;
                    S.push(n);
                    break;

            case 2: S.pop();
                    break;

            case 4: S.print();
                    break;

            case 0: break;

            default: cout<<"Invalid Choice";
        }
    }while(c != 0);

    return 0;
}
