#include "BinarySearchTree.hpp"
#include <iostream>
using namespace std;

template <class Entry>
Error_code BinarySearchTree<Entry>::insert(const Entry &new_data) {
  return search_and_insert(this->root, new_data);
}

template <class Entry>
Error_code BinarySearchTree<Entry>::search_and_insert(Binary_node<Entry> *&sub_root, const Entry &new_data) {
  // 若当前节点为空，即找到插入位置，插入元素并返回成功
  if (sub_root == NULL) {
    sub_root = new Binary_node<Entry>(new_data);
    return Success;
  }
  else if (new_data < sub_root->data)
    return search_and_insert(sub_root->left, new_data);
  else if (new_data > sub_root->data)
    return search_and_insert(sub_root->right, new_data);
  else // 重复数据
    return dublicate_error;
}

template <class Entry>
Error_code BinarySearchTree<Entry>::remove(const Entry &old_data) {
  return search_and_remove(this->root, old_data);
}
template <class Entry>
Error_code BinarySearchTree<Entry>::search_and_remove(Binary_node<Entry> *&sub_root, const Entry &target) {
  if (sub_root == NULL || sub_root->data == target)
    return remove_root(sub_root);
  else if (target < sub_root->data)
    return search_and_remove(sub_root->left, target);
  else
    return search_and_remove(sub_root->right, target);
}
template <class Entry>
Error_code BinarySearchTree<Entry>::remove_root(Binary_node<Entry> *&sub_root) {
  // Pre: sub_root is either NULL or points to a subtree of the BST
  if (sub_root == NULL)
    return not_present;
  // 用to_delete记录要删除的节点，sub_root就可以移动过了
  Binary_node<Entry> *to_delete = sub_root;
  // 只有左子树
  if (sub_root->right == NULL)
    sub_root = sub_root->left;
  // 只有右子树
  else if (sub_root->left == NULL)
    sub_root = sub_root->right;
  // 左右子树均存在, 找左子树的最右节点
  else {
    to_delete = sub_root->left;
    Binary_node<Entry> *parent = sub_root; // parent of to_delete
    while (to_delete->right != NULL) {
      parent = to_delete;
      to_delete = to_delete->right;
    }
    sub_root->data = to_delete->data;
    // 左子树无右子树
    if (parent == sub_root)
      sub_root->left = to_delete->left;
    else
      parent->right = to_delete->left;
  }
  delete to_delete;
  return Success;

}

template <class Entry>
Error_code BinarySearchTree<Entry>::tree_search(const Entry &target) const {
  Error_code result = Success;
  Binary_node<Entry> *found = search_for_node(this->root, target);
  if (found == NULL)
    return not_present;
  else
    target = found->data;
  return result;
}

template <class Entry>
Binary_node<Entry>* BinarySearchTree<Entry>::search_for_node(Binary_node<Entry> *sub_root, const Entry &target) const {
  // 若当前节点为空或者其数据与目标相符，返回本节点
  if (sub_root == NULL || sub_root->data == target)
    return sub_root;
  else if (target < sub_root->data)
    return search_for_node(sub_root->left, target);
  else
    return search_for_node(sub_root->right, target);
}