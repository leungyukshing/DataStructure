#include <iostream>
#include "Digraph.hpp"
template <int max_size>
void Digraph<max_size>::insert(const Vertex &start, const Vertex &end) {
  // 确保输入的两个点是合法的
  if (start < 0 || start >= max_size || end < 0 || start >= max_size) {
    return;
  }
  for (int i = 0; i < neighbors[start].size(); i++) {
    Vertex tmp;
    // 在start相邻的节点list中找到end，无需再操作
    neighbors[start].retrieve(i, tmp);
    if (end == tmp) {
      return;
    }
  }
  neighbors[start].insert(neighbors[start].size(), end);
  cout << "insert succeed!" << endl;
}

template <int max_size>
void Digraph<max_size>::depth_first(void (*visit)(Vertex &x)) const {
  bool visited[max_size];
  Vertex v;
  for (int i = 0; i < max_size; i++) {
    visited[i] = false;
  }
  for (int i = 0; i < max_size; i++) {
    if (!visited[i]) {
      traverse(i, visited, visit);
    }
  }
}

template <int max_size>
void Digraph<max_size>::traverse(Vertex &v, bool visited[], void (*visit)(Vertex &x)) const {
  // Pre: v是当前节点，visited是用于记录遍历的数组
  Vertex w;
  visited[v] = true; // 将v标为已遍历
  (*visit)(v);
  // 对v的相邻节点list进行遍历
  for(int i = 0; i < neighbors[v].size(); i++) {
    neighbors[v].retrieve(i, w);
    if (!visited[w]) {
      traverse(w, visited, visit);
    }
  }
}

template <int max_size>
void Digraph<max_size>::breadth_first(void (*visit)(Vertex &x)) const {
  LinkedQueue<Vertex> q;
  bool visited[max_size];
  Vertex v, w, x;
  for (v = 0; v < max_size; v++) {
    visited[v] = false;
  }
  for (v = 0; v < max_size; v++) {
    if (!visited[v]) {
      q.append(v);
      while (!q.empty()) {
        q.retrieve(w);
        if (!visited[w]) {
          visited[w] = true;
          (*visit)(w);
          for (int i = 0; i < neighbors[w].size(); i++) {
            neighbors[w].retrieve(i, x);
            if (!visited[x]) {
              q.append(x);
            }
          }
        }
        q.serve();
      }
    }
  }
}