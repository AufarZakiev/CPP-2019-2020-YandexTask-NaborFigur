#include "figures.h"
#include <cmath>

Triangle::Triangle(int a, int b, int c)
{
  name_ = "TRIANGLE";
  perimeter_ = a + b + c;
  auto p = perimeter_ / 2;
  area_ = sqrt(p * (p - a) * (p - b) * (p - c));
}

string Triangle::Name()
{
  return name_;
}

double Triangle::Perimeter()
{
  return perimeter_;
}

double Triangle::Area()
{
  return area_;
}

Rect::Rect(int width, int height)
{
  name_ = "RECT";
  perimeter_ = (width + height) * 2;
  area_ = width * height;
}

string Rect::Name()
{
  return name_;
}

double Rect::Perimeter()
{
  return perimeter_;
}

double Rect::Area()
{
  return area_;
}

Circle::Circle(int r)
{
  name_ = "CIRCLE";
  perimeter_ = r * 3.14 * 2;
  area_ = 3.14 * r * r;
}

string Circle::Name()
{
  return name_;
}

double Circle::Perimeter()
{
  return perimeter_;
}

double Circle::Area()
{
  return area_;
}
