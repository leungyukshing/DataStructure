#include <iostream>
using namespace std;
void swap(int arr[], int low, int high) {
  int temp = arr[low];
  arr[low] = arr[high];
  arr[high] = temp;
}

int partition(int arr[], int low, int high) {
  int pivot = arr[low];
  int last_small = low;
  for (int i = low + 1; i <= high; i++) {
    if (arr[i] < pivot) {
      last_small++;
      swap(arr, last_small, i);
    }
  }
  swap(arr, last_small, low);
  return last_small;
}


void qsort(int arr[], int low, int high) {
  if (low < high) {
    int pivot = partition(arr, low, high);
    qsort(arr, low, pivot - 1);
    qsort(arr, pivot + 1, high);
  }
}

void print(int arr[], int size) {
  for (int i = 0; i < size; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
}
int main() {
  int num;
  cin >> num;
  int arr[num];
  for (int i = 0; i < num; i++) {
    cin >> arr[i];
  }
  qsort(arr, 0, num - 1);
  print(arr, num);

  return 0;
}