#include "BinaryTree.hpp"
#include <iostream>
using namespace std;
template <class Entry>
BinaryTree<Entry>::BinaryTree() {
  root = NULL;
}
template <class Entry>
Binary_node<Entry>::Binary_node() {
  left = right = NULL;
}

template <class Entry>
Binary_node<Entry>::Binary_node(const Entry &x) {
  data = x;
  left = right = NULL;
}

template <class Entry>
BinaryTree<Entry>::BinaryTree(const BinaryTree<Entry> &original) {
  root = recursive_copy(original.root);
}

template <class Entry>
Binary_node<Entry>* BinaryTree<Entry>::recursive_copy(Binary_node<Entry> *sub_root) {
  if (sub_root == NULL)
    return NULL;
  Binary_node<Entry> *temp = new Binary_node<Entry>(sub_root->data);
  temp->left = recursive_copy(sub_root->left);
  temp->right = recursive_copy(sub_root->right);
  return temp;
}

template <class Entry>
BinaryTree<Entry>& BinaryTree<Entry>::operator =(const BinaryTree<Entry> &original) {
  BinaryTree<Entry> new_copy(original);
  clear();
  root = new_copy.root;
  new_copy.root = NULL;
  return *this;
}

template <class Entry>
BinaryTree<Entry>::~BinaryTree() {
  clear();
}

template <class Entry>
void BinaryTree<Entry>::preorder(void (*visit)(Entry &)) {
  recursive_preorder(root, visit);
}

template <class Entry>
void BinaryTree<Entry>::inorder(void (*visit)(Entry &)) {
  recursive_inorder(root, visit);
}

template <class Entry>
void BinaryTree<Entry>::postorder(void (*visit)(Entry &)) {
  recursive_postorder(root, visit);
}

template <class Entry>
void BinaryTree<Entry>::recursive_preorder(Binary_node<Entry> *sub_root, void (*visit)(Entry &)) {
  // 当前节点不为空
  if (sub_root != NULL) {
    (*visit)(sub_root->data);
    recursive_preorder(sub_root->left, visit);
    recursive_preorder(sub_root->right, visit);
  }
}

template <class Entry>
void BinaryTree<Entry>::recursive_inorder(Binary_node<Entry> *sub_root, void (*visit)(Entry &)) {
  // 当前节点不为空
  if (sub_root != NULL) {
    recursive_inorder(sub_root->left, visit);
    (*visit)(sub_root->data);
    recursive_inorder(sub_root->right, visit);
  }
}

template <class Entry>
void BinaryTree<Entry>::recursive_postorder(Binary_node<Entry> *sub_root, void (*visit)(Entry &)) {
  // 当前节点不为空
  if (sub_root != NULL) {
    recursive_postorder(sub_root->left, visit);
    recursive_postorder(sub_root->right, visit);
    (*visit)(sub_root->data);
  }
}

// 双重遍历
template <class Entry>
void BinaryTree<Entry>::double_traverse(void (*visit)(Entry &)) {
  recursive_double_traverse(root, visit);
}

template <class Entry>
void BinaryTree<Entry>::recursive_double_traverse(Binary_node<Entry> *sub_root, void (*visit)(Entry &x)) {
  if (sub_root != NULL) {
    (*visit)(sub_root->data);
    recursive_double_traverse(sub_root->left, visit);
    (*visit)(sub_root->data);
    recursive_double_traverse(sub_root->right, visit);
  }
}

template <class Entry>
void BinaryTree<Entry>::level_traverse(void (*visit)(Entry &)) {
  Binary_node<Entry> *sub_root;
  if (root != NULL) {
    LinkedQueue<Binary_node<Entry> *> waiting_nodes;
    waiting_nodes.append(root); // 将根节点放入队列
    do {
      waiting_nodes.retrieve(sub_root); // 获取头节点进行处理
      (*visit)(sub_root->data);
      if (sub_root->left)
        waiting_nodes.append(sub_root->left);
      if (sub_root->right)
        waiting_nodes.append(sub_root->right);
      waiting_nodes.serve(); // 拿走已经处理的头
    } while (!waiting_nodes.empty());
  }
}

// 计算节点个数
template <class Entry>
int BinaryTree<Entry>::size() const {
  return recursive_size(root);
}

template <class Entry>
int BinaryTree<Entry>::recursive_size(Binary_node<Entry> *sub_root) const {
  // 若本身为空，不计数
  if (sub_root == NULL)
    return 0;
  else
    return 1 + recursive_size(sub_root->left) + recursive_size(sub_root->right);
}

// 计算叶子节点个数
template <class Entry>
int BinaryTree<Entry>::leaf_count() const {
  return recursive_leaf_count(root);
}

template <class Entry>
int BinaryTree<Entry>::recursive_leaf_count(Binary_node<Entry> *sub_root) const {
  // 若本身是空，不计数
  if (sub_root == NULL)
    return 0;
  // 若本身不为空，且无左右子树，即自己为叶子节点，计数
  if (sub_root->left)
    return 1;
  else
    return recursive_leaf_count(sub_root->left) + recursive_leaf_count(sub_root->right);
}

// 计算树高
template <class Entry>
int BinaryTree<Entry>::height() const {
  return recursive_height(root);
}

template <class Entry>
int BinaryTree<Entry>::recursive_height(Binary_node<Entry> *sub_root) const {
  if (sub_root == NULL)
    return 0;
  int left_height = recursive_height(sub_root->left);
  int right_height = recursive_height(sub_root->right);
  if (left_height > right_height) {
    return left_height + 1;
  }
  else
    return right_height + 1;
}

template <class Entry>
int BinaryTree<Entry>::width() const {
  if (root == NULL)
    return 0;
  LinkedQueue<Binary_node<Entry>*> current_level;
  current_level.append(root);
  int max_level = 0;
  while (current_level.size() != 0) {
    if (current_level.size() > max_level)
      max_level = current_level.size();
    LinkedQueue <Binary_node<Entry> *> next_level;
    do {
      Binary_node<Entry> *sub_root;
      current_level.retrieve(sub_root);
      if (sub_root->left)
        next_level.append(sub_root->left);
      if (sub_root->right)
        next_level.append(sub_root->right);
      current_level.serve();
    } while (!current_level.empty());
    current_level = next_level;
  }
  return max_level;
}
// 插入
template <class Entry>
void BinaryTree<Entry>::insert(const Entry &x) {
  recursive_insert(root, x);
}

template <class Entry>
void BinaryTree<Entry>::recursive_insert(Binary_node<Entry> *&sub_root, const Entry &x) {
  // 若当前节点为空，则插入到当前节点
  if (sub_root == NULL){
    sub_root = new Binary_node<Entry>(x);
  }
  // 若左子树较高，则插入到右边
  else if (recursive_height(sub_root->right) < recursive_height(sub_root->left))
    recursive_insert(sub_root->right, x);
  // 若右子树较高，则插入到左边
  else
    recursive_insert(sub_root->left, x);
}

template <class Entry>
void BinaryTree<Entry>::clear() {
  recursive_clear(root);
}

template <class Entry>
void BinaryTree<Entry>::recursive_clear(Binary_node<Entry> *&sub_root) {
  Binary_node<Entry> *temp = sub_root;
  if (sub_root == NULL)
    return;
  recursive_clear(sub_root->left);
  recursive_clear(sub_root->right);
  sub_root = NULL;
  delete temp;
}