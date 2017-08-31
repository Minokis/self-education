#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Point.h"

class Triangle {
  public:
    Triangle(Point, Point, Point, const char*);
    Triangle(const char*); // конструктор пустого треугольника
    ~Triangle();
    Point Get_v1() const { return v1; }
    Point Get_v2() const { return v2; }
    Point Get_v3() const { return v3; }
    char* GetName() const { return name; }
    void Show() const;
    void Move(Point);
  public:
    static int count;
  private:
    char* objID;
    char* name;  // имя создается при создании треугольника, в конструкторе, с помощью счетчика
    Point v1, v2, v3;
    double v1v2; // соединяет v1 и v2
    double v2v3; // соединяет v2 и v3
    double v1v3; // соединяет v1 и v3
};

#endif // TRIANGLE_H
