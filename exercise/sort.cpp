#include <iostream>
using namespace std;

void swap(int arr[], int low, int high) {
  int temp = arr[low];
  arr[low] = arr[high];
  arr[high] = temp;
}

int max_key(int arr[], int low, int high) {
  int largest, current;
  largest = low;
  for(current = low + 1; current <= high; current++) {
    if (arr[current] > arr[largest]) {
      largest = current;
    }
  }
  return largest;
}

void selectionSort(int arr[], int n) {
  for (int position = n - 1; position > 0; position--) {
    int max = max_key(arr, 0, position);
    swap(arr, position, max);
  }
}

int main() {
  while (1) {
    int number, interval;
    cin >> number >> interval;
    if (number == 0 && interval == 0)
      break;
    int arr[number];
    int size = number;
    int i = 0;
    while (number--) {
      cin >> arr[i];
      i++;
    }
    /*for(int i = 0; i < size; i++) {
      cout << arr[i] << " ";
    }
    cout << "finish input" << endl;*/
    //sort
    selectionSort(arr, size);

    /*for(int i = 0; i < size; i++) {
      cout << arr[i] << " ";
    }*/
    for(int i = 0; i < size; i+=interval) {
      cout << arr[i] << " ";
    }
    //cout << endl;
  }
  return 0;
}