#include <stack>
using namespace std;

// root is a pointer to the root of the binary tree.
template <typename T>
void inorder_recursive(BinaryNode<T>* root, void (*visit)(T &x)) {
  if (root == NULL)
    return;
  inorder_recursive(root->left, visit);
  (*visit)(root->elem);
  inorder_recursive(root->right, visit);
}

// root is a pointer to the root of the binary tree.
template <typename T>
void inorder(BinaryNode<T>* root, void (*visit)(T &x)) {
  BinaryNode<T> *p = root;
  stack<BinaryNode<T>*> st;

  while (p != NULL || !st.empty()) {
    if (p) {
      st.push(p);
      p = p->left;
    }
    else {
      p = st.top();
      st.pop();
      (*visit)(p->elem);
      p = p->right;
    }
  }
}