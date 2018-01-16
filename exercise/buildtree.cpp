#include <iostream>
#include <cstring>
#define MAX 100
using namespace std;

struct Binary_node {
  Binary_node() {
    data = 0;
    left = right = NULL;
  }
  char data;
  Binary_node *left, *right;
};

int searchNum(char num, char *array, int len) {
  /* num 为要找的元素，array是查到的地方， len是数组的长度*/
  for (int i = 0; i < len; i++) {
    if (array[i] == num)
      return i;
  }
  /*返回找到元素的下标，即根节点在中序序列的位置*/
}

Binary_node* createBTree(char *pre, char *in, int len) {
  if (len <= 0)
    return NULL;
  Binary_node* node = new Binary_node();
  node->data = pre[0];
  int index = searchNum(*pre, in, len);

  node->left = createBTree(pre + 1, in, index);
  node->right = createBTree(pre + index + 1, in + index + 1, len - index - 1);

  return node;
}

void recursive_post(Binary_node *sub_root, void (*visit)(char &)) {
  if (sub_root == NULL)
    return;
  recursive_post(sub_root->left, visit);
  recursive_post(sub_root->right, visit);
  (*visit)(sub_root->data);
}

void postOrder(Binary_node *root, void (*visit)(char &)) {
  recursive_post(root, visit);
}

void print(char &ch) {
  cout << ch;
}

int main() {
  char preNode[MAX], inNode[MAX];
  int n = 0;
  char ch;
  Binary_node *root = NULL;
  cin >> preNode;
  cin >> inNode;

  root = createBTree(preNode, inNode, strlen(inNode));

  postOrder(root, print);
  cout << endl;
}