// Let's create a binary tree of integers!
#include <iostream>

struct Node {
  int d;
  Node *left;
  Node *right;
};

Node * first(int d);
Node * search_insert(Node *root, int d);
void print_tree(Node *root, int l);

int main() {
  const int n = 16;
  int b[n] = {10, 25, 20, 6, 21, 8, 1, 30, 22, 23, 24, 56, 44, 3, 4,9 };
  Node *root = first(b[0]);
  for (int i=1; i < n; i++)search_insert(root, b[i]);
  print_tree(root, 0);
  return 0;
}

Node * first(int d) {
  Node *pv = new Node;
  pv->d = d;
  pv->left = 0;
  pv->right = 0;
  return pv;
}
// Поиск с включением
Node * search_insert(Node *root, int d) {
  Node *pv = root, *prev;
  bool found = false;
  while(pv && !found) {
    // We need to know the parent Node, if we are to create a new one
    prev = pv;
    if (d == pv->d) found = true;
    else if (d < pv->d) pv = pv->left;
    else                pv = pv->right;
  }
  if(found) return pv;
  // Else let's create a new Node:
  Node *pnew = new Node;
  pnew->d = d;
  pnew->left = 0;
  pnew->right = 0;

  if (d < prev->d) prev->left = pnew;
  else             prev->right = pnew;
  return pnew;
}

void print_tree(Node *p, int level) {
  if(p) {
    print_tree(p->left, level+1);
    for (int i = 0; i < level; i++) std::cout << "    ";
    std::cout << p->d << std::endl;
    print_tree(p->right, level+1);
  }
}

// void del(Node *root, int d) {
//   //поиск узла
//   Node *p = root, *prev;
//   bool found = false;
//   while(p && !found) {
//
//
//     if (d == p->d) found = true;
//     else if (d < p->d) p = p->left;
//     else               p = p->right;
//   }
//   if(!found) {
//     std::cout << "Node is not found.\n";
//     return;
//   }
// // There are possibilities:
// // 1. left is 0, right is 0 - leaf. Just remove links of parent.
// // 2. left is 0, right is not. There is a subtree! okay, then link the parent with the child.
// // 3. left is not 0, right is 0. The same approach.
// // actually, 1. is the same as 2 and 3.
//
//   }
// }
