#include <iostream>
#include <stack>
#include <string>
#include <cstdlib>
using namespace std;

class Calculator {
public:
  Calculator();
  void parse();
private:
  stack<double> data;
  stack<char> operate;
  bool compare(char ch1, char ch2);
  double compute(double num1, double num2, char op);
};

Calculator::Calculator() {
  parse();
}

void Calculator::parse() {
  string input;
  cin >> input;
  for (int i = 0; i < input.size(); i++) {
    // is digit
    if (input[i] >= '0' && input[i] <= '9') {
      string num;
      int j;
      for (j = i; j < input.size(); j++) {
        if ((input[j] >= '0' && input[j] <= '9') || input[j] == '.') {
          num += input[j];
        }
        else {
          break;
        }
      }
      data.push(atof(num.c_str()));
      i = j-1;
    }
    // is operator
    else if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/') {
      if (operate.empty()) {
        operate.push(input[i]);
      }
      else {
        char top = operate.top();
        if (compare(input[i], top)) {
          operate.pop();
          double num1 = data.top();
          data.pop();
          double num2= data.top();
          data.pop();
          
          double result = compute(num2, num1, input[i]);
          data.push(result);
        }
        else {
          operate.push(input[i]);
        }
      }
    }
    else {
      cout << "Wrong input" << endl;
    }
  }
  
  while (!operate.empty()) {
    double num1 = data.top();
    data.pop();
    double num2= data.top();
    data.pop();
    char ch = operate.top();
    operate.pop();
    
    double result = compute(num2, num1, ch);
    data.push(result);
  }
  
  cout << data.top() << endl;
}

bool Calculator::compare(char ch1, char ch2) {
  if ((ch1 == '+' || ch1 == '-') && (ch2 == '*' || ch2 == '/')) {
    return true;
  }
  return false;
}

double Calculator::compute(double num1, double num2, char op) {
  if (op == '+') {
    return num1+num2;
  }
  else if (op == '-') {
    return num1-num2;
  }
  else if (op == '*') {
    return num1 * num2;
  }
  else if (op == '/') {
    return num1 * 1.0 / num2;
  }
}


int main() {
  Calculator c1;
  return 0;
}