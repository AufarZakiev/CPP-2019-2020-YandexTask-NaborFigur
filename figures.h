#ifndef FIGURES_H
#define FIGURES_H

#include <iostream>

using namespace std;

class Figure
{
protected:
  string _name;
  double _perimetr;
  double _area;

public:
  virtual string Name() = 0;
  virtual string Perimeter() = 0;
  virtual string Area() = 0;

  virtual ~Figure() = default;
};

class Triangle : public Figure
{
public:
  Triangle(int a, int b, int c);

  string Name() override;
  string Perimeter() override;
  string Area() override;
};

class Rect : public Figure
{
public:
  Rect(int a, int b);
  string Name() override;
  string Perimeter() override;
  string Area() override;
};

class Circle : public Figure
{
public:
  Circle(int a);
  string Name() override;
  string Perimeter() override;
  string Area() override;
};

#endif  // FIGURES_H
