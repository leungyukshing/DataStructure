#include <iostream>
#include <iomanip>
#include <stack>
using namespace std;
bool isNumber(char ch) {
  return ch <= 'z' && ch >= 'a';
}

double calculate(string exp) {
  stack<double> st;
  for (int i = 0; i < exp.size(); i++) {
    if (isNumber(exp[i])) {
      st.push(exp[i]-'a'+1);
    }
    else {
      switch (exp[i]) {
        case '+':{
          double add1 = st.top();
          st.pop();
          double add2 = st.top();
          st.pop();
          double add_result = add1 + add2;
          st.push(add_result);
          break;}
        case '-':{
          double subtract1 = st.top();
          st.pop();
          double subtract2 = st.top();
          st.pop();
          double subtract_result = subtract2 - subtract1;
          st.push(subtract_result);
          break;}
        case '*':{
          double multiply1 = st.top();
          st.pop();
          double multiply2 = st.top();
          st.pop();
          double multiply_result = multiply1 * multiply2;
          st.push(multiply_result);
          break;}
        case '/':{
          double divide1 = st.top();
          st.pop();
          double divide2 = st.top();
          st.pop();
          double  divide_result = (divide2*1.0) / divide1;
          st.push(divide_result);
          break;}
      }
    }
  }
  return st.top();
}
int main() {
  int testcase = 0;
  cin >> testcase;
  while (testcase--) {
    string exp;
    cin >> exp;
    //exp.append('=');
    double result = calculate(exp);
    cout << fixed << setprecision(2) << result << endl;
  }
  return 0;
}