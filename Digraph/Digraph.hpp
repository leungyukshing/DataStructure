#ifndef GRAPH_H
#define GRAPH_H
#include "../LinkedList/LinkedList.hpp"
#include "../LinkedList/LinkedList.cpp"
#include "../LinkedQueue/LinkedQueue.hpp"
#include "../LinkedQueue/LinkedQueue.cpp"

typedef int Vertex;
template <int max_size>
class Digraph {
public:
  void insert(const Vertex &start, const Vertex &end);
  void depth_first(void (*visit)(Vertex &x)) const;
  void breadth_first(void (*visit)(Vertex &x)) const;
private:
  int count; // number of vertices, at most max_size
  LinkedList<Vertex> neighbors[max_size];
  // auxilary funcitons
  void traverse(Vertex &v, bool visited[], void (*visit)(Vertex &)) const;
};

#endif