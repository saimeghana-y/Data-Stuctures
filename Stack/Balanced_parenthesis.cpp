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
    }

    return (s.empty());
}

int main()
{
    string str;
    getline(cin,str);

    if (isBalanced(str))
        cout << "Balanced";
    else
        cout << "Not Balanced";
    return 0;
}
