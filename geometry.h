#ifndef GEOMETRY_H
#define GEOMETRY_H

#include <iostream>

using namespace std;

class Figure
{
protected:
  string _name;
  double _perimeter;
  double _area;

public:
  virtual string Name() = 0;
  virtual double Perimeter() = 0;
  virtual double Area() = 0;
};

class Triangle : public Figure
{
public:
  Triangle(int a, int b, int c);

  string Name() override;
  double Perimeter() override;
  double Area() override;
};

class Rect : public Figure
{
public:
  Rect(int a, int b);
  string Name() override;
  double Perimeter() override;
  double Area() override;
};

class Circle : public Figure
{
public:
  Circle(int a);
  string Name() override;
  double Perimeter() override;
  double Area() override;
};

#endif  // GEOMETRY_H
