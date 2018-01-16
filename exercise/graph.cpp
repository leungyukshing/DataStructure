#include <iostream>
using namespace std;
bool graph[1000][1000];
void traverse(int i, bool visited[], int n) {
  visited[i] = true;
  for(int j = 1; j <= n; j++) {
    if (graph[i][j] && !visited[j]) {
      traverse(j, visited, n);
    }
  }
}

int main() {
  int n,m;
  cin >> n >> m;
  bool visited[n+1];
  
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      graph[i][j] = false;
    }
  }

  for (int i = 1; i <= n; i++) {
    visited[i] = false;
  }

  while (m--) {
    int start, end;
    cin >> start >> end;
    graph[start][end] = true;
    graph[end][start] = true;
  }
  int count = 0;
  for (int i = 1; i <= n; i++) {
    if (!visited[i]){
      traverse(i, visited, n);
    count++;
    }
  }
  cout << count << endl;

  return 0;
}