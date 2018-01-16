#include <iostream>
#include <cstring>
#include <stack>
#include <string>
#include <vector>
using namespace std;

class CalculatorPro {
public:
  CalculatorPro();
  
private:
  void read();
  bool isoperator(char op);
  int priority(char op);
  void postfix();
  double read_number(char str[], int *i); 
  double compute();
  vector<char> pre;
  char post[100];
  int size; 
};

CalculatorPro::CalculatorPro() {
  size = 0;
  read();
  postfix();
  //cout << post << endl;
  cout << compute() << endl;
}

void CalculatorPro::read() {
  string temp;
  cout << "Please input the expression(end with '='): ";
  cin >> temp;
  for (int i = 0; i < temp.size(); i++) {
    char ch = temp[i];
    pre.push_back(ch);
  }
  
  if (pre[0] == '-') {
    pre.insert(pre.begin(), '0');
  }
  for (int i = 0; i < pre.size(); i++) {
    if (pre[i] == '(' && pre[i+1] == '-') {
      pre.insert(pre.begin()+i+1, '0');
    }
  }
}

bool CalculatorPro::isoperator(char op) {
  switch(op) {
    case '+':
    case '-':
    case '*':
    case '/': return 1;
    default:
    return 0; 
  }
}

int CalculatorPro::priority(char op) {
  switch(op) {
    case '=':
      return -1;
    case '(':
      return 0;
    case '+':
    case '-':
      return 1;
    case '*':
    case '/':
      return 2;
    default:
      return -1;
  }
}

void CalculatorPro::postfix() {
  int i = 0, j = 0;
  stack<char> st; // used to store operators
  st.push('=');
  
  while(pre[i] != '=') {
    // judge whether it is a number(both int and double)
    if ((pre[i] >= '0' && pre[i] <= '9') || pre[i] == '.') {
      post[j++] = pre[i];
      size++;
    }
    else if (pre[i] == '(') {
      st.push(pre[i]);
    }
    else if (pre[i] == ')') {
      while (st.top() != '(') {
        post[j++] = st.top();
        st.pop();
        size++;
      }
      st.pop(); // pop the'('
    }
    else if (isoperator(pre[i])) {
      post[j++] = ' ';
      size++;
      while (priority(pre[i]) <= priority(st.top())) {
        post[j++] = st.top();
        st.pop();
        size++;
      }
      st.push(pre[i]);
    }
    
    i++;
  }
  while (!st.empty()) {
    post[j++] = st.top();
    st.pop();
    size++;
  }
}

double CalculatorPro::read_number(char str[], int *i) {
  double x = 0;
  int k = 0;
  while (str[*i] >= '0' && str[*i] <= '9') {
    x = x*10 + (str[*i] - '0');
    (*i)++;
  }

  // decimal part
  if (str[*i] == '.') {
    (*i)++;
    while (str[*i] >= '0' && str[*i] <= '9') {
      x = x * 10 + (str[*i] - '0');
      (*i)++;
      k++;
    }
  }
  while(k != 0) {
    x /= 10.0; // move decimal point
    k--;
  }
  
  return x;
}

double CalculatorPro::compute() {
  stack<double> st_num;
  int i = 0;
  double op1, op2;
  
  while (post[i] != '=') {
    if (post[i] >= '0' && post[i] <= '9') {
      st_num.push(read_number(post,&i));
    }
    else if (post[i] == ' ') {
      i++;
    }
    else if (post[i] == '+') {
      op2 = st_num.top();
      st_num.pop();
      op1 = st_num.top();
      st_num.pop();
      st_num.push(op1 + op2);
      i++;
    }
    else if (post[i] == '-') {
      op2 = st_num.top();
      st_num.pop();
      op1 = st_num.top();
      st_num.pop();
      st_num.push(op1 - op2);
      i++;
    }
    else if (post[i] == '*') {
      op2 = st_num.top();
      st_num.pop();
      op1 = st_num.top();
      st_num.pop();
      st_num.push(op1 * op2);
      i++;
    }
    else if (post[i] == '/') {
      op2 = st_num.top();
      st_num.pop();
      op1 = st_num.top();
      st_num.pop();
      st_num.push(op1 / op2);
      i++;
    }
    else {
      exit(0);
    }
  }
  
  return st_num.top();
}


int main() {
  CalculatorPro ca;
  return 0;
}