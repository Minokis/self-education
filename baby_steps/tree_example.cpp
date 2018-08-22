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
void del(Node *root, int d);

int main() {
  const int n = 16;
  int b[n] = {10, 25, 20, 6, 21, 8, 1, 30, 22, 23, 24, 56, 44, 3, 4,9 };
  Node *root = first(b[0]);
  for (int i=1; i < n; i++)search_insert(root, b[i]);
  print_tree(root, 0);
  //del(root, 10);
  del(root, 20);
  //del(root, 23);

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
// The function looks for the node d.
// If it is absent, new node is inserted in the search tree (in a good place).
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

void del(Node *root, int d) {
  Node *pv = root, *prev = 0;
  bool found = false;
  while(pv && !found) {
    if (d == pv->d) found = true;
    else if (d < pv->d) { prev = pv; pv = pv->left;}
    else                { prev = pv; pv = pv->right;}
  }
  if(!found) { std::cout << "Node is not found.\n"; return; }
  // TODO: finish translation, get rid of dummies
  // на выходе имеем prev - родителя искомого удаляемого, и удаляемое pv.
  // если pv == root,  то prev = 0x0.

  // Проверка
  std::cout << "pv = " << pv->d << std::endl;
  prev ? std::cout << "prev = " << prev->d << std::endl : std::cout << "prev = " << prev << std::endl;

  if(!(pv->left)) {  // pv doesn't have left subtree, or both.
    // pv's link to the right subtree should go to the parent.
    // we're not sure about link to pv (is it prev->left or right?), so need to check
    std::cout<<"pv has no left subtree\n";
    d < prev->d ? prev->left = pv->right : prev->right = pv->right;
    std::cout << "prev = " << prev->d << std::endl;
    prev->left ? std::cout << "prev->left = " << (prev->left)->d << std::endl : std::cout << "prev->left = " << prev->left << std::endl;
  //  delete prev; delete pv;
  }
  // TODO: check other branches
  else if (!(pv->right)) {// левое поддерево есть, а правого нет
  // тогда ссылка на левое поддерево должна перейти к родителю вместо ссылки на удаляемого
    d < prev->d ? prev->left = pv->left : prev->right = pv->left;
    delete prev; delete pv;
  }
  else { // оба поддерева в наличии
    std::cout << "Both subtrees" << std::endl;
  }

} // void del()
