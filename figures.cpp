#include "figures.h"
#include "math.h"

Triangle::Triangle(int a, int b, int c)
{
  _name = "TRIANGLE";
  _perimetr = a + b + c;
  auto p = _perimetr / 2;
  _area = sqrt(p * (p - a) * (p - b) * (p - c));
}

string Triangle::Name()
{
  return _name;
}

string Triangle::Perimeter()
{
  return to_string(_perimetr);
}

string Triangle::Area()
{
  return to_string(_area);
}

Rect::Rect(int a, int b)
{
  _name = "RECT";
  _perimetr = (a + b) * 2;
  _area = a * b;
}

string Rect::Name()
{
  return _name;
}

string Rect::Perimeter()
{
  return to_string(_perimetr);
}

string Rect::Area()
{
  return to_string(_area);
}

Circle::Circle(int a)
{
  _name = "CIRCLE";
  _perimetr = 6.28 * a;
  _area = 3.14 * a * a;
}

string Circle::Name()
{
  return _name;
}

string Circle::Perimeter()
{
  return to_string(_perimetr);
}

string Circle::Area()
{
  return to_string(_area);
}
