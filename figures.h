#ifndef FIGURES_H
#define FIGURES_H

#include <iostream>

using namespace std;

class Figure
{
protected:
  string name_;
  double perimeter_;
  double area_;

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
  Rect(int width, int height);
  string Name() override;
  double Perimeter() override;
  double Area() override;
};

class Circle : public Figure
{
public:
  Circle(int r);
  string Name() override;
  double Perimeter() override;
  double Area() override;
};
#endif  // FIGURES_H
