#include <bits/stdc++.h>

using namespace std;

int main()
{
    stack<int> st;
    string s;
    cout<<"Enter postfix expression : ";
    getline(cin,s);
    
    for (int i = 0; s[i]; ++i)
    {
        if (isdigit(s[i]))
            st.push(s[i] - '0');

        else
        {
            int val1 = st.top();
            st.pop();
            int val2 = st.top();
            st.pop();
            
            switch (s[i])
            {
            case '+': st.push(val2 + val1);
                      break;
            case '-': st.push(val2 - val1);
                      break;
            case '*': st.push(val2 * val1); 
                      break;
            case '/': st.push(val2/val1); 
                      break;
            }
        }
    }
    cout<<"Result : "<< st.top();
    return 0;
}
