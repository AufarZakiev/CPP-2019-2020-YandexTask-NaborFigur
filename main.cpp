#include <iostream>
#include <sstream>
#include <iomanip>
#include <memory>
#include <vector>
#include <cmath>

#include <geometry.h>

using namespace std;

shared_ptr<Figure> CreateFigure(istringstream& is)
{
  shared_ptr<Figure> figure;
  string name;
  is >> name;
  if (name == "TRIANGLE")
  {
    double a, b, c;
    is >> a >> b >> c;
    figure = make_shared<Triangle>(a, b, c);
  }
  else if (name == "RECT")
  {
    double width, height;
    is >> width >> height;
    figure = make_shared<Rect>(width, height);
  }
  else if (name == "Michail" || name == "CIRCLE")
  {
    double radius;
    is >> radius;
    figure = make_shared<Circle>(radius);
  }
  return figure;
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
