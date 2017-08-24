#include <iostream>
#ifndef POINT_H
#define POINT_H

class Point {
  public:
    Point(double _x = 0, double _y = 0):
      x(_x),
      y(_y)
    { std::cout << "Constructor of Point is working\n"; }

    void Show() const;

  private:
    double x, y;
};

#endif // POINT_H
