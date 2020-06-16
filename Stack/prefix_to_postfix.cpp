#include <bits/stdc++.h>
using namespace std;

bool isOperator(char x) {
  switch (x) {
  case '+':
  case '-':
  case '/':
  case '*':
    return true;
  }
  return false;
}


int main() {

  string pre;
  getline (cin, pre);
  stack<string> s;

  for (int i = pre.size() - 1; i >= 0; i--) {

    if (isOperator(pre[i])) {

      string op1 = s.top(); s.pop();
      string op2 = s.top(); s.pop();

      string temp = op1 + op2 + pre[i];

      s.push(temp);
    }

    else
      s.push(string(1, pre[i]));

  }
  cout << "Postfix : " << s.top();
  return 0;
}
