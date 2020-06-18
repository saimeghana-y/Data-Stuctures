#include <bits/stdc++.h>

using namespace std;

    queue <int> q;
    stack <int> s;

void print(queue<int> q)
{

    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

void reverseQ(){
    while (!q.empty())
    {
        s.push(q.front());
        q.pop();
    }

    while (!s.empty())
    {
        q.push(s.top());
        s.pop();
    }
}

int main()
{
    int c,n;
    do{
        cout<<"\nEnter choice:  1->Enqueue  2->Dequeue 3->DisplayQueue 4->ReverseQueue 0->Exit\n";
        cin>>c;
        switch(c){
            case 1: cout << "Enter the element to be entered : ";
                    cin >> n;
                    q.push(n);
                    break;

            case 2: cout<<q.front();
                    q.pop();
                    break;
                    
            case 3: print(q);
                    break;

            case 4: reverseQ();
                    print(q);
                    break;

            case 0: break;

            default: cout<<"Invalid Choice";
        }
    }while(c != 0);

    return 0;
}
