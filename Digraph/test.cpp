#include <iostream>
#include "Digraph.hpp"
#include "Digraph.cpp"
using namespace std;

void print(Vertex &x) {
  cout << x << " ";
}

int main() {
  Digraph<9> digraph;
  digraph.insert(0,1);
  digraph.insert(1,0);
  digraph.insert(1,2);
  digraph.insert(2,1);
  digraph.insert(2,3);
  digraph.insert(3,2);
  digraph.insert(1,4);
  digraph.insert(4,1);
  digraph.insert(0,4);
  digraph.insert(4,0);
  digraph.insert(0,8);
  digraph.insert(8,0);
  digraph.insert(5,6);
  digraph.insert(6,5);
  digraph.insert(8,5);
  digraph.insert(5,8);
  digraph.insert(5,4);
  digraph.insert(4,5);
  
  digraph.insert(6,7);
  digraph.insert(7,6);
  cout << "Use DFS to traverse the graph: ";
  digraph.depth_first(print);
  cout << endl;

  cout << "Use BFS to traverse the graph: ";
  digraph.breadth_first(print);
  cout << endl;

  return 0;
}