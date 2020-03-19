#include <iostream>
#include <sstream>
#include <iomanip>
#include <memory>
#include <vector>
#define _USE_MATH_DEFINES
#include <cmath>

using namespace std;

class Figure
{
public:
  virtual string Name() = 0;
  virtual double Perimeter() = 0;
  virtual double Area() = 0;
};

class Triangle : public Figure
{
  double a;
  double b;
  double c;

public:
  Triangle(double a, double b, double c) : a(a), b(b), c(c){};

  string Name() override
  {
    return "TRIANGLE";
  }

  double Perimeter() override
  {
    return a + b + c;
  }

  double Area() override
  {
    double p = Perimeter();
    return sqrt(p * (p - a) * (p - b) * (p - c));
  }
};

class Rect : public Figure
{
  double width;
  double height;

public:
  Rect(double width, double height) : width(width), height(height){};

  string Name() override
  {
    return "RECT";
  }

  double Perimeter() override
  {
    return (width + height) * 2;
  }

  double Area() override
  {
    return width * height;
  }
};

class Circle : public Figure
{
  double radius;

public:
  Circle(double radius) : radius(radius){};

  string Name() override
  {
    return "CIRCLE";
  }

  double Perimeter() override
  {
    return 2 * M_PI * radius;
  }

  double Area() override
  {
    return M_PI * radius * radius;
  }
};

shared_ptr<Figure> CreateFigure(istringstream& is)
{
  string type;
  is >> type;
  if (type == "TRIANGLE")
  {
    double a;
    double b;
    double c;
    is >> a;
    is >> b;
    is >> c;
    shared_ptr<Triangle> triangle;
    triangle = make_shared<Triangle>(a, b, c);
    return triangle;
  }
  else if (type == "RECT")
  {
    double width;
    double height;
    is >> width;
    is >> height;
    shared_ptr<Rect> rect;
    rect = make_shared<Rect>(width, height);
    return rect;
  }
  else if (type == "CIRCLE")
  {
    double radius;
    is >> radius;
    Circle c(radius);
    shared_ptr<Circle> circle;
    circle = make_shared<Circle>(radius);
    return circle;
  }
  return shared_ptr<Figure>();
};

int main()
{
  vector<shared_ptr<Figure>> figures;
  for (string line; getline(cin, line);)
  {
    istringstream is(line);

    string command;
    is >> command;
    if (command == "ADD")
    {
      figures.push_back(CreateFigure(is));
    }
    else if (command == "PRINT")
    {
      for (const auto& current_figure : figures)
      {
        cout << fixed << setprecision(3) << current_figure->Name() << " " << current_figure->Perimeter() << " "
             << current_figure->Area() << endl;
      }
    }
  }
  return 0;
}
