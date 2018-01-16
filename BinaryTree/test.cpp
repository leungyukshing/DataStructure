#include <iostream>
#include "BinaryTree.hpp"
#include "BinaryTree.cpp"
using namespace std;

template <class Entry>
void print(Entry &x) {
  cout << x << " ";
}

int main() {
  BinaryTree<int> tree;
  for (int i = 0; i < 10; i++) {
    tree.insert(i);
  }
  cout << "current size is ";
  cout << tree.size() << endl;
  cout << "in preorder: ";
  tree.preorder(print);
  cout << endl;
  cout << "in inorder: ";
  tree.inorder(print);
  cout << endl;
  cout << "in postorder: ";
  tree.postorder(print);
  cout << endl;

  return 0;
}