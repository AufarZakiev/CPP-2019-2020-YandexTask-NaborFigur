#include <iostream>
#include <vector>
#include <memory>
#include <cmath>
#include <sstream>
#include <iomanip>
using namespace std;

class Figure
{
public:
  virtual string Name() = 0;
  virtual float Perimeter() = 0;
  virtual float Area() = 0;
};

class Triangle : public Figure
{
  float side_a_, side_b_, side_c_;

public:
  Triangle(float a, float b, float c)
  {
    side_a_ = a;
    side_b_ = b;
    side_c_ = c;
  }

  virtual string Name()
  {
    return "TRIANGLE";
  }

  virtual float Perimeter()
  {
    return side_a_ + side_b_ + side_c_;
  }
  virtual float Area()
  {
    float tmp = (side_c_ * side_c_ - side_a_ * side_a_ - side_b_ * side_b_) / ((-2) * side_a_ * side_b_);  // cos(a,b)
    tmp = sqrt(1 - tmp * tmp);                                                                             // sin(a,b)
    tmp = 0.5 * side_a_ * side_b_ * tmp;                                                                   // area
    return tmp;
  }
};
class Rect : public Figure
{
  float side_a_, side_b_;

public:
  Rect(float a, float b)
  {
    side_a_ = a;
    side_b_ = b;
  }

  virtual string Name()
  {
    return "RECT";
  }

  virtual float Perimeter()
  {
    return (side_a_ + side_b_) * 2;
  }
  virtual float Area()
  {
    return side_a_ * side_b_;
  }
};

class Circle : public Figure
{
  float radius;

public:
  Circle(float r)
  {
    radius = r;
  }

  virtual string Name()
  {
    return "CIRCLE";
  }
  virtual float Perimeter()
  {
    return 2 * radius * M_PI;
  }
  virtual float Area()
  {
    return M_PI * radius * radius;
  }
};

shared_ptr<Figure> CreateFigure(istringstream& is)
{
  shared_ptr<Figure> figure;
  string command;
  is >> command;

  if (command == "RECT")
  {
    int side_a, side_b;
    is >> side_a >> side_b;
    figure = make_shared<Rect>(side_a, side_b);
  }
  else if (command == "TRIANGLE")
  {
    int side_a, side_b, side_c;
    is >> side_a >> side_b >> side_c;
    figure = make_shared<Triangle>(side_a, side_b, side_c);
  }
  else if (command == "CIRCLE")
  {
    int radius;
    is >> radius;
    figure = make_shared<Circle>(radius);
  }

  return figure;
}
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
