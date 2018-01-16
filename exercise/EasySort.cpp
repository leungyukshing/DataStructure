#include <iostream>
using namespace std;

int main() {
  int caseNumber;
  cin >> caseNumber;
  while (caseNumber--) {
    int elementNumber;
    cin >> elementNumber;
    int size = elementNumber;
    int arr[elementNumber];
    int i = 0;
    while (size--) {
      cin >> arr[i];
      i++;
    }
      // 排序
      for (int a = 1; a < elementNumber; a++) {
        int key = arr[a];
        int last_sort = a-1;
        while (last_sort >=0 && key < arr[last_sort]) {
          arr[last_sort+1] = arr[last_sort];
          last_sort--;
        }

        arr[last_sort+1] = key;
      }
      
    for (int j = 0; j < elementNumber; j++) {
      cout << arr[j] << endl;
    }
  }
}