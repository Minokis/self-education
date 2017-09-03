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
	strcpy_s(objID, strlen(ident) + 1, ident);

    count++;
    //sprintf(buf, "Triangle %d", count); // переписывание в buf - создание имени
	sprintf_s(buf, 16, "Triangle %d", count);
    name = new char[strlen(buf) + 1];
    strcpy_s(name, strlen(buf) + 1, buf);

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

  // Конструктор копирования
  Triangle::Triangle(const Triangle& tria) :
    v1(tria.v1),
    v2(tria.v2),
    v3(tria.v3) {
      cout << "Copy constructor for: " << tria.objID << endl;

      objID = new char[strlen(tria.objID) + strlen("(copy)") + 1];
      strcpy(objID, tria.objID);
      strcat(objID, "(copy)");

      name = new char[strlen(tria.name) + 1];
      strcpy(name, tria.name);
      v1v2 = tria.v1v2;
      v2v3 = tria.v2v3;
      v1v3 = tria.v1v3;
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

  // Переместить объект на величину dp.x, dp.y
    void Triangle::Move(Point dp) {
      v1 += dp;
      v2 += dp;
      v3 += dp;
    }

  // Сравнить площади
    bool Triangle::operator >(const Triangle& tria) const {
      double p = (v1v2+v2v3+v1v3) / 2;
      double s = sqrt(p* (p-v1v2)*(p-v2v3)*(p-v1v3));
      double p1 = (tria.v1v2+tria.v2v3+tria.v1v3) / 2;
      double s1 = sqrt(p1* (p1-tria.v1v2)*(p1-tria.v2v3)*(p1-tria.v1v3));
      if(s > s1)
        return true;
      else
        return false;
    }

    // Присвоить значение объекта tria
    Triangle& Triangle::operator =(const Triangle& tria) {
      cout << "Assign operator: " << objID << " = " << tria.objID << endl;
      if (&tria == this) return *this;
      delete [] name;
      name = new char[strlen(tria.name) + 1];
      strcpy(name, tria.name);
      v1v2 = tria.v1v2;
      v2v3 = tria.v2v3;
      v1v3 = tria.v1v3;
      return *this;
  }
