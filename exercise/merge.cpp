#include <iostream>
using namespace std;

int main() {
  int arr1[5] = {0};
  int arr2[5] = {0};
  int arr3[10] = {0};

  for (int i = 0; i < 5; i++) 
    cin >> arr1[i];
  for (int i = 0; i < 5; i++)
    cin >> arr2[i];

  int index1 = 0;
  int index2 = 0;
  int index3 = 0;

  while (index1 < 5 && index2 < 5) {
    if (arr1[index1] < arr2[index2]) {
      arr3[index3] = arr1[index1];
      index1++;
      index3++;
    }
    else {
      arr3[index3] = arr2[index2];
      index2++;
      index3++;
    }
  }

  while (index1 < 5) {
    arr3[index3] = arr1[index1];
    index3++;
    index1++;
  }

  while (index2 < 5) {
    arr3[index3] = arr2[index2];
    index2++;
    index3++;
  }

  for (int k = 0; k < 10; k++) {
    cout << arr3[k] << " ";
  }
  return 0;
}