#include <iostream>
#include "timer.hpp"
using namespace std;

int byRecursion(int num) {
  if (num <= 0)
    return 0;
  else if (num == 1)
    return 1;
  else
    return byRecursion(num - 1) + byRecursion(num - 2);
}

int main() {
	Timer clock;

	int result = byRecursion(30);
	cout << "The time used is " << (float)clock.elapsed_time() << endl;
	cout << "The result is " << result << endl;
	return 0;
}