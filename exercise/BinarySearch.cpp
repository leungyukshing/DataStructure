#include <iostream>
#include <vector>
using namespace std;

bool binary_search(vector<int> arr, int x) {
  while (!arr.empty()) {
    int pivot = arr[(arr.size()-1)/2];
    if (pivot == x) {
      cout <<"return true when x = " << x << endl;
      return true;
    }
    else if (pivot < x) {
      for (vector<int>::iterator i = arr.begin(); i != arr.end();) {
        if ((*i) == pivot) {
          arr.erase(i);
          break;
        }
        else {
          arr.erase(i);
          continue;
        }
        i++;
      }
    }
    else {
      std::vector<int>::iterator it = arr.begin();
      while((*it) != pivot) {
        it++;
      }
      for (it; it != arr.end();) {
        arr.erase(it);
      }
    }
    cout << "Now is:";
    for (int i = 0; i < arr.size(); i++) {
      cout << arr[i] << " ";
    }
  }
  return false;
}
int main() {
  int caseNumber;
  while (scanf("%d", &caseNumber) != EOF) {
    int count = 0;
    int size = caseNumber;
    std::vector<int> v;
    while (caseNumber--) {
      int data;
      cin >> data;
      v.push_back(data);
    }
    for (int i = 0; i < size; i++) {
      cout << v[i] << " ";
    }
    for (int i = 0; i < size; i++) {
      if (binary_search(v, v[i])) {
        count++;
      }
    }
    cout << count << endl;
    
  }
  return 0;
}