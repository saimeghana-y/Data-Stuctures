#include <iostream>
using namespace std;

struct stack{
    int data;
    stack * next;
};

void initStack(stack **s){
    *s=NULL;
}

void push(stack **s,int x){
    stack * n = new stack;
    n -> data = x;
    n -> next = *s;
    *s = n;
}

void print(stack *s)
{
    while (s != 0)
    {
        cout << s->data << "  ";
        s = s->next;
    }
    cout<<"\n";
}

int isEmpty(stack *s){
    if(s==NULL)
        return 1;
    return 0;
}

int top(stack *s){
    return (s -> data);
}

int pop(struct stack **s)
{
    int x;
    struct stack *temp;

    x = (*s)->data;
    temp = *s;
    (*s) = (*s)->next;
    delete temp;

    return x;
}

void sortInsert(stack **s,int x){

    if(isEmpty(*s) || x>top(*s)){
        push(s,x);
        return;
    }
    
    int temp = pop(s);
    sortInsert(s,x);
    push(s,temp);
}

void sortStack(stack **s){

    if(!isEmpty(*s)){
        int temp = pop(s);
        sortStack(s);
        sortInsert(s,temp);
    }
    
}

int main()
{
    stack * t;
    initStack(&t);
    
    int l;
    cout<<"Enter size of stack\n";
    cin >> l;
    
    cout<<"Enter elements ;\n";
    while (l--)
    {
        int num;
        cin >> num;
        push(&t,num);
    }
    
    cout<<"Stack before sorting:\n";
    print(t);
    
    sortStack((&t));
    
    cout<<"Stack after sorting:\n";
    print(t);

    return 0;
}
