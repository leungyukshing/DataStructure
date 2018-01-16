#include <iostream>
#include <vector>
using namespace std;

int main() {
  int testcase;
  cin >> testcase;
  while (testcase--) {
    int max_index = 0;
    int poly1[10000] = {0};
    int poly2[10000] = {0};
    int poly1_number;
    cin >> poly1_number;
    while (poly1_number--) {
      int co, in;
      cin >> co >> in;
      if (in > max_index) {
        max_index = in;
      }
      poly1[in] = co;
    }
    int poly2_number;
    cin >> poly2_number;
    while (poly2_number--) {
      int co, in;
      cin >> co >> in;
      if (in > max_index) {
        max_index = in;
      }
      poly2[in] = co;
    }
    int result[max_index];
    int count = 0;
    for (int i = 0; i < max_index; i++)
      result[i] = 0;
    for (int i = max_index; i >= 0; i--) {
      result[i] = poly1[i] + poly2[i];
      if (result[i] != 0) {
        count++;
      }

    }
    cout << count << endl;
    for (int i = max_index; i >= 0; i--) {
      if (result[i] != 0) {
        cout << result[i] << " " << i << endl;
      }

    }
  }
  return 0;
}