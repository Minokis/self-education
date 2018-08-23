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
  int b[n] = {10, 25, 20, 19, 6, 21, 8, 1, 30, 22, 23, 24, 56, 44, 3, 4 };
  Node *root = first(b[0]);
  for (int i=1; i < n; i++)search_insert(root, b[i]);
  print_tree(root, 0);

  del(root, 10); // check deleting of the root
  del(root, 8);
  del(root, 20);   // node with only right subtree
  del(root, 44);   // node-leaf
  del(root, 56); // node with only left subtrees
  del(root, 20); // node with both subtrees

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
  // Now we have pv to delete and its parent prev.
  // If pv == root,  then prev = 0x0.

  // Check our findings
  std::cout << "pv = " << pv->d << std::endl;
  prev ? std::cout << "prev = " << prev->d << std::endl : \
      std::cout << "prev = " << prev << std::endl;

  if(!(pv->left)) {  // pv doesn't have a left subtree, or both.
    // pv's link to the right subtree should go to the parent.
    // we're not sure about link to pv (is it prev->left or right?), so need to check
    d < prev->d ? prev->left = pv->right : prev->right = pv->right;
    prev->left ? std::cout << "prev->left = " << (prev->left)->d << \
        std::endl : std::cout << "prev->left = " << prev->left << std::endl;
  }
  else if (!(pv->right)) { // pv doesn't have a right subtree, but it has the left one.
     // pv's link to the left subtree should go to the parent.
     // we're not sure about link to pv (is it prev->left or right?), so need to check
     d < prev->d ? prev->left = pv->left : prev->right = pv->left;
     prev->right ? std::cout << "prev->right = " << (prev->right)->d << \
         std::endl : std::cout << "not supposed to happen: prev->rigth = " << prev->right << std::endl;
  }
  else { // pv has both subtrees. Welcome to hell!
    std::cout << "Both subtrees" << std::endl;
    // we need to replace this node with the one, which is most close in value.
    // it can be the rightest of the left subtree or the leftest of the right subtree.
    // Step 1. Find it!
    // Step 2. Memorize its value
    // Step 3. Delete it (ha-ha)
    // Step 4. Replace the value

    // Step 1. Find it! Let's go for the rightest of the left subtree.
    Node *replace = new Node;
    replace = pv->left;   // A . Remember this.
    prev = pv;
    while(replace->right) {
      prev = replace;
      replace = replace->right;
    }
    // Step 2. Memorize its value
    int value = replace->d;
    // Step 3. Delete it.
    // Yes, I know it's illogical to search for the value again, but come on, it's easier!
    // del(root, value);
    // Okay, it was a joke. Let's repeat some strings.
    // WE DON'T KNOW IF IT IS prev->right OR prev->left!!!! (Look to A.)
    // But we are sure that replace->right is 0.
    replace->d < prev->d ? prev->left = replace->left : prev->right = replace->left;
    delete replace;
    // Step 4. Replace the value
    pv->d = value;
  } // both subtrees

} // void del()
