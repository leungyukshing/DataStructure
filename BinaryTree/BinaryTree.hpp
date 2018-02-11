#ifndef BINARYTREE_H
#define BINARYTREE_H
#include "../LinkedQueue/LinkedQueue.hpp"
#include "../LinkedQueue/LinkedQueue.cpp"
template <class Entry>
struct Binary_node {
  // data members
  Entry data;
  Binary_node<Entry> *left;
  Binary_node<Entry> *right;

  //constructors
  Binary_node();
  Binary_node(const Entry &x);
};

template <class Entry>
class BinaryTree {
public:
  BinaryTree();
  bool empty() const;
  void preorder(void (*visit)(Entry &));
  void inorder(void (*visit)(Entry &));
  void postorder(void (*visit)(Entry &));
  void double_traverse(void (*visit)(Entry &));
  void level_traverse(void (*visit)(Entry &));
  int size() const;
  void clear();
  int height() const;
  int width() const;
  int leaf_count() const;
  void insert(const Entry &);

  BinaryTree(const BinaryTree<Entry> &original);
  BinaryTree& operator=(const BinaryTree<Entry> &original);
  ~BinaryTree();
protected:
  Binary_node<Entry> *root;  
  // aux functions
  void recursive_preorder(Binary_node<Entry> *sub_root, void (*visit)(Entry &));
  void recursive_inorder(Binary_node<Entry> *sub_root, void (*visit)(Entry &));
  void recursive_postorder(Binary_node<Entry> *sub_root, void (*visit)(Entry &));
  int recursive_size(Binary_node<Entry> *sub_root) const;
  int recursive_leaf_count(Binary_node<Entry> *sub_root) const;
  int recursive_height(Binary_node<Entry> *sub_root) const;
  void recursive_insert(Binary_node<Entry> *&sub_root, const Entry &x);
  void recursive_clear(Binary_node<Entry> *&sub_root);
  Binary_node<Entry>* recursive_copy(Binary_node<Entry> *sub_root);
  void recursive_double_traverse(Binary_node<Entry> *sub_root, void (*visit)(Entry &));
};
#endif