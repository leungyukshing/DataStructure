#include <iostream>
#include <vector>
using namespace std;

class HashTable{
public:
  int hash(int key) {
    int hash = key % 13;
    return hash;
  }
  void insert(int ele) {
    int key = hash(ele);
    entry[key].push_back(ele);
  }
  void print() {
    for (int i = 0; i < 13; i++) {
      cout << i << "#";
      std::vector<int> tmp = entry[i];
      if (tmp.empty())
        cout << "NULL" << endl;
      else {
        for (int j = 0; j < tmp.size()-1; j++) {
          cout << tmp[j] << " ";
        }
        cout << tmp[tmp.size()-1] << endl;
      }
    }
    /*cout << 12 << "#";
      std::vector<int> tmp = entry[12];
      if (tmp.empty())
        cout << "NULL";
      else {
        for (int j = 0; j < tmp.size()-1; j++) {
          cout << tmp[j] << " ";
        }
        cout << tmp[tmp.size()-1];
      }*/
  }
private:
  vector<int> entry[13];
};

int main() {
  while(1) {
    int testcase;
    cin >> testcase;
    if (testcase == 0) {
      break;
    }
    HashTable table;
    while (testcase--) {
      int element;
      cin >> element;
      table.insert(element);
    }
    table.print();
  }
}