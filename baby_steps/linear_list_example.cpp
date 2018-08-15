/* программа формирует список из 5 чисел,
добавляет число в список, удаляет число из списка и выводит список на экран.*/

#include <iostream>
// Объявим элемент списка
struct Node {
  int d;
  Node *next;
  Node *prev;
};
// ---------
Node * first (int d);            // создание первого элемента
void add (Node **pend, int d);   // добавление элемента в конец списка
Node * find(Node * const pbeg, int key);
Node * insert(Node * const pbeg, Node **pend, int key, int d); // вставить после key
bool remove (Node ** pbeg, Node **pend, int key);


int main() {
  // Пусть указатель на начало списка = pbeg, на конец - pend
  // Создадим список
  Node *pbeg = first(1);
  Node *pend = pbeg;
  // Добавим элементы 2, 3, 4, 5
  for (int i = 2; i < 6; i++)add(&pend, i);
  // Вставим элемент 350 после элемента 3
  insert (pbeg, &pend, 3, 350);
  // Удалим элемент 4
  if(!remove(&pbeg, &pend, 4)) std::cout << "не найден";

  // Распечатаем
  Node *pv = pbeg;
  while(pv) {
    std::cout << pv->d << ' ';
    pv = pv->next;
  }
  std::cout << '\n';
  delete pbeg;
  delete pend;
  delete pv;
  return 0;
}

// Создание первого элемента - формирование списка
Node * first (int d) {
  Node *pv = new Node;
  pv->d = d;
  pv->next = 0; pv->prev = 0;
  return pv;
}
// Добавление элемента в конец списка
void add (Node **pend, int d) {
  Node *pv = new Node;
  pv->d = d;
  pv->next = 0;
  pv->prev = *pend; // pend - это указатель на указатель на структуру. Нам нужен просто указатель на структуру
  (*pend)->next = pv; // не забыли про предпоследний элемент!
  *pend = pv;
}
// Поиск элемента по ключу
Node * find(Node * const pbeg, int d) {
  Node *pv = pbeg;
  while(pv) {
    if (pv->d == d) break;
    pv = pv-> next;
  }
  return pv; // если не найдет, функция вернет 0
}
// Вставка после элемента с заданным ключом
Node * insert(Node * const pbeg, Node **pend, int key, int d) {
  if(Node *pkey = find(pbeg, key)) {
    Node *pv = new Node;
    pv->d = d;
    // 1 установление связи нового узла с последующим:
    pv->next = pkey->next;
    // 2 установление связи нового узла с предыдущим:
    pv->prev = pkey;
    // 3 установление связи предыдущего узла с новым:
    pkey->next = pv;
    // 4 установление связи последующего узла с новым
    if (pkey != *pend) (pv->next)->prev = pv;
    //обновление указателя на конец списка, если узел вставлен в конец
    else *pend = pv;
    return pv;
  }
  return 0;
}

// Удаление элемента
bool remove (Node ** pbeg, Node **pend, int key) {
  if(Node *pkey = find(*pbeg, key)) {
    if(pkey == *pbeg) {
      *pbeg = (*pbeg)->next;
      (*pbeg)->prev = 0; }
    else if (pkey == *pend) {
      *pend = (*pend)->prev;
      (*pend)->next = 0; }
    else {
      (pkey->prev)->next = pkey->next;
      (pkey->next)->prev = pkey->prev;
    }
    delete pkey;
    return true;
  }
  return false;
}
