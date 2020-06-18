#include <bits/stdc++.h>
using namespace std;

struct Queue {
    stack<int> s1, s2;

    void enQueue(int x)
    {
        s1.push(x);
    }

    int deQueue()
    {
        if (s1.empty() && s2.empty()) {
            cout << "Q is empty";
            exit(0);
        }

        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }

        int x = s2.top();
        s2.pop();
        return x;
    }
};

int main()
{
    Queue Q;
    int c,n;
    do{
        cout<<"\nEnter choice:  1->Enqueue  2->Dequeue 0->Exit\n";
        cin>>c;
        switch(c){
            case 1: cout << "Enter the element to be entered. ";
                    cin >> n;
                    Q.enQueue(n);
                    break;

            case 2: cout<<Q.deQueue();
                    break;

            case 0: break;

            default: cout<<"Invalid Choice";
        }
    }while(c != 0);
    return 0;
}
