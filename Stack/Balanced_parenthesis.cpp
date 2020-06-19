#include<bits/stdc++.h>
using namespace std;

int isBalanced(string str)
{
    stack<char> s;
    char x;

    for (int i=0; i<str.length(); i++)
    {
        if (str[i]=='('||str[i]=='['||str[i]=='{')
        {
            s.push(str[i]);
            continue;
        }
        if(s.size()>0){
        switch (str[i])
        {
        case ')':

            x = s.top();
            s.pop();
            if (x=='{' || x=='[')
                return 0;
            break;

        case '}':

            x = s.top();
            s.pop();
            if (x=='(' || x=='[')
                return 0;
            break;

        case ']':

            x = s.top();
            s.pop();
            if (x =='(' || x == '{')
                return 0;
            break;
        }
    }else return 0;
    }
    return (s.empty());
}

int main()
{
    
    string str;
    int n;
    cin>>n;
    while(n--){
        
        cin>>str;

        if (isBalanced(str))
        cout << "YES";
    else
        cout << "NO";

    cout<<endl;
    }

    return 0;
}
