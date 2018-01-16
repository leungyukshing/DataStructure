#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
  int caseNumber;
  cin >> caseNumber;
  stack<char> st;
  while (caseNumber--) {
    string ss;
    cin >> ss;
    bool flag = false;

    while(st.empty()==false)st.pop();
    for (int i = 0; i < ss.size(); i++) {
      if (ss[i] == '{' || ss[i] == '(' || ss[i] == '[') {
        st.push(ss[i]);
      }
      else if (ss[i] == '}') {
        if(st.empty() || st.top() != '{') {
          flag = true;
          break;
        }
        else {
          st.pop();
        }
      }
      else if (ss[i] == ')') {
        if(st.empty() || st.top() != '(') {
          flag = true;
          break;
        }
        else {
          st.pop();
        }
      }
      else if (ss[i] == ']') {
        if(st.empty() || st.top() != '[') {
          flag = true;
          break;
        }
        else {
          st.pop();
        }
      }
    }
    if (!st.empty())
      flag = true;

    if (flag) {
      cout << "No" << endl;
    }
    else
      cout << "Yes" << endl;
  }
  return 0;
}