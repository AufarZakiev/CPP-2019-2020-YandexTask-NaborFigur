#include <iostream>
#include <vector>
#include <memory>
#include <cmath>
#include <iomanip>
#include <figures.h>

using namespace std;

shared_ptr<Figure> CreateFigure(istringstream& is)
{
  shared_ptr<Figure> figure;
  string type;
  is >> type;
  if (type == "TRIANGLE")
  {
    int a, b, c;
    is >> a >> b >> c;
    figure = make_shared<Triangle>(a, b, c);
  }
  else if (type == "RECT")
  {
    int width, height;
    is >> width >> height;
    figure = make_shared<Rect>(width, height);
  }
  else if (type == "CIRCLE")
  {
    int r;
    is >> r;
    figure = make_shared<Circle>(r);
  }
  else
    throw "Wrong type of figure is written!";
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
