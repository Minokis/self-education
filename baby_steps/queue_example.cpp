// An example of queue

#include <iostream>

// Queue element
struct Node {
  int d;
  Node *next;
};

Node *first(int d);
void add(Node ** pend, int d);
int remove(Node **pbeg);

int main() {
  // Create first element
  Node *pbeg = first(1);
  Node *pend = pbeg;
  // Add some more elements
  for (int i = 2; i < 7; i++) add(&pend, i);

  // Remove 2 elements
  remove(&pbeg);
  remove(&pbeg);

  // Print the queue
  Node *pv = pbeg;
  while(pbeg)
    std::cout << remove(&pbeg) << std::endl;
  return 0;
}
// Forming a queue
Node *first(int d) {
  Node *pv = new Node;
  pv->d = d;
  pv->next = 0;
  return pv;
}
// Adding to the tail
void add(Node ** pend, int d) {
  Node *pv = new Node;
  pv->d = d;
  pv->next = 0;
  (*pend)->next = pv;
  *pend = pv;
}

int remove(Node **pbeg) {
  int temp = (*pbeg)->d;
  Node *pv = *pbeg;
  *pbeg = (*pbeg)->next;
  delete pv;
  return temp;
}
