#include <iostream>
#include <map>
using namespace std;

int main() {
  int casenumber;
  bool flag = false;
  while (scanf("%d", &casenumber) != EOF) {
    if (flag)
      cout << endl;
    else
      flag = true;
    
    map<long, long> counter;
    while (casenumber--) {
      long ele;
      cin >> ele;
      counter[ele]++;
    }
    
    map<long, long>::iterator it;
    for (it = counter.begin(); it != counter.end(); it++) {
      if (it->second != 0)
        cout << it->first << " " << it->second << endl;
    }
  }
  return 0;
}