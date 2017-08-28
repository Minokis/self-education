#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <cstring>
#include <math.h>
#include "Triangle.h"
using namespace std;

// Конструктор
Triangle::Triangle(Point _v1, Point _v2, Point _v3, const char* ident):
  v1(_v1),
  v2(_v2),
  v3(_v3) {
    char buf[16]; // здесь мы создадим имя
    objID = new char[strlen(ident) + 1]; // strlen не включает \0
    strcpy(objID, ident);

    count++;
    sprintf(buf, "Triangle %d", count); // переписывание в buf - создание имени
    name = new char[strlen(buf) + 1];
    strcpy(name, buf);
    v1v2 = sqrt((v1.x - v2.x) * (v1.x - v2.x) + (v1.y - v2.y) * (v1.y - v2.y));
    v2v3 = sqrt((v2.x - v3.x) * (v2.x - v3.x) + (v2.y - v3.y) * (v2.y - v3.y));
    v1v3 = sqrt((v1.x - v3.x) * (v1.x - v3.x) + (v1.y - v3.y) * (v1.y - v3.y));
    cout << "Constructor_1 for " << objID << " (" << name << ") "<< endl;
  }

  // Конструктор пустого треугольника
  Triangle::Triangle(const char* ident) {
    char buf[16];
    objID = new char[strlen(ident) + 1];
    strcpy(objID, ident);

    count++;
    sprintf(buf, "Triangle %d", count); // переписывание в buf - создание имени
    name = new char[strlen(buf) + 1];
    strcpy(name, buf);
    v1v2 = v2v3 = v1v3 = 0;
    cout << "Constructor_2 for " << objID << " (" << name << ") "<< endl;

  }

  //Деструктор
  Triangle::~Triangle() {
    cout << "Destructor for: " << objID << endl;
    delete[] objID;
    delete[] name;
  }

  // Показать объект
  void Triangle::Show() const {
    cout << name << ": ";
    v1.Show();
    v2.Show();
    v3.Show();
    cout << endl;
  }

