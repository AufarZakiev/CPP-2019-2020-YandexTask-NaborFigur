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
  virtual double Perimeter() = 0;
  virtual double Area() = 0;

  virtual ~Figure() = default;
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

#endif  // FIGURES_H
