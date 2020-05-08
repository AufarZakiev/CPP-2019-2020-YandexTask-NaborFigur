#include "geometry.h"
#include "math.h"

Triangle::Triangle(int a, int b, int c)
{
  _name = "TRIANGLE";
  _perimeter = a + b + c;
  auto pp = _perimeter / 2;
  _area = sqrt((pp - a) * (pp - b) * (pp - c) * pp);
}

string Triangle::Name()
{
  return _name;
}

double Triangle::Perimeter()
{
  return _perimeter;
}

double Triangle::Area()
{
  return _area;
}

Rect::Rect(int a, int b)
{
  _name = "RECT";
  _perimeter = (a + b) * 2;
  _area = a * b;
}

string Rect::Name()
{
  return _name;
}

double Rect::Perimeter()
{
  return _perimeter;
}

double Rect::Area()
{
  return _area;
}

Circle::Circle(int a)
{
  _name = "CIRCLE";
  _perimeter = 2 * 3.14 * a;
  _area = 3.14 * a * a;
}

string Circle::Name()
{
  return _name;
}

double Circle::Perimeter()
{
  return _perimeter;
}

double Circle::Area()
{
  return _area;
}
