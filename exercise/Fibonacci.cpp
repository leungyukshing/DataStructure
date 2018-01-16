#include <iostream>
#include <time.h>
using namespace std;

int byLoop(int num) {
  int last_but_one;
  int last_value;
  int sum = 0;
  
  if (num <= 0)
    return 0;
  else if (num == 1)
    return 1;
  else {
    last_but_one = 0;
    last_value = 1;
    for (int i = 2; i <= num; i++) {
      sum = last_but_one + last_value;
      last_but_one = last_value;
      last_value = sum;
    }
    return sum;
  }
  
}

int byRecursion(int num) {
  if (num <= 0)
    return 0;
  else if (num == 1)
    return 1;
  else
    return byRecursion(num - 1) + byRecursion(num - 2);
}

int main() {
  clock_t startTime, endTime;
  cout << "[1] Calculate Fibonacci By Loop" << endl;
  cout << "[2] Calculate Fibonacci By Recursion" << endl;

  char choice = 0;
  cin >> choice;
  cout << "Please input the number: ";
  int number = 0;
  cin >> number;
  switch(choice) {
    case '1':
      startTime = clock();
      cout << "The result is " << byLoop(number) << endl;
      endTime = clock();
      cout << "The loop function runs in " << (double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
      break;
    case '2':
      startTime = clock();
      cout << "The result is " << byRecursion(number) << endl;
      endTime = clock();
      cout << "The recursion function runs in " << (double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
      break;
    default:
      break;
  }

  return 0;
}