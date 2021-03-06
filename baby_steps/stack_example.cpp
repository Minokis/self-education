// Создадим стек из целых чисел

#include <iostream>

// Элемент стека
struct Node {
	int d;
	Node *next;
};


Node * first(int d);            // Создание первого элемента
void push(Node **top, int d);   // Добавление в стек
int pop(Node **top);         // Выборка из стека


int main()
{   
	// top всегда указывает на начало стека
	Node *top = first(1);
	for (int i = 2; i < 7; i++) push(&top, i);
	while (top) {
		std::cout << pop(&top) << std::endl;
	}
	return 0;
}

Node * first(int d) {
	Node *pv = new Node;
	pv->d = d;
	pv->next = 0;
	return pv;
} 

void push(Node **top, int d) {
	Node *pv = new Node;
	pv->d = d;
	pv->next = *top;
	*top = pv;
}

int pop(Node **top) {
	int temp = (*top)->d;
	Node *pv = *top;
	*top = (*top)->next;
	delete pv;
	return temp;
}

