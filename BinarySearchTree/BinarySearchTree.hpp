#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H
#include "../BinaryTree/BinaryTree.hpp"
#include "../BinaryTree/BinaryTree.cpp"
template <class Entry>
class BinarySearchTree: public BinaryTree<Entry> {
public:
  Error_code insert(const Entry &new_data);
  Error_code remove(const Entry &target);
  Error_code tree_search(const Entry &target) const;
private:
  // 用于遍历并插入的函数
  Error_code search_and_insert(Binary_node<Entry> *&sub_root, const Entry &new_data);
  // 用于遍历寻找指定节点的函数
  Binary_node<Entry>* search_for_node(Binary_node<Entry> *sub_root, const Entry &target) const;
  // 用于遍历找到要删除节点的函数
  Error_code search_and_remove(Binary_node<Entry> *&sub_root, const Entry &target);
  // 用于处理要删除的根节点的函数
  Error_code remove_root(Binary_node<Entry> *&sub_root);
};

#endif