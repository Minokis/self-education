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
// delete


int main() {
  // Пусть указатель на начало списка = pbeg, на конец - pend
  // Создадим список
  Node *pbeg = first(1);
  Node *pend = pbeg;
  // Добавим элементы 2, 3, 4, 5
  for (int i = 2; i < 6; i++) add(&pend, i);
  // Вставим элемент 350 после 3
  insert (pbeg, &pend, 3, 350);
  // TODO удалим элемент 4

  // Распечатаем
  Node *pv = pbeg;
  while(pv) {
    std::cout << pv->d << ' ';
    pv = pv->next;
  }
  std::cout << '\n';
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
Node * find(Node * const pbeg, int key) {
  Node *pv = pbeg;
  while(pv) {
    if (pv->d == key) break;
    pv-> next = pv;
  }
  return pv; // если не найдет, функция вернет 0
}
// Вставка после элемента с заданным ключом
Node * insert(Node * const pbeg, Node **pend, int key, int d) {
  if(Node *pkey = find(pbeg, key)) {
    Node *pv = new Node;
    pv->d = d;
    // установление связи нового узла с последующим:
    pv->next = pkey->next;
    // установление связи нового узла с предыдущим:
    pv->prev = pkey;
    // установление связи предыдущего узла с новым:
    pkey->next = pv;
    // установление связи последующего узла с новым
    if (pkey != *pend) (pv->next)->prev = pv;
    //обновление указателя на конец списка, если узел вставлен в конец
    else *pend = pv;
    return pv;
  }
  return 0;
}
