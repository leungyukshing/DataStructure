#include <iostream>
using namespace std;

int main() {
  int n,m;
  cin >> n >> m;
  bool visited[n+1];
  bool graph[n+1][n+1];
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
  int v,w;
  int distance[n+1];
  bool found[n+1];
  for (int i = 1; i <= n; i++) {
    found[i] = false;
    for (int j = 1; j <= n; j++) {
      if (graph[1][j] == true) {
        distance[j] = 1;
      }
      else {
        distance[j] = 50;
      }
    }
  }
  found[1] = true;
  distance[1] = 0;

  /*for (int a = 1; a <= n; a++) {
    cout << distance[a] << " ";
  }
  cout << endl;*/

  for (int i = 1; i <= n; i++) {
    int min = 100;
    for (w = 1; w <= n; w++) {
      if (!found[w]) {
        if (distance[w] < min) {
          v = w;
          min = distance[w];
        }
      }
    }
    found[v] = true;
    for (w = 1; w <= n; w++) {
      if (!found[w]) {
        if (graph[v][w] == false){
          continue;
        }
        if (min + graph[v][w] < distance[w]) {
          //cout << "graph[v][w] " << graph[v][w] << endl;
          //cout << "distance[w] " << distance[w] << endl;
          distance[w] = min + graph[v][w];
          //cout << "change " << w << endl;
        }
      }
    }
    /*for (int a = 1; a <= n; a++) {
      cout << distance[a] << " ";
    }
    cout << endl;*/
  }

  for (int a = 1; a <= n; a++) {
    if (distance[a] == 50) {
      cout << -1 << " ";
      continue;
    }
    cout << distance[a] << " ";
  }
  cout << endl;
}