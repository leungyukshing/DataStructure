#include <iostream>
#include <queue>
using namespace std;
struct obj {
  int index;
  int priority;
};

int max_priority(int mark[], int size) {
  int max = -1;
  for (int i = 0; i < size; i++) {
    if (mark[i] > max)
      max = mark[i];
  }
  return max;
}
int main() {
  int testcase;
  cin >> testcase;
  while (testcase--) {
    int count = 0;
    queue<obj> q;
    int n, m;
    cin >> n >> m;
    int mark[n];
    for (int i = 0; i < n; i++) {
      obj tmp;
      tmp.index = i;
      cin >> tmp.priority;
      mark[i] = tmp.priority;
      q.push(tmp);
    }
    while (1) {
      //cout << q.front().index << endl;
      obj top = q.front();
      int max = max_priority(mark, n);
      //cout << "max is: " << max << endl;
      if (top.priority == max) {
        q.pop();
        mark[top.index] = -1;
        count++;
        //cout << "print"<<endl;
        if (top.index == m)
          break;
      }
      else {
        //cout << "trans" << endl;
        q.pop();
        q.push(top);
      }
    }
    cout << count << endl;
  }
  return 0;
}