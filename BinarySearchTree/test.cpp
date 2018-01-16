#include <iostream>
#include "BinarySearchTree.hpp"
#include "BinarySearchTree.cpp"
using namespace std;
template <class Entry>
void print(Entry &x) {
  cout << x << " ";
}

int main() {
  BinarySearchTree<int> tree;
  int data[] = {10, 27, 1, 23, 8, 54, 98, 200, 47, 3, 24, 44, 74};
  for (int i = 0; i < 13; i++) {
    tree.insert(data[i]);
  }
  cout << "The size is " << tree.size() << endl;
  cout << "Tree printed in inorder: ";
  tree.inorder(print);
  cout << endl;

  tree.remove(23);
  tree.remove(58);
  tree.remove(98);
  cout << "The size is " << tree.size() << endl;
  cout << "Tree printed in inorder after remove operation: ";
  tree.inorder(print);
  cout << endl;
}